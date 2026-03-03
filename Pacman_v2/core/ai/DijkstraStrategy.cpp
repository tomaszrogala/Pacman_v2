#include "DijkstraStrategy.h"
#include "../../entities/Ghost.h"
#include "../../state/GameState.h"
#include <chrono>
#include <iostream>

Direction DijkstraStrategy::decide(Ghost& a_ghost, const GameState& a_state) //TODO: Make ghost const, in random as well?
{
    const Map& map = a_state.m_Map;
    const int mapWidth = map.width();
    const int mapHeight = map.height();
    if (mapWidth <= 0 || mapHeight <= 0)
        return Direction::None;

    const Position2D startPosition = a_ghost.m_Position;
    const Position2D targetPosition = a_state.m_Pacman.m_Position;

    auto isInsideMap = [&](Position2D position) {
        return position.m_X >= 0 && position.m_Y >= 0 && position.m_X < mapWidth &&
               position.m_Y < mapHeight;
    };

    auto isWallTile = [&](Position2D position)
    { return map.m_Tiles[position.m_Y][position.m_X] == Tile::Wall; };

    auto toIndex = [&](Position2D position) { return position.m_Y * mapWidth + position.m_X; };

    if (!isInsideMap(startPosition) || !isInsideMap(targetPosition) || isWallTile(startPosition) ||
        isWallTile(targetPosition))
    {
        return Direction::None;
    }

    const int infinityDistance = std::numeric_limits<int>::max();
    std::vector<int> distanceTo(mapWidth * mapHeight, infinityDistance);
    std::vector<Position2D> previousCell(mapWidth * mapHeight, {-1, -1});

    struct QueueNode
    {
        int distance;
        Position2D position;
    };

    struct CompareBySmallestDistance
    {
        bool operator()(const QueueNode& left, const QueueNode& right) const
        {
            return left.distance > right.distance;
        }
    };

    std::priority_queue<QueueNode, std::vector<QueueNode>, CompareBySmallestDistance> openSet;

    distanceTo[toIndex(startPosition)] = 0;
    openSet.push({0, startPosition});

    auto tryRelaxEdge = [&](Position2D fromPosition, Position2D toPosition)
    {
        if (!isInsideMap(toPosition) || isWallTile(toPosition))
            return;

        const int newDistance = distanceTo[toIndex(fromPosition)] + 1;
        if (newDistance < distanceTo[toIndex(toPosition)])
        {
            distanceTo[toIndex(toPosition)] = newDistance;
            previousCell[toIndex(toPosition)] = fromPosition;
            openSet.push({newDistance, toPosition});
        }
    };

    while (!openSet.empty())
    {
        const QueueNode currentNode = openSet.top();
        openSet.pop();

        // ignore outdated queue nodes (can happen because we push multiple nodes for the same position)
        if (currentNode.distance != distanceTo[toIndex(currentNode.position)])
            continue;

        if (currentNode.position == targetPosition)
            break;

        const Position2D currentPos = currentNode.position;
        tryRelaxEdge(currentPos, Position2D{ currentPos.m_X, currentPos.m_Y - 1}); // Up
        tryRelaxEdge(currentPos, Position2D{ currentPos.m_X, currentPos.m_Y + 1}); // Down
        tryRelaxEdge(currentPos, Position2D{ currentPos.m_X - 1, currentPos.m_Y}); // Left
        tryRelaxEdge(currentPos, Position2D{ currentPos.m_X + 1, currentPos.m_Y}); // Right
    }

    if (distanceTo[toIndex(targetPosition)] == infinityDistance)
        return Direction::None;

    // Go backwards from target to start to find the first step
    Position2D stepPosition = targetPosition;
    Position2D previousPosition = previousCell[toIndex(stepPosition)];
    if (previousPosition.m_X == -1)
        return Direction::None;
    while (!(previousPosition == startPosition))
    {
        stepPosition = previousPosition;
        previousPosition = previousCell[toIndex(stepPosition)];
        if (previousPosition.m_X == -1)
            return Direction::None;
    }

    // stepPosition is an adjacent to startPosition -> return direction
    if (stepPosition.m_X == startPosition.m_X && stepPosition.m_Y == startPosition.m_Y - 1)
        return Direction::Up;
    if (stepPosition.m_X == startPosition.m_X && stepPosition.m_Y == startPosition.m_Y + 1)
        return Direction::Down;
    if (stepPosition.m_X == startPosition.m_X - 1 && stepPosition.m_Y == startPosition.m_Y)
        return Direction::Left;
    if (stepPosition.m_X == startPosition.m_X + 1 && stepPosition.m_Y == startPosition.m_Y)
        return Direction::Right;

    return Direction::None;
}
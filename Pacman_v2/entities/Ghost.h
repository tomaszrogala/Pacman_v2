#pragma once
#include "../utils/Direction.h"
#include "../utils/Position2D.h"

enum class AiType
{
	RANDOM, 
	DIJKSTRA,
};

struct Ghost
{
    Direction m_Direction; 
    Position2D m_Position;

    AiType m_AiType;

	//TODO:
	/*int m_decision_periods_per_tick;  
	int m_decision_countdown;*/  

};
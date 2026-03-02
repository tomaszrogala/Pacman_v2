#pragma once
#include "../utils/Direction.h"
#include "../utils/Position2D.h"

enum class AiType
{
	RANDOM, 
	//DIJKSTRA,
};

struct Ghost
{
    Direction m_direction; 
	Position2D m_position;

	AiType m_ai_type;

	//TODO:
	/*int m_decision_periods_per_tick;  
	int m_decision_countdown;*/  

};
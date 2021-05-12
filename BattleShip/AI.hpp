#pragma once

#include "Map.hpp"

class Computer {
private:
	enum class Direction {
		up, down, right, left
	};
	Direction dir;
	int i, j;
	int prev_i, prev_j, sunk;
	bool isHit, PrevSunk;

	Map map;
public:
	Computer();
	bool Strike(Map& UserMap);
	void DetectCoords(Map& UserMap);
	void ChangeDirection();
};
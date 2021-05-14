#pragma once

#include "Map.hpp"



class Computer {
private:

	Direction dir;
	int i, j;
	int prev_i, prev_j, sunk;
	bool isHit, PrevSunk, PrevHit, Finish, ChangeDir;
public:
	Computer();
	bool Strike(Map& UserMap, bool& isSunk);
	void DetectCoords(Map& UserMap);
	void ChangeDirection();
	bool getFinish(Map& UserMap);
};
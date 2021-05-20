#pragma once

#include "Map.hpp"



class Computer {
private:
	Direction dir;
	int i, j;
	int prev_i, prev_j, sunk;
	bool isHit, PrevHit;
	bool ChangeDir;
	bool FinishBoat;
	bool PrevSunk;
public:
	Computer();
	bool Strike(Map& UserMap, bool& isSunk);
	void DetectCoords(Map& UserMap);
	void ChangeFireDirection();
	void OppositeFireDirection(Map& UserMap);
};
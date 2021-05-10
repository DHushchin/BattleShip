#pragma once
#include "Cell.hpp"

class Boat {
private:
	int size;
	string Direction;
	int row, col;
public:
	Boat();
	Boat(int size);
	void setDirection(int num);
	string getDirection();
	void setCoords();
	int getRow();
	int getCol();
	int getSize();
	bool isSunk(vector<vector<Cell*>>& cells);
};

#pragma once
#include "Cell.hpp"

class Boat {
private:
	string Direction;
	int row, col, size;
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
	bool operator==(const Boat& other);
};

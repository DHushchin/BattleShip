#pragma once

#include "Cell.hpp"


using namespace std;

class Boat {
private:
	int size;
	string Direction;
	int row, col;
public:
	Boat();
	Boat(int size);
	//Boat(const Boat& other);
	void setDirection(int num);
	string getDirection();
	void setCoords();
	int getRow();
	int getCol();
	int getSize();
};

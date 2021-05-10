#pragma once

#include <SFML/Graphics.hpp>
#include "Boat.hpp"


Boat::Boat() {
	size = col = row = -1;
}

Boat::Boat(int size) {
	this->size = size;
    col = row = -1;
}

void Boat::setDirection(int num) {
	if (num == 0) 
		Direction = "Horizontal";
	else 
        Direction = "Vertical";
}

string Boat::getDirection() {
	return Direction;
}

void Boat::setCoords() {

    switch (size) 
    {
    case 1:
        if (Direction == "Horizontal")
        {
            col = rand() % 10;
            row = rand() % 10;
        }
        else
        {
            col = rand() % 10;
            row = rand() % 10;
        }
        break;
    case 2:
        if (Direction == "Horizontal")
        {
            col = rand() % 9;
            row = rand() % 10;
        }
        else
        {
            col = rand() % 10;
            row = rand() % 9;
        }
        break;
    case 3:
        if (Direction == "Horizontal")
        {
            col = rand() % 8;
            row = rand() % 10;
        }
        else
        {
            col = rand() % 10;
            row = rand() % 8;
        }
        break;
    case 4:
        if (Direction == "Horizontal")
        {
            col = rand() % 7;
            row = rand() % 10;
        }
        else
        {
            col = rand() % 10;
            row = rand() % 7;
        }
    }
}

int Boat::getRow() {
    return row;
}

int Boat::getCol() {
    return col;
}

int Boat::getSize() {
    return size;
}

bool Boat::isSunk(vector<vector<Cell*>>& cells) {
    if (Direction == "Horizontal") {
        for (int j = col; j < col + size; j++)
            if (!cells[row][j]->getHit())
                return false;
    }
    else 
    {
        for (int i = row; i < row + size; i++)
            if (!cells[i][col]->getHit())
                return false;
    }
    return true;
}

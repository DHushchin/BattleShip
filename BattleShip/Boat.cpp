#pragma once
#include <SFML/Graphics.hpp>
#include "Boat.hpp"

using namespace std;

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

    switch (size) //Generate random column and row based on boat size so we don't go over the edge of the grid
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

/*
Boat::Boat(const Boat& other) {
    this->col = other.col;
    this->row = other.row;
    this->Direction = other.Direction;
    this->size = other.size;
}
*/
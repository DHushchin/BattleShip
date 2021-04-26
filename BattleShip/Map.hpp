#pragma once
#include "Boat.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std; 

enum BoatSize { Submarine = 1, Destroyer = 2, Battleship = 3, Carrier = 4 };

void initGrid(int map[][10]);
void printMap(int map[][10]);
void printGameMap(int grid[][10], string player);
int resetColAndRow(int col, int& row, int BoatSize, char d);
char getDirection(int d);
int checkSpaces(int map[][10], int c, int r, int s, char d);
void editMap(int map[][10], int col, int row, int BoatSize, char dir);
bool setBoat(int map[][10], int BoatSize, int name, vector<Boat>& boatList);
void editBoatInfo(int map[][10], int c, int r, int BoatSize, char d, vector<Boat>& boatList, int name);
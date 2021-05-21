#pragma once

#include <algorithm>
#include "Map.hpp"

using namespace std;

enum class Tactics {
	diagonals, improved_locator, chesses, random 
};

enum class Direction {
	up, down, right, left
};

class Computer {
private:
	Direction dir;
	Tactics CurrStrategy;
	int i, j, prev_i, prev_j;
	int sunk;
	bool isHit, PrevHit;
	bool ChangeDir;
	bool FinishBoat;
	bool PrevSunk;
	vector <pair<int, int>> diagonals;
	vector <pair<int, int>> improved_locator;

public:
	Computer();
	bool Strike(Map& UserMap, bool& isSunk);
	void DetectCoords(Map& UserMap);
	void ChangeFireDirection();
	void OppositeFireDirection(Map& UserMap);
	void ChooseStrategy(Map& UserMap);
	void ChangeStrategy(Map& UserMap);
	void UpdateTacticList(Map& UserMap);
	void UpdateTacticList(Map& UserMap, vector<pair<int, int>>& BorderList);
	bool ContainsCell(vector<pair<int, int>>& TacticList, pair<int, int>& coords);
	bool isLocatorCell();
	bool isLocatorCell(int& row, int& col);
	bool EndChess(Map& UserMap);
	friend class Map;
};
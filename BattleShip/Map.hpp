#pragma once

#include "Cell.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

class Map {
private:
	vector<vector<Cell*>> cells;
public:
	Map(int i_start, int j_start);
	Cell* getCell(int i, int j);
};
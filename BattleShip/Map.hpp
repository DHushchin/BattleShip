#pragma once

#include "Cell.hpp"
#include "Boat.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;


class Map {
private:
	vector<vector<Cell*>> cells;
	vector <Boat> BoatList;
public:
	Map(int i_start, int j_start);
	Cell* getCell(int i, int j);
	void setBoatList();
	void setBoats();
	bool FreeSpace(Boat& boat);
	void setClick(const sf::RenderWindow& window);
};
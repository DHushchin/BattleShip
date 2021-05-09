#pragma once

#include "Cell.hpp"
#include "Boat.hpp"
#include <SFML/Graphics.hpp>
#include <vector>


class Map {
private:
	vector<vector<Cell*>> cells;
	vector <Boat> BoatList;
	int Hits;
	bool Over;
public:
	Map();
	Map(int i_start, int j_start);
	Cell* getCell(int i, int j);
	void setBoatList();
	void setBoats();
	bool FreeSpace(Boat& boat);
	void setClick(const sf::RenderWindow& window);
	void setBorder(Boat& boat);
	bool isOver();
	int getHits();
};
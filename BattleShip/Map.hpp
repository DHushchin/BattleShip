#pragma once

#include "Cell.hpp"
#include "Boat.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

enum class Direction {
	up, down, right, left
};

class Map {
private:
	vector<vector<Cell*>> cells;
	vector <Boat> BoatList, SunkList;
	int Hits;
	bool Over;
public:
	Map();
	Map(int i_start, int j_start);
	Cell* getCell(int i, int j);
	void setBoatList();
	void setBoats();
	bool FreeSpace(Boat& boat);
	bool setClick(sf::RenderWindow& window, sf::Event& GameEvent, sf::RenderWindow& MenuWindow, bool& isSunk);
	void setBorder(Boat& boat);
	bool isOver();
	int getHits();
	int getSunk();
	bool Strike(int i, int j, bool& isSunk);
	bool Contains(Boat& boat);
};
#pragma once

#include "Cell.hpp"
#include "Boat.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>


class Map {
private:
	vector<vector<Cell*>> cells;
	vector <Boat> BoatList, SunkList;
	vector<pair<int, int>> BorderCoords;
	int Hits;
	bool Over, ShowBoats, Border;
private:
	void setBoatList();
	void setBoats();
	bool FreeSpace(Boat& boat);
	void setBorderCoords(Boat& boat);
	void setBorder(Boat& boat);
	bool Contains(Boat& boat);
public:
	Map();
	Map(int i_start, int j_start, bool ShowBoats);
	Cell* getCell(int i, int j);
	bool setClick(sf::RenderWindow& window, sf::Event& GameEvent, sf::RenderWindow& MenuWindow, bool& isSunk);
	vector<pair<int, int>> getBorderCoords();
	bool isOver();
	int getSunkNumber();
	bool Strike(int i, int j, bool& isSunk);
};
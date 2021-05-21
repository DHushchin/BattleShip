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
public:
	Map();
	Map(int i_start, int j_start, bool ShowBoats);
	Cell* getCell(int i, int j);
	void setBoatList();
	void setBoats();
	bool FreeSpace(Boat& boat);
	bool setClick(sf::RenderWindow& window, sf::Event& GameEvent, sf::RenderWindow& MenuWindow, bool& isSunk);
	void setBorderCoords(Boat& boat);
	vector<pair<int, int>> getBorderCoords();
	void setBorder(Boat& boat);
	bool isOver();
	int getHits();
	int getSunkNumber();
	bool Strike(int i, int j, bool& isSunk);
	bool Contains(Boat& boat);
};
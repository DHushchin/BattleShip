#include "Map.hpp"

Map::Map() {

}

Map::Map(int i_start, int j_start) {
	cells.clear();
	for (int i = 0, i_shift = i_start; i < 10; i++, i_shift += 49) {
		vector <Cell*> Row;
		for (int j = 0, j_shift = j_start; j < 10; j++, j_shift += 49) {
			Row.push_back(new Cell(j_shift, i_shift));
			Row[j]->SetUpSprite("images\\Cell.png");
		}
		cells.push_back(Row);
	}
	setBoats();
}


Cell* Map::getCell(int i, int j) {
	return cells[i][j];
}


void Map::setBoatList() {
	Boat Carrier(4); BoatList.push_back(Carrier);
	Boat Battleship1(3); BoatList.push_back(Battleship1);
	Boat Battleship2(3); BoatList.push_back(Battleship2);
	Boat Destoyer1(2); BoatList.push_back(Destoyer1);
	Boat Destoyer2(2); BoatList.push_back(Destoyer2);
	Boat Destoyer3(2); BoatList.push_back(Destoyer3);
	Boat Submarine1(1); BoatList.push_back(Submarine1);
	Boat Submarine2(1); BoatList.push_back(Submarine2);
	Boat Submarine3(1); BoatList.push_back(Submarine3);
	Boat Submarine4(1); BoatList.push_back(Submarine4);
}


void Map::setBoats() {
	setBoatList();
	for (int count = 0; count < BoatList.size(); count++) {
		BoatList[count].setDirection(rand() % 2);
		string direction = BoatList[count].getDirection();
		BoatList[count].setCoords();

		while (FreeSpace(BoatList[count]) == false) {
			BoatList[count].setDirection(rand() % 2);
			string direction = BoatList[count].getDirection();
			BoatList[count].setCoords();
		}

		if (BoatList[count].getDirection() == "Horizontal")
			for (int col = BoatList[count].getCol(); col < BoatList[count].getCol() + BoatList[count].getSize(); col++)
				cells[BoatList[count].getRow()][col]->setBoat();

		else
			for (int row = BoatList[count].getRow(); row < BoatList[count].getRow() + BoatList[count].getSize(); row++)
				cells[row][BoatList[count].getCol()]->setBoat();
	}
}


bool Map::FreeSpace(Boat& boat) {
	if (boat.getDirection() == "Horizontal")
	{

		for (int i = boat.getRow() - 1; i < boat.getRow() + 2; i++)
			for (int j = boat.getCol() - 1; j < boat.getCol() + boat.getSize() + 1; j++)
				if (i < 0 || i >= 10 || j < 0 || j >= 10)
					continue;
				else if (cells[i][j]->getBoat() || cells[i][j]->getBlocked() || cells[i][j]->getBorder())
					return false;
	}
	else
	{
		for (int i = boat.getRow() - 1; i < boat.getRow() + boat.getSize() + 1; i++)
			for (int j = boat.getCol() - 1; j < boat.getCol() + 2; j++)
				if (i < 0 || i >= 10 || j < 0 || j >= 10)
					continue;
				else if (cells[i][j]->getBoat() || cells[i][j]->getBlocked() || cells[i][j]->getBorder())
					return false;
	}
	return true;
}


void Map::setClick(sf::RenderWindow& window) {

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (!cells[i][j]->getBlocked()) {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && cells[i][j]->getSprite().getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
					if (cells[i][j]->getBoat()) 
						cells[i][j]->setHit();
					else
						cells[i][j]->setMiss();
				}


			}
		}
	}

	for (auto boat : BoatList) {
		if (boat.isSunk(cells)) {
			setBorder(boat);
		}
	}

}


void Map::setBorder(Boat boat) {

	if (boat.getDirection() == "Horizontal")
	{

		for (int i = boat.getRow() - 1; i < boat.getRow() + 2; i++)
			for (int j = boat.getCol() - 1; j < boat.getCol() + boat.getSize() + 1; j++)
				if (i < 0 || i >= 10 || j < 0 || j >= 10)
					continue;
				else
					cells[i][j]->setBorder();
					
	}
	else
	{
		for (int i = boat.getRow() - 1; i < boat.getRow() + boat.getSize() + 1; i++)
			for (int j = boat.getCol() - 1; j < boat.getCol() + 2; j++)
				if (i < 0 || i >= 10 || j < 0 || j >= 10)
					continue;
				else 
					cells[i][j]->setBorder();
					
	}

}

#include "Map.hpp"

Map::Map(int i_start, int j_start) {
	cells.clear();
	for (int i = 0, i_shift = i_start; i < 10; i++, i_shift += 49) {
		vector <Cell*> Row;
		for (int j = 0, j_shift = j_start; j < 10; j++, j_shift += 49) {
			Row.push_back(new Cell("images\\cell.png", j_shift, i_shift));
		}
		cells.push_back(Row);
	}
}

Cell* Map::getCell(int i, int j) {
	return cells[i][j];
}
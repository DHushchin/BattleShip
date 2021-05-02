#include "Cell.hpp"

using namespace std;

Cell::Cell(string TextureName, float x, float y) {
	if (!SetUpSprite(TextureName))
		return;
	pos = sf::Vector2f(x, y);
	sprite.setPosition(pos);
}


bool Cell::SetUpSprite(string TextureName) {
	if (!texture.loadFromFile(TextureName))
		return false;
	sprite.setTexture(texture);
	return true;
}



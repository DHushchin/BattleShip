#include "Cell.hpp"


Cell::Cell(float x, float y) {
	isHit = isMiss = isBorder = isBoat = false;
	pos = sf::Vector2f(x, y);
	sprite.setPosition(pos);
}


bool Cell::SetUpSprite(string TextureName) {
	if (!texture.loadFromFile(TextureName))
		return false;
	sprite.setTexture(texture);
	return true;
}


sf::Sprite Cell::getSprite() {
	return sprite;
}


void Cell::setHit() {
	SetUpSprite("images\\Hit.png");
	isHit = true;
}


void Cell::setMiss() {
	SetUpSprite("images\\Miss.jpg");
	isMiss = true;
}


void Cell::setBorder() {
	if (!isBoat) {
		SetUpSprite("images\\Miss.jpg");
		isBorder = true;
	}
}


void Cell::setBoat() {
	SetUpSprite("images\\Ship1.png");
	isBoat = true;
}


bool Cell::getBorder() {
	return isBorder;
}


bool Cell::getHit() {
	return isHit;
}


bool Cell::getBlocked() {
	return (isHit || isMiss || isBorder);
}


bool Cell::getBoat() {
	return isBoat;
}


bool Cell::getMiss() {
	return isMiss;
}


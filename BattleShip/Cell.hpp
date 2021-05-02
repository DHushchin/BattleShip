#pragma once

#include <SFML/Graphics.hpp>
#include <string>

using namespace std;

class Cell {
private:
	sf::Vector2f pos;
	sf::Texture texture;	
public:
	Cell(string TextureName, float x, float y);
	bool SetUpSprite(string TextureName);
	sf::Sprite sprite;
};

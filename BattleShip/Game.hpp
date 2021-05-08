#pragma once

#include "Boat.hpp"
#include "Map.hpp"


class Game {
public:
	enum class State {
		User, Computer, Over
	};

private:
	State state;
	sf::RenderWindow GameWindow;
	sf::Texture MapBackTexture, UserFieldTexture, CompFieldTexture;
	sf::Sprite MapBackSprite, UserFieldSprite, CompFieldSprite;
	Map UserMap;
	Map CompMap;
public:
	Game();
	void Turn();
	
};

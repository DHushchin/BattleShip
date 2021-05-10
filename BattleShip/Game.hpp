#pragma once

#include "Boat.hpp"
#include "Map.hpp"
#include "Menu.hpp"
enum class State {
	User, Computer
};

class Game {
public:


public:
	State state;
	sf::RenderWindow GameWindow;
	sf::Texture MapBackTexture, UserFieldTexture, CompFieldTexture;
	sf::Sprite MapBackSprite, UserFieldSprite, CompFieldSprite;
	sf::Event GameEvent{};
	Map UserMap, CompMap;
	bool GameOver;
public:
	Game();
	Game(sf::RenderWindow& MenuWindow);
	void Turn();
	void Play(Map& active, sf::RenderWindow& window, sf::RenderWindow& MenuWindow);
};




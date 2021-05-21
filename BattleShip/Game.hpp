#pragma once

#include "Boat.hpp"
#include "Map.hpp"
#include "Menu.hpp"
#include "AI.hpp"

enum class State {
	User, Computer
};

class Game {
private:
	State state;
	sf::RenderWindow GameWindow;
	sf::Texture MapBackTexture, UserFieldTexture, CompFieldTexture;
	sf::Sprite MapBackSprite, UserFieldSprite, CompFieldSprite;
	sf::Event GameEvent{};
	Map UserMap, CompMap;
	bool GameOver;
	sf::Music music;
public:
	Game();
	Game(sf::RenderWindow& MenuWindow);
	void Turn();
	bool Player(Map& CompMap, sf::RenderWindow& window, sf::RenderWindow& MenuWindow, bool& isSunk);
};
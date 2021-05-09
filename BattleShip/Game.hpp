#pragma once

#include "Boat.hpp"
#include "Map.hpp"


class Game {
public:
	enum class State {
		User, Computer
	};

private:
	State state;
	sf::Texture MapBackTexture, UserFieldTexture, CompFieldTexture;
	sf::Sprite MapBackSprite, UserFieldSprite, CompFieldSprite;
	Map UserMap, CompMap;
	bool GameOver;
public:
	Game();
	void Turn();
	void Play(Map& active, sf::RenderWindow& window);
	void Result(State& state);
};

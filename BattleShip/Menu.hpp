#pragma once
#include "Game.hpp"

class Menu {
private:
	sf::RenderWindow MenuWindow;
	sf::Texture menuTexture, buttonTexture;
	sf::Sprite menuSprite, buttonSprite;
	sf::Event MenuEvent{};
public:
	Menu();
};
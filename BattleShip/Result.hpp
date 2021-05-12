#pragma once

#include "Game.hpp"

using namespace sf;

class Result {
private:
	RenderWindow ResWindow;
	Texture ResTexture;
	Sprite ResSprite;
	Event ResEvent{};

public:
	Result();
	Result(State& state);
};

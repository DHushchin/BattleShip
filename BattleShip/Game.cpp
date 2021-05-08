#include "Game.hpp"

using namespace sf;


Game::Game() {
    state = State::User;
    RenderWindow GameWindow(VideoMode(1176, 539), "Game");

    MapBackTexture.loadFromFile("images\\MapBackground.png");
    UserFieldTexture.loadFromFile("images\\Field.jpg");
    CompFieldTexture.loadFromFile("images\\Field.jpg");

    MapBackSprite.setTexture(MapBackTexture);
    UserFieldSprite.setTexture(UserFieldTexture);
    CompFieldSprite.setTexture(UserFieldTexture);

    MapBackSprite.setPosition(0, 0);
    UserFieldSprite.setPosition(0, 0);
    CompFieldSprite.setPosition(637, 0);

    srand(time(NULL));
    Map UserMap(49, 49);
    Map CompMap(49, 686);

    while (GameWindow.isOpen()) {
        Event GameEvent;
        while (GameWindow.pollEvent(GameEvent))
            if (GameEvent.type == Event::Closed)
                GameWindow.close();

        GameWindow.draw(MapBackSprite);
        GameWindow.draw(UserFieldSprite);
        GameWindow.draw(CompFieldSprite);

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                GameWindow.draw(CompMap.getCell(i, j)->getSprite());
                GameWindow.draw(UserMap.getCell(i, j)->getSprite());
            }
        }

        GameWindow.display();

        CompMap.setClick(GameWindow);
        UserMap.setClick(GameWindow);

    }
}


void Game::Turn() {
	if (state == State::User)
		state = State::Computer;
	else
		state = State::User;
}



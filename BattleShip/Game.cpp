#include "Game.hpp"
#include "Result.hpp"

using namespace sf;

Game::Game() {

}


Game::Game(RenderWindow& MenuWindow) {

    state = State::User;
    GameOver = false;

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

    srand((unsigned int)time(NULL));
    Map UserMap(49, 49);
    Map CompMap(49, 686);

    while (GameWindow.isOpen() && !GameOver) {

        while (GameWindow.pollEvent(GameEvent)) {
            if (GameEvent.type == Event::Closed) {
                GameWindow.close();
                MenuWindow.close();
            }
        }

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

        if (state == State::User) {
            Play(CompMap, GameWindow, MenuWindow);
        }
        else {
            Play(UserMap, GameWindow, MenuWindow);
        }
    }

}


void Game::Turn() {
    if (state == State::User)
        state = State::Computer;
    else
        state = State::User;
}


void Game::Play(Map& CurrPlayer, RenderWindow& MapWindow, RenderWindow& MenuWindow) {
        
    bool isHit = CurrPlayer.setClick(MapWindow, GameEvent, MenuWindow);
    
    GameOver = CurrPlayer.isOver();

    if (GameOver) {
        Result res(state);
    }
    else if (!isHit)
        Turn();
}
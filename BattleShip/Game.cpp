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

    GameOver = false;

    while (GameWindow.isOpen()) {
        Event GameEvent;
        while (GameWindow.pollEvent(GameEvent)) {
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

            if (state == State::User) {
                Play(CompMap, GameWindow);
            }
            else {
                Play(UserMap, GameWindow);
            }
        }
    }
}


void Game::Turn() {
    if (state == State::User)
        state = State::Computer;
    else
        state = State::User;
}


void Game::Play(Map& current, RenderWindow& window) {
    
    //int Hits = current.getHits();
    current.setClick(window);   
    /*
    if (Hits < current.getHits()) {
        int Hits = current.getHits();
        Play(current, window);
    }*/
    
    GameOver = current.isOver();

    if (GameOver) {
        Result(state);
        window.close();
    }
    else 
    {
        Turn();
    }
}


void Game::Result(State& state) {

        RenderWindow WinWindow(VideoMode(260, 375), "Menu");

        Texture WinTexture;
        WinTexture.loadFromFile("images\\Winner.jpg");

        Sprite WinSprite(WinTexture);

        WinSprite.setPosition(0, 0);

        while (WinWindow.isOpen())
        {
            Event event;
            while (WinWindow.pollEvent(event)) {
                if (event.type == Event::Closed) {
                    WinWindow.close();
                }
            }

            WinWindow.draw(WinSprite);
            WinWindow.display();
        }
}
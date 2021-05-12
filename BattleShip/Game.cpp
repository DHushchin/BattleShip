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
    Computer Comp;

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
            Player(CompMap, GameWindow, MenuWindow);
        }
        else {
            //Player(UserMap, GameWindow, MenuWindow);
            sleep(sf::milliseconds(1000));
            if (!Comp.Strike(UserMap))
                Turn();
            GameOver = UserMap.isOver();
            if (GameOver)
                Result res(state);
        }
    }

}


void Game::Turn() {
    if (state == State::User)
        state = State::Computer;
    else
        state = State::User;
}


void Game::Player(Map& CompMap, RenderWindow& MapWindow, RenderWindow& MenuWindow) {
        
    bool isHit = CompMap.setClick(MapWindow, GameEvent, MenuWindow);

    GameOver = CompMap.isOver();

    if (GameOver) 
        Result res(state);
    
    if (!isHit)
        Turn();
}

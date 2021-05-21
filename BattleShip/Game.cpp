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
    Map UserMap(49, 49, true);
    Map CompMap(49, 686, false);
    Computer Comp;
    int iter = 0;
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

        if (iter == 0)
            iter++;
        else
            music.play();

        GameOver = UserMap.isOver() || CompMap.isOver();
        if (GameOver) {
            if (state == State::User)
                music.openFromFile("sounds\\Ta_Da.wav");
            else
                music.openFromFile("sounds\\sea_gulls.wav");
            Result res(state);
        }

        bool isSunk = false;
        if (state == State::User) {
            if (Player(CompMap, GameWindow, MenuWindow, isSunk)) {
                if (!isSunk)
                    music.openFromFile("sounds\\short_pen.wav");
                else
                    music.openFromFile("sounds\\bomb.wav");
            }
            else 
                music.openFromFile("sounds\\water_drop.wav");            
        }
        else {
            sleep(sf::milliseconds(1000));
            if (Comp.Strike(UserMap, isSunk)) {
                if (!isSunk)
                    music.openFromFile("sounds\\short_pen.wav");
                else {
                    music.openFromFile("sounds\\bomb.wav");
                    vector<pair<int, int>> coords = UserMap.getBorderCoords();
                    Comp.UpdateTacticList(UserMap, coords);
                }
            }
            else {
               music.openFromFile("sounds\\water_drop.wav");
                Turn();
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


bool Game::Player(Map& CompMap, RenderWindow& MapWindow, RenderWindow& MenuWindow, bool& isSunk) {
        
    bool isHit = CompMap.setClick(MapWindow, GameEvent, MenuWindow, isSunk);
   
    if (!isHit) 
        Turn();
    
    return isHit;
}

#include "Map.hpp"

using namespace std;

void Menu();
void Game();

int main()
{
    Menu();
    return 0;
}


void Menu() {
    sf::RenderWindow MenuWindow(sf::VideoMode(1000, 500), "Menu");

    sf::Texture menuTexture, buttonTexture;

    menuTexture.loadFromFile("images\\MenuBackground.jpeg");
    buttonTexture.loadFromFile("images\\play.png");

    sf::Sprite menuSprite(menuTexture), buttonSprite(buttonTexture);

    menuSprite.setPosition(0, 0);
    buttonSprite.setPosition(470, 300);


    while (MenuWindow.isOpen())
    {
        sf::Event event;
        while (MenuWindow.pollEvent(event))
            if (event.type == sf::Event::Closed)
                MenuWindow.close();


        MenuWindow.clear();
        MenuWindow.draw(menuSprite);
        MenuWindow.draw(buttonSprite);
        MenuWindow.display();

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && buttonSprite.getGlobalBounds().contains(MenuWindow.mapPixelToCoords(sf::Mouse::getPosition(MenuWindow))))
            Game();
    }
}


void Game() {
    sf::RenderWindow GameWindow(sf::VideoMode(1176, 539), "Game");

    sf::Texture MapBackTexture, UserFieldTexture, CompFieldTexture;

    MapBackTexture.loadFromFile("images\\MapBackground.png");
    UserFieldTexture.loadFromFile("images\\Field.jpg");
    CompFieldTexture.loadFromFile("images\\Field.jpg");

    sf::Sprite MapBackSprite(MapBackTexture), UserFieldSprite(UserFieldTexture), CompFieldSprite(CompFieldTexture);

    MapBackSprite.setPosition(0, 0);
    UserFieldSprite.setPosition(0, 0);
    CompFieldSprite.setPosition(637, 0);

    srand(time(NULL));
    Map UserMap(49, 49);
    Map CompMap(49, 686);


    while (GameWindow.isOpen()) {
        sf::Event GameEvent;
        while (GameWindow.pollEvent(GameEvent))
            if (GameEvent.type == sf::Event::Closed)
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

        UserMap.setClick(GameWindow);
        CompMap.setClick(GameWindow);
    }
}



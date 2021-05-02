#include "Map.hpp"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 500), "Menu run!");
    
    sf::Texture menuTexture, buttonTexture, MapBackTexture, UserFieldTexture, CompFieldTexture;

    menuTexture.loadFromFile("images\\MenuBackground.jpeg");
    buttonTexture.loadFromFile("images\\play.png");
    MapBackTexture.loadFromFile("images\\MapBackground.png");
    UserFieldTexture.loadFromFile("images\\Field.jpg");
    CompFieldTexture.loadFromFile("images\\Field.jpg");

    sf::Sprite menuSprite(menuTexture), buttonSprite(buttonTexture), MapBackSprite(MapBackTexture), UserFieldSprite(UserFieldTexture), CompFieldSprite(CompFieldTexture);

    menuSprite.setPosition(0, 0);
    buttonSprite.setPosition(470, 300);
    MapBackSprite.setPosition(0, 0);
    UserFieldSprite.setPosition(0, 0);
    CompFieldSprite.setPosition(637, 0);


    Map UserMap(49, 49);
    Map CompMap(637, 49);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();
        window.draw(menuSprite);
        window.draw(buttonSprite);
        window.display();

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && buttonSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
        {
            sf::RenderWindow window2(sf::VideoMode(1176, 539), "Game run!");

            while (window2.isOpen()) {

                while (window2.pollEvent(event))
                {

                    if (event.type == sf::Event::Closed)
                        window2.close();
                }

                window2.draw(MapBackSprite);
                window2.draw(UserFieldSprite);
                window2.draw(CompFieldSprite);
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        window2.draw(UserMap.getCell(i, j)->sprite);
                    }
                }
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        window2.draw(CompMap.getCell(i, j)->sprite);
                    }
                }

                window2.display();
            }

        }
    }

    return 0;
}



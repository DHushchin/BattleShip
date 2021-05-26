#include "Menu.hpp"

using namespace sf;

Menu::Menu() {

    RenderWindow MenuWindow(VideoMode(1000, 500), "Menu");

    menuTexture.loadFromFile("images\\MenuBackground.jpeg");
    buttonTexture.loadFromFile("images\\play.png");

    menuSprite.setTexture(menuTexture);
    buttonSprite.setTexture(buttonTexture);

    menuSprite.setPosition(0, 0);
    buttonSprite.setPosition(470, 300);

    MenuWindow.clear();
    MenuWindow.draw(menuSprite);
    MenuWindow.draw(buttonSprite);
    MenuWindow.display();

    while (MenuWindow.isOpen())
    {     
        while (MenuWindow.pollEvent(MenuEvent)) {
            if (MenuEvent.type == Event::Closed) {
                MenuWindow.close();
            }
        }
        if (Mouse::isButtonPressed(Mouse::Left) && buttonSprite.getGlobalBounds().contains(MenuWindow.mapPixelToCoords(Mouse::getPosition(MenuWindow)))) {
            sf::Music Start;
            Start.openFromFile("sounds\\Start.wav");
            Start.play();
            Game game(MenuWindow);
        }       
    }
}


#include "Result.hpp"

using namespace sf;

Result::Result() {

}

Result::Result(State& state) {

    RenderWindow ResWindow(VideoMode(1280, 720), "Result");

    if (state == State::User) {
        ResTexture.loadFromFile("images\\Winner.jpg");
    }
    else {
        ResTexture.loadFromFile("images\\Loser.jpg");
    }
    
    ResSprite.setTexture(ResTexture);
    ResSprite.setPosition(0, 0);

    while (ResWindow.isOpen())
    {
        while (ResWindow.pollEvent(ResEvent)) {
            if (ResEvent.type == Event::Closed) {
                ResWindow.close();
            }
        }
        ResWindow.clear();
        ResWindow.draw(ResSprite);
        ResWindow.display();
    }
}
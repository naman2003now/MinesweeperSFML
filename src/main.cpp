#include <iostream>
#include <SFML/Graphics.hpp>
#include "Button.h"
/*
Navy Blue   :   5, 68, 94
Grotto?     :   24, 154, 180
Blue fuck green have a baby
            :   117, 230, 218
baby blue   :   212, 241, 244 
*/

const sf::Vector2f RESOLUTION = sf::Vector2f(800, 800);
const sf::Color BACKGROUND_COLOR = sf::Color(5, 68, 94);
const sf::Color BUTTON_COLOR = sf::Color(24, 154, 180);

int main(){
    sf::RenderWindow window(sf::VideoMode(RESOLUTION.x, RESOLUTION.y), "HelloWorld");
    sf::Event event;

    Button box(sf::Vector2f(250, 250), 200.0f);
    box.shape.setPosition(sf::Vector2f(400, 400));
    box.shape.setFillColor(BUTTON_COLOR);

    //eventLoop
    while(window.isOpen()){
        //events
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed) window.close();
        }
        //Clearing the old shit
        window.clear(BACKGROUND_COLOR);

        //Rendering
        window.draw(box.shape);

        //Update The shit that your eyes can see
        window.display();
    }

    return 0;
}
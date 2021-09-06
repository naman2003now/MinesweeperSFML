#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Button.h"
#include "Game.h"
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
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;  

    sf::RenderWindow window(sf::VideoMode(RESOLUTION.x, RESOLUTION.y), "HelloWorld", sf::Style::Close, settings);
    sf::Event event;
    
    Button box(sf::Vector2f((RESOLUTION.x/10)-20, (RESOLUTION.y/10)-20), 10.0f);
    box.shape.setPosition(sf::Vector2f(400, 400));
    box.shape.setFillColor(BUTTON_COLOR);

    sf::Text text;
    sf::Font font;
    if(!font.loadFromFile("/home/naman/Documents/MineSweeper/build/font.ttf")){
        std::cout << "shit" << std::endl;
    };
    text.setFont(font);
    text.setString(std::to_string(1));
    text.setCharacterSize(90);
    text.setFillColor(sf::Color(212, 241, 244));
    text.setOrigin(28, 62);
    text.setPosition(400, 400);

    Game game(10, 10);

    

    //eventLoop
    while(window.isOpen()){
        //events
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed) window.close();
        }
        //Clearing the old shit
        window.clear(BACKGROUND_COLOR);
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                if(game.board[i][j] == EMPTY){
                    text.setFillColor(sf::Color(212, 241, 244));
                    if(game.numbers[i][j]){
                        text.setString(std::to_string(game.numbers[i][j]));
                    }
                    else{
                        text.setString(" ");
                    }
                }
                else{
                    text.setFillColor(sf::Color(212, 41, 44));
                    text.setString("F");
                }
                box.shape.setPosition(i*RESOLUTION.x/10 + 40, j*RESOLUTION.y/10 + 40);
                text.setPosition(i*RESOLUTION.x/10 + 40, j*RESOLUTION.y/10 + 40);
                window.draw(box.shape);
                window.draw(text);
            }
        }
        //Update The shit that your eyes can see
        window.display();
    }

    return 0;
}
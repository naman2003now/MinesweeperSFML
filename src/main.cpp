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
const int GAME_SIZE = 20;

int main(){
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;  

    sf::RenderWindow window(sf::VideoMode(RESOLUTION.x, RESOLUTION.y), "HelloWorld", sf::Style::Close, settings);
    sf::Event event;
    
    Button box(sf::Vector2f((RESOLUTION.x/GAME_SIZE) - 20, (RESOLUTION.y/GAME_SIZE) - 20), 10.0f);
    box.shape.setPosition(sf::Vector2f(400, 400));
    box.shape.setFillColor(BUTTON_COLOR);

    sf::Text text;
    sf::Font font;
    if(!font.loadFromFile("/home/naman/Documents/MineSweeper/build/font.ttf")){
        std::cout << "shit" << std::endl;
    };
    text.setFont(font);
    text.setString(std::to_string(1));
    text.setCharacterSize(40);
    text.setFillColor(sf::Color(212, 241, 244));
    text.setOrigin(12, 27);
    text.setPosition(400, 400);

    Game game(GAME_SIZE, 9);

    

    //eventLoop
    while(window.isOpen()){
        //events
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed) window.close();
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                int mouse_x = sf::Mouse::getPosition(window).x;
                int mouse_y = sf::Mouse::getPosition(window).y;
                game.Click((int)(mouse_x*20/RESOLUTION.x), (int)(mouse_y*20/RESOLUTION.y));
            }else if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
                int mouse_x = sf::Mouse::getPosition(window).x;
                int mouse_y = sf::Mouse::getPosition(window).y;
                game.Flagged((int)(mouse_x*20/RESOLUTION.x), (int)(mouse_y*20/RESOLUTION.y));
            }
        }
        //Clearing the old shit
        window.clear(BACKGROUND_COLOR);

        //Rendering
        for(int i = 0; i < GAME_SIZE; i++){
            for(int j = 0; j < GAME_SIZE; j++){
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
                box.shape.setPosition(i*RESOLUTION.x/GAME_SIZE + 20, j*RESOLUTION.y/GAME_SIZE + 20);
                text.setPosition(i*RESOLUTION.x/GAME_SIZE + 20, j*RESOLUTION.y/GAME_SIZE + 20);
                window.draw(box.shape);
                window.draw(text);
            }
        }
        
        //Update The shit that your eyes can see
        window.display();
    }

    return 0;
}
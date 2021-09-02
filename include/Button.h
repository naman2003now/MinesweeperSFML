#include <iostream>
#include <SFML/Graphics.hpp>

class Button{
public:
    sf::ConvexShape shape;
    Button(sf::Vector2f size, float radius);
    Button(float width, float height, float radius);
    ~Button();
};
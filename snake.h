#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>

class Snake{

public:

    Snake(sf::RenderWindow& window);
    void move();
    void grow();
    void handleInput(sf::Keyboard::Key key);
    void render(sf::RenderWindow& window);
    void reset();
    sf::RectangleShape& getBody();
    const std::vector<sf::RectangleShape>& getTail() const;

private:

    sf::RectangleShape body;
    std::vector<sf::RectangleShape> tail;
    sf::Vector2f direction;
    sf::RenderWindow& window;
};

#endif
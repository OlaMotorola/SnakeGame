#ifndef FOOD_H
#define FOOD_H

#include <SFML/Graphics.hpp>

class Food{

public:

    Food();
    void render(sf::RenderWindow& window);
    void respawn();
    sf::Vector2f getPosition() const;
    sf::Sprite& getSprite();

private:

    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f position;
};

#endif
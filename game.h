#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "snake.h"
#include "food.h"

class Game{

public:
    Game();
    void run();

private:

    const int screenWidth = 800;
    const int screenHeight = 600;
    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    Snake snake;
    Food food;
    int score;
    sf::Font font;
    sf::Text scoreText;

    void processEvents();
    void update();
    void render();
    void checkCollision();
    void reset();
};

#endif
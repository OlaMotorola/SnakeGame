#include <iostream>
#include "game.h"

using namespace std;


Game::Game(): window(sf::VideoMode(600, 600), "Snake Game"), snake(window){

    window.setFramerateLimit(10);

    if (!backgroundTexture.loadFromFile("../background.jpg")){
        std::cout << "Background error" << std::endl;}


    if (!font.loadFromFile("../arial.ttf")){
        std::cout << "Font error" << std::endl;}

    score = 0;
    scoreText.setFont(font);
    scoreText.setCharacterSize(30);
    scoreText.setPosition(10, 10);
    scoreText.setFillColor(sf::Color::White);
}


void Game::run(){

    while (window.isOpen()){

        processEvents();
        update();
        render();
    }
}


void Game::processEvents(){

    sf::Event event;
    while (window.pollEvent(event)){

        if (event.type == sf::Event::Closed){
            window.close();}

        else if (event.type == sf::Event::KeyPressed){
            snake.handleInput(event.key.code);}
    }
}


void Game::update(){

    snake.move();
    checkCollision();

    if (snake.getBody().getGlobalBounds().intersects(food.getSprite().getGlobalBounds())){

        snake.grow();
        food.respawn();
        score += 10;
        scoreText.setString("Score: " + std::to_string(score));
    }
}


void Game::render(){

    window.clear();
    sf::Sprite backgroundSprite(backgroundTexture);
    window.draw(backgroundSprite);
    snake.render(window);
    food.render(window);
    window.draw(scoreText);

    window.display();
}


void Game::checkCollision(){

    sf::Vector2f snakePosition = snake.getBody().getPosition();

    /*
    if (snakePosition.x < 0 || snakePosition.x >= screenWidth || snakePosition.y < 0 || snakePosition.y >= screenHeight){
        reset();}
    */

    for (const auto& segment : snake.getTail()){

        if (segment.getPosition() == snakePosition){

            reset();
            break;
        }
    }
}

void Game::reset(){

    snake.reset();
    food.respawn();
    score = 0;
    scoreText.setString("Score: " + std::to_string(score));
}

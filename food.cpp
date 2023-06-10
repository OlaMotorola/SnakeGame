#include "food.h"
#include <cstdlib>
#include <ctime>
#include <iostream>


Food::Food(){

    if (!texture.loadFromFile("/users/olamotorola/Desktop/SnakeGame/apple.png")){
        std::cout << "Apple image error" << std::endl;}

    sprite.setTexture(texture);
    sprite.setScale(0.05f, 0.05f);
    respawn();
}


void Food::respawn(){

    srand(static_cast<unsigned int>(time(0)));
    int x = rand() % 30;
    int y = rand() % 30;
    position = sf::Vector2f(x * 20.0f, y * 20.0f);
    sprite.setPosition(position);
}


void Food::render(sf::RenderWindow& window){
    window.draw(sprite);}


sf::Sprite& Food::getSprite() {
    return sprite;}


sf::Vector2f Food::getPosition() const{
    return position;}



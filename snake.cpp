#include "snake.h"

Snake::Snake(sf::RenderWindow& window)
    : window(window) {

    body.setSize(sf::Vector2f(20.0f, 20.0f));
    body.setFillColor(sf::Color::White);
    body.setPosition(0.0f, 0.0f);

    direction = sf::Vector2f(1.0f, 0.0f);
}

void Snake::move(){

    sf::Vector2f position = body.getPosition();
    body.setPosition(position.x + direction.x * 20.0f, position.y + direction.y * 20.0f);

    sf::Vector2u windowSize = window.getSize();

    if (body.getPosition().x < 0)
        body.setPosition(windowSize.x - body.getSize().x, body.getPosition().y);

    else if (body.getPosition().x >= windowSize.x)
        body.setPosition(0, body.getPosition().y);

    if (body.getPosition().y < 0)
        body.setPosition(body.getPosition().x, windowSize.y - body.getSize().y);

    else if (body.getPosition().y >= windowSize.y)
        body.setPosition(body.getPosition().x, 0);

    if (!tail.empty()){

        tail.back().setPosition(tail[tail.size() - 2].getPosition());

        for (int i = tail.size() - 2; i > 0; --i){
            tail[i].setPosition(tail[i - 1].getPosition());}

        tail.front().setPosition(position);
    }
}

void Snake::grow(){

    sf::RectangleShape newSegment(sf::Vector2f(20.0f, 20.0f));
    newSegment.setFillColor(sf::Color::Green);
    tail.push_back(newSegment);
}


void Snake::handleInput(sf::Keyboard::Key key){

    switch (key){

        case sf::Keyboard::Up:
            direction = sf::Vector2f(0.0f, -1.0f);
            break;

        case sf::Keyboard::Down:
            direction = sf::Vector2f(0.0f, 1.0f);
            break;

        case sf::Keyboard::Left:
            direction = sf::Vector2f(-1.0f, 0.0f);
            break;

        case sf::Keyboard::Right:
            direction = sf::Vector2f(1.0f, 0.0f);
            break;
    }
}

void Snake::reset(){

    body.setPosition(0.0f, 0.0f);
    tail.clear();
    direction = sf::Vector2f(1.0f, 0.0f);
}

void Snake::render(sf::RenderWindow& window){

    window.draw(body);

    for (const auto& segment : tail){
        window.draw(segment);
    }
}


sf::RectangleShape& Snake::getBody(){
    return body;}

const std::vector<sf::RectangleShape>& Snake::getTail() const{
    return tail;}

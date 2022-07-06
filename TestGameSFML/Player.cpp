#include "Player.h"

Player::Player() {
    sf::CircleShape* shape = new sf::CircleShape(50.f);
    shape->setFillColor(sf::Color::Magenta);
    setShape(shape);
}
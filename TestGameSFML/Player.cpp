#include "Player.h"

Player::Player() {
    sf::CircleShape* shape = new sf::CircleShape(50.f);
    shape->setFillColor(sf::Color::Magenta);

    sf::FloatRect boundaries = shape->getGlobalBounds();
    shape->setOrigin(boundaries.width / 2, boundaries.height / 2);
    setShape(shape);
}
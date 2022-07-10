#include "Zombie.h"

Zombie::Zombie() {
    sf::RectangleShape* shape = new sf::RectangleShape(sf::Vector2f(50.f, 50.f));
    shape->setFillColor(sf::Color::Red);

    sf::FloatRect boundaries = shape->getGlobalBounds();
    shape->setOrigin(boundaries.width / 2, boundaries.height / 2);
    setShape(shape);

    health = 100;
    defaultSpeed = 50.f;
}

void Zombie::tick(TickData & tickData) {
    movementVector = tickData.playerPos - position;
    movementVector = vectorNormalized(movementVector);
    movementVector *= tickData.deltaTime * defaultSpeed;

    move(movementVector);
    setRotation(movementVector);
}


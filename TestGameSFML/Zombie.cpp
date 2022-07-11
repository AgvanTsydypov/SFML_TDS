#include "Zombie.h"

Zombie::Zombie() {
    sf::RectangleShape* shape = new sf::RectangleShape(sf::Vector2f(50.f, 50.f));
    shape->setFillColor(sf::Color::Red);

    sf::FloatRect boundaries = shape->getGlobalBounds();
    shape->setOrigin(boundaries.width / 2, boundaries.height / 2);
    setShape(shape);

    health = maxHealth;
}

void Zombie::tick(TickData & tickData) {
    float currentSpeed = defaultSpeed * tickData.deltaTime;
    float currentMass = mass / tickData.deltaTime / 10;
    sf::Vector2f steeringVector = sb::seek(position, tickData.playerPos, movementVector, currentSpeed, currentMass);
    movementVector = sb::applySteering(movementVector, steeringVector, currentSpeed);

    move(movementVector);
    setRotation(movementVector);
}


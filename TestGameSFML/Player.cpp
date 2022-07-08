#include "Player.h"
#include "Bullet.h"

Player::Player() {
    sf::RectangleShape* shape = new sf::RectangleShape(sf::Vector2f(50.f, 50.f));
    shape->setFillColor(sf::Color::Magenta);

    sf::FloatRect boundaries = shape->getGlobalBounds();
    shape->setOrigin(boundaries.width / 2, boundaries.height / 2);
    setShape(shape);
}

void Player::tick(TickData & tickData) {
    int hDir = tickData.rightPressed - tickData.leftPressed;
    int vDir = tickData.downPressed - tickData.upPressed;
    
    if (hDir || vDir) {
        sf::Vector2f dir(static_cast<float>(hDir), static_cast<float>(vDir));
        
        dir = vectorNormalized(dir);
        sf::Vector2f speedVector = dir * tickData.deltaTime * movementSpeed;

        sf::Vector2f dimensions = getDimensions();

        if (position.x - dimensions.x / 2.f + speedVector.x < 0) {
            speedVector.x = 0;
            setPosition(dimensions.x / 2.f, position.y);
        }
        if (position.x + speedVector.x > tickData.windowSize.x - dimensions.x / 2.f) {
            speedVector.x = 0;
            setPosition(tickData.windowSize.x - dimensions.x / 2.f, position.y);
        }

        if (position.y - dimensions.y / 2.f + speedVector.y < 0) {
            speedVector.y = 0;
            setPosition(position.x, dimensions.y / 2.f);
        }
        if (position.y + speedVector.y > tickData.windowSize.y - dimensions.y / 2.f) {
            speedVector.y = 0;
            setPosition(position.x, tickData.windowSize.y - dimensions.y / 2.f);
        }

        move(speedVector);
    }

    sf::Vector2f directVector = sf::Vector2f(tickData.mousePos.x - position.x, tickData.mousePos.y - position.y);
    sf::Vector2f mouseDirectionNormal = vectorNormalized(directVector);

    setRotation(mouseDirectionNormal);

    if (tickData.lmbPressed && shotTimer.getElapsedTime().asSeconds() > shotDelay) {
        Bullet* bullet = new Bullet();
        bullet->setPosition(position);
        bullet->setMovementDirection(mouseDirectionNormal);
        tickData.gameObjects->push_back(bullet);

        shotTimer.restart();
    }
}
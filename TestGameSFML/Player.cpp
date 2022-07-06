#include "Player.h"
#include "Bullet.h"

Player::Player() {
    sf::CircleShape* shape = new sf::CircleShape(50.f);
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
        float length = std::sqrtf(std::pow(dir.x, 2) + std::pow(dir.y, 2));
        dir = dir / length;
        sf::Vector2f speedVector = dir * tickData.deltaTime * movementSpeed;

        if (position.x - getDimensions().x / 2.f + speedVector.x < 0) {
            speedVector.x = 0;
            setPosition(getDimensions().x / 2.f, position.y);
        }
        if (position.x + speedVector.x > tickData.windowSize.x - getDimensions().x / 2.f) {
            speedVector.x = 0;
            setPosition(tickData.windowSize.x - getDimensions().x / 2.f, position.y);
        }

        if (position.y - getDimensions().y / 2.f + speedVector.y < 0) {
            speedVector.y = 0;
            setPosition(position.x, getDimensions().y / 2.f);
        }
        if (position.y + speedVector.y > tickData.windowSize.y - getDimensions().y / 2.f) {
            speedVector.y = 0;
            setPosition(position.x, tickData.windowSize.y - getDimensions().y / 2.f);
        }

        move(speedVector);
    }

    sf::Vector2f directVector = sf::Vector2f(tickData.mousePos.x - position.x, tickData.mousePos.y - position.y);
    sf::Vector2f mouseDirectionNormal = sf::Vector2f(directVector / (float)std::sqrt(std::pow(directVector.x, 2) + std::pow(directVector.y, 2)));

    bool shotDone = sf::Mouse::isButtonPressed(sf::Mouse::Left);

    if (shotDone) {
        tickData.lmbPressed = true;
        Bullet* bullet = new Bullet();
        bullet->setPosition(position);
        bullet->bulletSetSpeed(mouseDirectionNormal);
        tickData.gameObjects->push_back(bullet);
    }
}
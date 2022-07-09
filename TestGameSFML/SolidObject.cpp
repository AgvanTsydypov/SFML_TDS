#include "SolidObject.h"
#include "Bullet.h"

SolidObject::SolidObject() {
    sf::Vector2f recSize = sf::Vector2f(120.f, 420.f);
    sf::RectangleShape* shape = new sf::RectangleShape(recSize);
    shape->setFillColor(sf::Color::Green);
    setShape(shape);

    shape->setOrigin(0, 0);
}

int SolidObject::checkCollision(GameObject* obj) {
    sf::Vector2f dimensions = getDimensions();
    sf::Vector2f objPosition = obj->getPosition();

    if (shape->getGlobalBounds().intersects(obj->getGlobalBounds())) {
        sf::Vector2f cornerVecTL(-dimensions.x / 2.f, dimensions.y / 2.f);
        sf::Vector2f VecL(-dimensions.x / 2.f, 0);
        sf::Vector2f dir(position + dimensions / 2.f - objPosition);

        float thisCos = std::acosf(cosF(cornerVecTL, VecL)) * 180 / PI;
        float objCos = std::acosf(cosF(dir, VecL)) * 180 / PI;
        // left side
        if (objCos > 180 - thisCos)
            return LEFT;
        // right side
        if (objCos < thisCos)
            return RIGHT;
        // top side
        if (objCos > thisCos && objCos < 180 - thisCos && !std::signbit(dir.y))
            return TOP;
        // bottom side
        if (objCos > thisCos && objCos < 180 - thisCos && std::signbit(dir.y))
            return BOTTOM;
    }
    return 0; 
}

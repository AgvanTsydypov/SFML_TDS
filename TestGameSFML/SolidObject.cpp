#include "SolidObject.h"
#include "Bullet.h"

SolidObject::SolidObject() {
    sf::Vector2f recSize = sf::Vector2f(120.f, 420.f);
    sf::RectangleShape* shape = new sf::RectangleShape(recSize);
    shape->setFillColor(sf::Color::Green);
    setShape(shape);

    shape->setOrigin(0, 0);

    setPosition(500, 200);
}

void SolidObject::tick(TickData& tickData) {
    for (size_t i = 0; i < tickData.gameObjects->size(); i++) {
        if (toDestroy)
            break;
        GameObject *obj = (*tickData.gameObjects)[i];
        
        // Bullet
        if (dynamic_cast<Bullet*>(obj) != nullptr) {
            if (checkCollision(obj)) {
                obj->toDestroy = true;

                health--;
                if (health <= 0)
                    toDestroy = true;
            }
        }

        // Player
        if (dynamic_cast<Player*>(obj) != nullptr){
            int col = checkCollision(obj);

            sf::Vector2f dimensions = getDimensions();
            sf::Vector2f objDimensions = obj->getDimensions();
            sf::Vector2f objPosition = obj->getPosition();

            if (col == LEFT) {
                obj->setPosition(position.x - objDimensions.x / 2.f, objPosition.y);
            }
            else if (col == RIGHT) {
                obj->setPosition(position.x + dimensions.x + objDimensions.x / 2.f, objPosition.y);
            }
            else if (col == TOP) {
                obj->setPosition(objPosition.x, position.y - objDimensions.y / 2.f);
            }
            else if (col == BOTTOM) {
                obj->setPosition(objPosition.x, position.y + dimensions.y + objDimensions.y / 2.f);
            }
        }
    }
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

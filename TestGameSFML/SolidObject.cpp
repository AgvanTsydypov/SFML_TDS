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
    for (int i = 0; i < tickData.gameObjects->size(); i++) {
        GameObject *obj = (*tickData.gameObjects)[i];
        if (dynamic_cast<Bullet*>(obj) != nullptr) {
            if (checkCollision(obj))
                obj->toDestroy = true;
        }
        if (dynamic_cast<Player*>(obj) != nullptr){
            int col = checkCollision(obj);
            if (col == 1) {
                obj->setPosition(getPosition().x - obj->getDimensions().x / 2.f, obj->getPosition().y);
            }
            else if (col == 2) {
                obj->setPosition(getPosition().x + getDimensions().x + obj->getDimensions().x / 2.f, obj->getPosition().y);
            }
            else if (col == 3) {
                obj->setPosition(obj->getPosition().x, getPosition().y - obj->getDimensions().y / 2.f);
            }
            else if (col == 4) {
                obj->setPosition(obj->getPosition().x, getPosition().y + getDimensions().y + obj->getDimensions().y / 2.f);
            }
        }
    }
}

int SolidObject::checkCollision(GameObject* obj) {
    bool left = obj->getPosition().x + obj->getDimensions().x / 2.f > getPosition().x;
    bool right = obj->getPosition().x - obj->getDimensions().x / 2.f < getPosition().x + getDimensions().x;
    bool up = obj->getPosition().y + obj->getDimensions().y / 2.f > getPosition().y;
    bool down = obj->getPosition().y - obj->getDimensions().y / 2.f < getPosition().y + getDimensions().y;
    if (left && up && down && right) {
        sf::Vector2f cornerVecTL(-getDimensions().x / 2.f, getDimensions().y / 2.f);
        sf::Vector2f VecL(-getDimensions().x / 2.f, 0);
        sf::Vector2f dir(getPosition() + getDimensions() / 2.f - obj->getPosition());

        float thisCos = std::acos(cosF(cornerVecTL, VecL)) * 180 / PI;
        float objCos = std::acos(cosF(dir, VecL)) * 180 / PI;

        // left side
        if (objCos > 180 - thisCos)
            return 1;
        // right side
        if (objCos < thisCos)
            return 2;
        // top side
        if (objCos > thisCos && objCos < 180 - thisCos && !std::signbit(dir.y))
            return 3;
        // bottom side
        if (objCos > thisCos && objCos < 180 - thisCos && std::signbit(dir.y))
            return 4;
    }
    return 0; 
}

float SolidObject::cosF(sf::Vector2f a, sf::Vector2f b) {
    return (a.x * b.x + a.y * b.y) / std::sqrt(std::pow(a.x, 2) + std::pow(a.y, 2)) / std::sqrt(std::pow(b.x, 2) + std::pow(b.y, 2));
}

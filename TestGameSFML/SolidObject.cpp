#include "SolidObject.h"
#include "Bullet.h"


SolidObject::SolidObject() {
    sf::Vector2f recSize = sf::Vector2f(120.f, 320.f);
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
            if (col)
                std::cout << col << std::endl;
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
        sf::Vector2f dir(getPosition() + getDimensions() / 2.f - obj->getPosition());
        if (std::max(std::abs(dir.x), std::abs(dir.y)) == std::abs(dir.x) && !std::signbit(dir.x))
            return 1;
        if (std::max(std::abs(dir.x), std::abs(dir.y)) == std::abs(dir.x) && std::signbit(dir.x))
            return 2;
        if (std::max(std::abs(dir.x), std::abs(dir.y)) == std::abs(dir.y) && !std::signbit(dir.y))
            return 3;
        if (std::max(std::abs(dir.x), std::abs(dir.y)) == std::abs(dir.y) && std::signbit(dir.y))
            return 4;
    }
    return 0; 
}

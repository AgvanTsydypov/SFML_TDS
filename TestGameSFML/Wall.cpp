#include "Wall.h"
#include "Player.h"
#include "Enemy.h"

Wall::Wall() {
    sf::Vector2f recSize = sf::Vector2f(120.f, 420.f);
    sf::RectangleShape* shape = new sf::RectangleShape(recSize);
    shape->setFillColor(sf::Color::Green);
    setShape(shape);

    shape->setOrigin(0, 0);
}

void Wall::tick(TickData& tickData) {
    for (size_t i = 0; i < tickData.gameObjects->size(); i++) {
        if (toDestroy)
            break;
        GameObject* obj = (*tickData.gameObjects)[i];

        // Player
        Player* player = dynamic_cast<Player*>(obj);
        if (player != nullptr) {
            int col = checkCollision(player);

            sf::Vector2f dimensions = getDimensions();
            sf::Vector2f objDimensions = player->getDimensions();
            sf::Vector2f objPosition = player->getPosition();

            if (col == LEFT) {
                player->setPosition(position.x - objDimensions.x / 2.f, objPosition.y);
            }
            else if (col == RIGHT) {
                player->setPosition(position.x + dimensions.x + objDimensions.x / 2.f, objPosition.y);
            }
            else if (col == TOP) {
                player->setPosition(objPosition.x, position.y - objDimensions.y / 2.f);
            }
            else if (col == BOTTOM) {
                player->setPosition(objPosition.x, position.y + dimensions.y + objDimensions.y / 2.f);
            }
        }

        // Enemy
        Enemy* enemy = dynamic_cast<Enemy*>(obj);
        if (enemy != nullptr) {
            int col = checkCollision(enemy);

            sf::Vector2f dimensions = getDimensions();
            sf::Vector2f objDimensions = enemy->getDimensions();
            sf::Vector2f objPosition = enemy->getPosition();

            if (col == LEFT) {
                enemy->setPosition(position.x - objDimensions.x / 2.f, objPosition.y);
            }
            else if (col == RIGHT) {
                enemy->setPosition(position.x + dimensions.x + objDimensions.x / 2.f, objPosition.y);
            }
            else if (col == TOP) {
                enemy->setPosition(objPosition.x, position.y - objDimensions.y / 2.f);
            }
            else if (col == BOTTOM) {
                enemy->setPosition(objPosition.x, position.y + dimensions.y + objDimensions.y / 2.f);
            }
        }
    }
}

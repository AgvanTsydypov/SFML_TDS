#include "App.h"
#include "Bullet.h"
#include "Player.h"

float App::deltaTime = 0;

void App::initApp() {
	window = new sf::RenderWindow(sf::VideoMode(1024, 768), "Top-Down Shooter");

    lmbPressed = false;

    player = new Player();
    gameObjects.push_back(player);
}

void App::mainLoop() {
    sf::Clock deltaClock;

    float playerSpeed = 500.f;
    
    while (window->isOpen()) {
        // Update deltaTime value
        App::deltaTime = deltaClock.restart().asSeconds();

        bool upPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
        bool leftPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
        bool downPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
        bool rightPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
        int hDir = rightPressed - leftPressed;
        int vDir = downPressed - upPressed;

        if (hDir || vDir) {
            sf::Vector2f dir(static_cast<float>(hDir), static_cast<float>(vDir));
            sf::Vector2f speedVector = dir * App::deltaTime * playerSpeed;

            if (player->getPosition().x + speedVector.x < 0) {
                speedVector.x = 0;
                player->setPosition(0, player->getPosition().y);
            }
            if (player->getPosition().x + speedVector.x > window->getSize().x - player->getDimensions().x) {
                speedVector.x = 0;
                player->setPosition(window->getSize().x - player->getDimensions().x, player->getPosition().y);
            }

            if (player->getPosition().y + speedVector.y < 0) {
                speedVector.y = 0;
                player->setPosition(player->getPosition().x, 0);
            }
            if (player->getPosition().y + speedVector.y > window->getSize().y - player->getDimensions().y) {
                speedVector.y = 0;
                player->setPosition(player->getPosition().x, window->getSize().y - player->getDimensions().y);
            }

            player->move(speedVector);
        }

        bool shotDone = sf::Mouse::isButtonPressed(sf::Mouse::Left);

        if (shotDone) {
            lmbPressed = true;
            Bullet *bullet = new Bullet();
            bullet->setPosition(player->getPosition());
            gameObjects.push_back(bullet);
        }

        callTicks();
        
        pollEvents();

        drawObjects();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window->close();
    }
}

void App::callTicks() {
    for (size_t i = 0; i < gameObjects.size(); i++) {
        gameObjects[i]->tick();

        // Delete objects flagged to be destroyed
        if (gameObjects[i]->toDestroy) {
            std::vector<GameObject*>::iterator ind = std::find(gameObjects.begin(), gameObjects.end(), gameObjects[i]);
            delete gameObjects[i];
            if (ind != gameObjects.end())
                gameObjects.erase(ind);
        }
    }
}

void App::pollEvents() {
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();

        if (event.type == sf::Event::MouseButtonReleased)
            lmbPressed = false;
    }
}

void App::drawObjects() {
    window->clear(sf::Color::White);

    for (size_t i = 0; i < gameObjects.size(); i++) {
        gameObjects[i]->draw(*window);
    }

    window->display();
}

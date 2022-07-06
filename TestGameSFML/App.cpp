#include "App.h"
#include "Bullet.h"
#include "Player.h"
#include "SolidObject.h"

void App::initApp() {
	window = new sf::RenderWindow(sf::VideoMode(1024, 768), "Top-Down Shooter");

    tickData.windowSize = window->getSize();
    tickData.gameObjects = &gameObjects;

    player = new Player();
    gameObjects.push_back(player);
    SolidObject *so = new SolidObject();
    //std::cout << (dynamic_cast<SolidObject*>(&so) != nullptr) << std::endl;
    gameObjects.push_back(so);
    player->setPosition(player->getDimensions() / 2.f);
}

void App::mainLoop() {
    sf::Clock deltaClock;
    
    while (window->isOpen()) {
        // Update deltaTime value
        tickData.deltaTime = deltaClock.restart().asSeconds();

        getInput();

        callTicks();
        
        pollEvents();

        drawObjects();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window->close();
    }
}

void App::getInput() {
    tickData.upPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    tickData.leftPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    tickData.downPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
    tickData.rightPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::D);

    tickData.mousePos = sf::Mouse::getPosition(*window);
}

void App::callTicks() {
    for (size_t i = 0; i < gameObjects.size(); i++) {
        gameObjects[i]->tick(tickData);

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
            tickData.lmbPressed = false;
    }
}

void App::drawObjects() {
    window->clear(sf::Color::White);

    for (size_t i = 0; i < gameObjects.size(); i++) {
        gameObjects[i]->draw(*window);
    }

    window->display();
}

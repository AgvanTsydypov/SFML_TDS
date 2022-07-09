#include "App.h"
#include "Bullet.h"
#include "Player.h"
#include "Wall.h"
#include "Zombie.h"

void App::initApp() {
    int windowStyle = sf::Style::Close;

	window = new sf::RenderWindow(sf::VideoMode(gameWindowWidth, gameWindowHeight), "Top-Down Shooter", windowStyle);
    window->setFramerateLimit(0);

    tickData.windowSize = window->getSize();
    tickData.gameObjects = &gameObjects;
}

void App::launchGame() {
    // Player
    player = new Player();
    player->setPosition(player->getDimensions() / 2.f);
    gameObjects.push_back(player);

    // Test Wall
    Wall* wall = new Wall();
    gameObjects.push_back(wall);
    wall->setPosition(500, 120);
    wall = new Wall();
    wall->setPosition(400, 100);
    gameObjects.push_back(wall);

    // Test Zombie
    Zombie* zombie = new Zombie();
    zombie->setPosition(200, 50);
    gameObjects.push_back(zombie);

    // FPS counter
    fpsCounter = new sf::Text();
    basicFont = new sf::Font();
    basicFont->loadFromFile(FONT_DIR);
    fpsCounter->setFont(*basicFont);
    fpsCounter->setFillColor(sf::Color::Green);
    fpsCounter->setString("FPS: 0");
}

void App::mainLoop() {
    sf::Clock deltaClock;
    sf::Clock fpsClock;
    
    while (window->isOpen()) {
        // Update deltaTime value
        tickData.deltaTime = deltaClock.restart().asSeconds();

        // FPS counter
        long frameCount = std::lround(1.f / tickData.deltaTime);
        fpsCounter->setString("FPS: " + std::to_string(frameCount));

        pollEvents();

        getInput();

        callTicks();

        drawObjects();
    }
}

void App::getInput() {
    readInput = !isMouseOutOfWindow() && windowInFocus;

    tickData.upPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::W) && readInput;
    tickData.leftPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::A) && readInput;
    tickData.downPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::S) && readInput;
    tickData.rightPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::D) && readInput;

    tickData.lmbPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left) && readInput;

    tickData.lmbWasPressed = tickData.lmbPressed && !tickData.lmbWasPressedBefore;
    tickData.lmbWasPressedBefore = tickData.lmbPressed;

    if (readInput)
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
    sf::Event windowEvent;
    while (window->pollEvent(windowEvent)) {
        if (windowEvent.type == sf::Event::Closed)
            window->close();
        else if (windowEvent.type == sf::Event::LostFocus)
            windowInFocus = false;
        else if (windowEvent.type == sf::Event::GainedFocus)
            windowInFocus = true;

        if (windowEvent.type == sf::Event::MouseButtonReleased) {
            tickData.lmbWasPressedBefore = false;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && readInput)
        window->close();
}

void App::drawObjects() {
    window->clear(sf::Color::White);

    for (size_t i = 0; i < gameObjects.size(); i++) {
        gameObjects[i]->draw(*window);
    }

    window->draw(*fpsCounter);

    window->display();
}

bool App::isMouseOutOfWindow() {
    return sf::Mouse::getPosition(*window).x < 0 ||
        sf::Mouse::getPosition(*window).y < 0 ||
        sf::Mouse::getPosition(*window).x > gameWindowWidth ||
        sf::Mouse::getPosition(*window).y > gameWindowHeight;
}

App::~App() {
    delete window;
    delete fpsCounter;
    delete basicFont;

    for (size_t i = 0; i < gameObjects.size(); i++) {
        delete gameObjects[i];
    }
}

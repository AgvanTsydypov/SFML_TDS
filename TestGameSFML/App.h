#pragma once

#include "TDS.h"
#include "Player.h"
#include "GameObject.h"

class App {
public:
	~App();

	void initApp();

	// \brief Initializes game's starting conditions
	void launchGame();

	// \brief Performs game's main loop
	void mainLoop();

private:
	sf::RenderWindow* window;

	std::vector<GameObject*> gameObjects;

	Player* player;

	TickData tickData;

	sf::Text *fpsCounter;
	sf::Font* basicFont;

	void callTicks();
	void getInput();
	void pollEvents();
	void drawObjects();
};


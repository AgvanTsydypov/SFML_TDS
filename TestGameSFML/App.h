#pragma once

#include "TDS.h"
#include "Player.h"
#include "GameObject.h"

class App {
public:
	void initApp();

	// \brief Launches game's main loop
	void mainLoop();

private:
	sf::RenderWindow* window;

	std::vector<GameObject*> gameObjects;

	Player* player;

	TickData tickData;

	void callTicks();
	void getInput();
	void pollEvents();
	void drawObjects();
};


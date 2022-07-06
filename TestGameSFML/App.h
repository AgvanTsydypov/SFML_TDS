#pragma once

#include "TDS.h"
#include "Player.h"
#include "GameObject.h"

class App {
public:
	void initApp();

	// \brief Launches game's main loop
	void mainLoop();

	// \brief Returns seconds passed between previous and current main loop cycles
	static float deltaTime;

private:
	sf::RenderWindow* window;

	std::vector<GameObject*> gameObjects;

	Player* player;

	bool lmbPressed;

	void callTicks();
	void pollEvents();
	void drawObjects();
};


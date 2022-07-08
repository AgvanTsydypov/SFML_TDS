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

	// \brief checking for mouse presence in game window space
	bool isMouseOutOfWindow();

private:
	const int gameWindowWidth = 1024;
	const int gameWindowHeight = 768;

	sf::RenderWindow* window;

	std::vector<GameObject*> gameObjects;

	Player* player;

	TickData tickData;

	sf::Text *fpsCounter;
	sf::Font* basicFont;

	bool windowInFocus = true;
	bool readInput = true;

	void callTicks();
	void getInput();
	void pollEvents();
	void drawObjects();
};


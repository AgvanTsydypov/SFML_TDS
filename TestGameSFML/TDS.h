#pragma once
/*
#define _CRTDBG_MAP_ALLOC

#ifdef _DEBUG
	#define DBG_NEW  new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
	// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
	// allocations to be of _CLIENT_BLOCK type
#else
	#define DBG_NEW  new
#endif
*/

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include <crtdbg.h>

// Collision side
#define LEFT 1
#define RIGHT 2
#define TOP 3
#define BOTTOM 4

#define FONT_DIR "C:/Windows/Fonts/arial.ttf"

class GameObject;

struct TickData {
	sf::Vector2u windowSize;

	// \brief Returns seconds passed between previous and current main loop cycles
	float deltaTime = 0;

	bool upPressed = false;
	bool leftPressed = false;
	bool downPressed = false;
	bool rightPressed = false;

	bool lmbPressed = false;
	bool lmbWasPressed = false;
	bool lmbWasPressedBefore = false;

	sf::Vector2i mousePos = sf::Vector2i();

	std::vector<GameObject*> *gameObjects;

};
#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>

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

	sf::Vector2i mousePos = sf::Vector2i();

	std::vector<GameObject*> *gameObjects;
};
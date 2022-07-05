#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>

class App
{
public:
	void init_app();
	void main_loop();

private:
	sf::RenderWindow* window;
	std::vector<sf::Drawable *> *objects;
	sf::CircleShape* player;
	bool lmbPressed;

	void poll_events();
	void draw_objects();
};


#pragma once

#include "App.h"

class Bullet
{
public:
	sf::CircleShape shape;
	bool to_destroy;
	
	Bullet(float time, sf::Vector2f bullet_speed, sf::Vector2f pos);
	
	void bullet_new_pos(sf::Vector2f pos);
	void tick(float dt);

private:
	float timer;
	sf::Vector2f speed;
};


#pragma once

#include "TDS.h"

class GameObject {
public:
	// \brief If GameObject is flagged to be destroyed it will be deleted this frame
	bool toDestroy = false;

	GameObject();
	~GameObject();
	
	// \brief This method is used to put sprite/shape to the window
	virtual void draw(sf::RenderWindow & window);

	// \brief This method is called every frame
	virtual void tick(TickData & tickData);

	virtual void setPosition(sf::Vector2f new_position);
	virtual void setPosition(float x, float y);
	virtual sf::Vector2f getPosition();
	virtual void move(sf::Vector2f speed);

	virtual void setShape(sf::Shape* shape);
	// \brief Returns a vector containing the width and height of this objects bounding box
	virtual sf::Vector2f getDimensions();

protected:
	sf::Vector2f position;
	sf::Sprite* sprite;
	sf::Shape* shape;
};


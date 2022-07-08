#include "Math.h"
#include "GameObject.h"

GameObject::GameObject() {
	sprite = nullptr;
	shape = nullptr;
	position = sf::Vector2f(0, 0);
}

GameObject::~GameObject() {
	if (sprite)
		delete sprite;
	if (shape)
		delete shape;
}

void GameObject::draw(sf::RenderWindow& window) {
	if (sprite)
		window.draw(*sprite);
	if (shape)
		window.draw(*shape);
}

void GameObject::tick(TickData & tickData) {

}

void GameObject::setPosition(sf::Vector2f new_position) {
	position = new_position;

	if (sprite)
		sprite->setPosition(position);
	if (shape)
		shape->setPosition(position);
}

void GameObject::setPosition(float x, float y) {
	setPosition(sf::Vector2f(x, y));
}

void GameObject::move(sf::Vector2f speed) {
	setPosition(position + speed);
}

void GameObject::setShape(sf::Shape* new_shape) {
	shape = new_shape;
	sf::FloatRect boundaries = shape->getGlobalBounds();
	shape->setOrigin(boundaries.width / 2, boundaries.height / 2);
}

sf::Vector2f GameObject::getPosition() {
	return position;
}

sf::Vector2f GameObject::getDimensions() {
	sf::FloatRect boundaries;
	if (sprite)
		boundaries = sprite->getGlobalBounds();
	else if (shape)
		boundaries = shape->getGlobalBounds();
	else
		return sf::Vector2f(0, 0);

	sf::Vector2f dimensions(boundaries.width, boundaries.height);
	return dimensions;
}

void GameObject::setRotation(sf::Vector2f dir) {
	if (sprite)
		sprite->setRotation(vectorAngle(dir));
	if (shape)
		shape->setRotation(vectorAngle(dir));
}

void GameObject::setRotation(float angle) {
	if (sprite)
		sprite->setRotation(angle);
	if (shape)
		shape->setRotation(angle);
}

sf::FloatRect GameObject::getGlobalBounds() {
	if (sprite)
		return sprite->getGlobalBounds();
	if (shape)
		return shape->getGlobalBounds();

	return sf::FloatRect();
}

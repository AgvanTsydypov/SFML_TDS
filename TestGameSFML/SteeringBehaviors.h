#pragma once

#include <SFML/System.hpp>
#include "Math.h"

namespace sb {

	// \brief Returns a movement vector with applied steering vector
	sf::Vector2f applySteering(sf::Vector2f movementVector, sf::Vector2f steeringVector, float speed);

	/// <summary>
	/// Returns a steering vector for turning towards the target. Subsequent calls
	/// allow for moving towards the target with smooth rotation in it's direction.
	/// </summary>
	/// <param name="position">- Steering object current position</param>
	/// <param name="movementVector">- Current movement vector</param>
	/// <param name="mass">- Defines rotation speed</param>
	sf::Vector2f seek(sf::Vector2f position, sf::Vector2f target, sf::Vector2f movementVector, float maxSpeed, float mass);

}

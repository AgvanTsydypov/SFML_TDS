#include "SteeringBehaviors.h"

namespace sb {

	sf::Vector2f applySteering(sf::Vector2f movementVector, sf::Vector2f steeringVector, float speed) {
		sf::Vector2f finalVector = movementVector + steeringVector;
		finalVector = vectorNormalized(finalVector);
		finalVector *= speed;

		return finalVector;
	}

	sf::Vector2f seek(sf::Vector2f position, sf::Vector2f targetPosition, sf::Vector2f movementVector, float maxSpeed, float mass) {
		sf::Vector2f desiredVector = targetPosition - position;
		desiredVector = vectorNormalized(desiredVector);
		desiredVector *= maxSpeed;

		sf::Vector2f steeringVector = desiredVector - movementVector;
		if (mass >= 1.f)
			steeringVector /= mass;

		return steeringVector;
	}

}

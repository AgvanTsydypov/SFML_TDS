#pragma once

#include "TDS.h"

#define PI 3.14159265f

float cosF(sf::Vector2f a, sf::Vector2f b);

float vectorAngle(sf::Vector2f vec);

float vectorLength(sf::Vector2f vec);
float vectorLength(sf::Vector2i vec);

sf::Vector2f vectorNormalized(sf::Vector2f vec);
sf::Vector2f vectorNormalized(sf::Vector2i vec);

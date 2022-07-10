#include "Math.h"

float cosF(sf::Vector2f a, sf::Vector2f b) {
    float ret = (a.x * b.x + a.y * b.y) / std::sqrtf(std::powf(a.x, 2) + std::powf(a.y, 2)) / std::sqrtf(std::powf(b.x, 2) + std::powf(b.y, 2));
    return ret;
}

float vectorAngle(sf::Vector2f vec) {
    return -atan2(vec.x, vec.y) * 180 / PI;
}

float vectorLength(sf::Vector2f vec) {
    return std::sqrtf(std::powf(vec.x, 2) + std::powf(vec.y, 2));
}

float vectorLength(sf::Vector2i vec) {
    return std::sqrt(std::powf(static_cast<float>(vec.x), 2) + std::powf(static_cast<float>(vec.y), 2));
}

sf::Vector2f vectorNormalized(sf::Vector2f vec) {
    float length = vectorLength(vec);
    if (length == 0)
        return sf::Vector2f();

    return vec / length;
}

sf::Vector2f vectorNormalized(sf::Vector2i vec) {
    float length = vectorLength(vec);
    if (length == 0)
        return sf::Vector2f();

    return sf::Vector2f(vec) / length;
}

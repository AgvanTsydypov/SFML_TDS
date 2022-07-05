#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML works!");
    sf::CircleShape shape(50.f, 30);
    shape.setFillColor(sf::Color::Green);
    float sprite_speed = 120.f;
    sf::Clock deltaClock;

    sf::Texture texture;
    if (!texture.loadFromFile("pic.png"))
    {
        std::cout << "Error: can't load texture!!!" << std::endl;
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(sf::Vector2f(1.f, 1.f));

    while (window.isOpen())
    {
        sf::Time dt = deltaClock.restart();
        bool upPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
        bool leftPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
        bool downPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
        bool rightPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
        int hDir = rightPressed - leftPressed;
        int vDir = downPressed - upPressed;
        if (hDir || vDir)
        {
            sf::Vector2f dir(hDir, vDir);
            // left key is pressed: move our character
            shape.move(dir * dt.asSeconds() * sprite_speed);
        }
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(shape);
        window.draw(sprite);
        window.display();
    }

    return 0;
}
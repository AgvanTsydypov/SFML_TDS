#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML works!");
    sf::CircleShape shape(50.f, 30);
    shape.setFillColor(sf::Color::Green);
    float sprite_speed = 1000.f;
    sf::Clock deltaClock;

    //sf::Texture texture;
    //if (!texture.loadFromFile("pic.png"))
    //{
    //    std::cout << "Error: can't load texture!!!" << std::endl;
    //}

    //sf::Sprite sprite;
    //sprite.setTexture(texture);
    //sprite.setScale(sf::Vector2f(1.f, 1.f));

    while (window.isOpen())
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();

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
            sf::Vector2f speedVector(hDir * dt.asSeconds() * sprite_speed, vDir * dt.asSeconds() * sprite_speed);
            
            if (shape.getPosition().x + speedVector.x < 0)
            {
                speedVector.x = 0;
                shape.setPosition(0, shape.getPosition().y);
            }
            if (shape.getPosition().x + speedVector.x > window.getSize().x - shape.getRadius() * 2)
            {
                speedVector.x = 0;
                shape.setPosition(window.getSize().x - shape.getRadius() * 2, shape.getPosition().y);
            }

            if (shape.getPosition().y + speedVector.y < 0) 
            {
                speedVector.y = 0;
                shape.setPosition(shape.getPosition().x, 0);
            }
            if (shape.getPosition().y + speedVector.y > window.getSize().y - shape.getRadius() * 2)
            {
                speedVector.y = 0;
                shape.setPosition(shape.getPosition().x, window.getSize().y - shape.getRadius() * 2);
            }

            shape.move(speedVector);
        }
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(shape);
        //window.draw(sprite);
        window.display();
    }

    return 0;
}
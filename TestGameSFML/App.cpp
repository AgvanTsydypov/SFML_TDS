#include "App.h"
#include "Bullet.h"

void App::init_app()
{
	window = new sf::RenderWindow(sf::VideoMode(1024, 768), "SFML works!");

    objects = new std::vector<sf::Drawable *>();

    sf::CircleShape *shape = new sf::CircleShape(50.f, 30);
    shape->setFillColor(sf::Color::Green);

    player = shape;
    objects->push_back(shape);

    lmbPressed = false;
}

void App::main_loop()
{
    float sprite_speed = 1000.f;
    sf::Clock deltaClock;
    Bullet* bullet = nullptr;
    sf::Vector2f bullet_speed(200.f, 0);
    std::vector<Bullet*> bullets;

    while (window->isOpen())
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window->close();

        sf::Time dt = deltaClock.restart();
        bool upPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
        bool leftPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
        bool downPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
        bool rightPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
        int hDir = rightPressed - leftPressed;
        int vDir = downPressed - upPressed;
        bool shotDone = sf::Mouse::isButtonPressed(sf::Mouse::Left);

        if (shotDone) {
            lmbPressed = true;
            std::cout << "shotDone" << std::endl;
            for (int i = 0; i < 20; i++) {
                bullet = new Bullet(1.f, bullet_speed, player->getPosition());

                bullets.push_back(bullet);
                objects->push_back(&bullet->shape);
            }
        }

        float t = dt.asSeconds();
        for (int i = 0; i < bullets.size(); i++) {
            bullets[i]->tick(t);

            if (bullets[i]->to_destroy) {
                std::vector<sf::Drawable*>::iterator ind = std::find(objects->begin(), objects->end(), &bullets[i]->shape);
                if (ind != objects->end())
                    objects->erase(ind);
                delete bullets[i];
                std::cout << "prev " << bullets.size() << std::endl;
                bullets.erase(bullets.begin() + i);
                std::cout << bullets.size() << std::endl;
            }
        }

        if (hDir || vDir)
        {
            sf::Vector2f dir(hDir, vDir);
            sf::Vector2f speedVector(hDir * dt.asSeconds() * sprite_speed, vDir * dt.asSeconds() * sprite_speed);

            if (player->getPosition().x + speedVector.x < 0)
            {
                speedVector.x = 0;
                player->setPosition(0, player->getPosition().y);
            }
            if (player->getPosition().x + speedVector.x > window->getSize().x - player->getRadius() * 2)
            {
                speedVector.x = 0;
                player->setPosition(window->getSize().x - player->getRadius() * 2, player->getPosition().y);
            }

            if (player->getPosition().y + speedVector.y < 0)
            {
                speedVector.y = 0;
                player->setPosition(player->getPosition().x, 0);
            }
            if (player->getPosition().y + speedVector.y > window->getSize().y - player->getRadius() * 2)
            {
                speedVector.y = 0;
                player->setPosition(player->getPosition().x, window->getSize().y - player->getRadius() * 2);
            }

            player->move(speedVector);
        }
        
        poll_events();

        draw_objects();
    }
}

void App::poll_events()
{
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();

        if (event.type == sf::Event::MouseButtonReleased)
            lmbPressed = false;
    }
}

void App::draw_objects()
{
    window->clear(sf::Color::White);

    for (int i = 0; i < objects->size(); i++)
    {
        sf::Drawable* obj = (*(objects + 0))[i];
        window->draw(*obj);
    }

    window->display();
}

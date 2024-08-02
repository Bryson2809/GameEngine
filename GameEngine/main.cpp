#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <cstdlib>
#include <iostream>
#include <string>
#include "Body.h"
#include "Rectangle.h"
#include "Constants.h"
#include "Collision.h"

int main()
{
    sf::ContextSettings settings;

    sf::RenderWindow window(sf::VideoMode(800, 600), "My Window");
    window.setTitle("Game Engine");

    window.setActive();

    bool running = true;

    bool moveUp = false;
    bool moveDown = false;
    bool moveLeft = false;
    bool moveRight = false;

    Rect rectangle(sf::Vector2f(50.f, 50.f), 50.f, 50.f, 25.f, true, sf::Color(100, 250, 50), 10.f);
    Rect rectangle2(sf::Vector2f(200.f, 50.f), 50.f, 50.f, 25.f, false, sf::Color(100, 250, 50), 10.f);
    Rect stationaryRectangle(sf::Vector2f(400.f, 400.f), 50.f, 50.f, 25.f, false, sf::Color(100, 250, 50), 10.f);

    std::vector<Body*> bodies = { &rectangle, &rectangle2 };

    sf::Clock clock;
    sf::Time elapsedTime;
    float deltaTime = 0;

    while (running) {
        elapsedTime = clock.restart();
        deltaTime = elapsedTime.asSeconds();

        sf::Event event;

        while (window.pollEvent(event)) {
            switch (event.type) {
                // Close Window
                case sf::Event::Closed:
                    window.close();
                    running = false;
                    break;

                // Key Pressed
                case sf::Event::KeyPressed:
                    if (event.key.scancode == sf::Keyboard::Scan::Escape) {
                        window.close();
                        running = false;
                    }

                    break;

                case sf::Event::Resized:
                    glViewport(0, 0, event.size.width, event.size.height);

                default:
                    break;
            }
        }
        
        window.clear(sf::Color::Black);

        for (int i = 0; i < bodies.size(); i++) {
            bodies[i]->update();
            Collision::polygonVPolygon(*bodies[i], stationaryRectangle);
            for (int j = 1; j < bodies.size(); j++) {

            }
            bodies[i]->draw(window);
        }

        stationaryRectangle.draw(window);

        window.display();

        while (clock.getElapsedTime().asMilliseconds() < (1000 / Constants::MAX_FRAMES)) {}

        //std::cout << "FPS: " << (round) (1 / deltaTime) << std::endl;
    }

    return 0;
}
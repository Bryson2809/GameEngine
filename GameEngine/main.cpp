#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <cstdlib>
#include <iostream>
#include <string>
#include "Body.h"
#include "Rectangle.h"
#include "Constants.h"

int main()
{
    sf::ContextSettings settings;

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "My Window");
    window.setTitle("Game Engine");

    window.setActive();

    bool running = true;

    bool moveUp = false;
    bool moveDown = false;
    bool moveLeft = false;
    bool moveRight = false;

    sf::CircleShape circle(50.f);
    circle.setFillColor(sf::Color(100, 250, 50));

    Rect rectangle(sf::Vector2f(0.f, 0.f), 50.f, 50.f);

    sf::Vector2f position = {};

    sf::Clock clock;
    sf::Time elapsedTime;
    float deltaTime = 0;

    while (running) {
        elapsedTime = clock.restart();
        deltaTime = elapsedTime.asSeconds();

        if (deltaTime < Constants::MAX_FRAMES) {
            deltaTime = Constants::MAX_FRAMES;
        }
        else if (deltaTime > Constants::MIN_FRAMES) {
            deltaTime = Constants::MIN_FRAMES;
        }

        sf::Event event;
        position = rectangle.getPosition();

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

        rectangle.update();

        window.clear(sf::Color::Black);

        rectangle.draw(window);

        window.display();

        std::cout << "FPS: " << 1 / deltaTime << std::endl;
    }

    return 0;
}
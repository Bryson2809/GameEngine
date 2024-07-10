#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"

struct Vector2 {
	float x;
	float y;
};

class Body : public sf::Drawable 
{
private:
	sf::Vector2f position;
	float deltaTime;
	sf::Clock clock;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void draw(sf::RenderTarget& target) const;

public:
	Body(); // Default Contructor
	Body(sf::Vector2f position);
	~Body();

	sf::Vector2f getPosition();
	float getDeltaTime();

	void update();
};
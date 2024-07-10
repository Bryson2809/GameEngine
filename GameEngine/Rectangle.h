#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Body.h"

class Rect : public Body
{
private:
	sf::Vector2f position;
	sf::Clock clock;
	float length;
	float width;
	float deltaTime;
	float moveSpeed;

	void setDeltaTime(float deltaTime);

public:
	Rect();
	Rect(sf::Vector2f position, float length, float width);
	Rect(Body& body);
	~Rect();

	sf::Vector2f getPosition();
	float getLength();
	float getWidth();
	float getMoveSpeed();

	void setPosition(sf::Vector2f position);
	void setLength(float length);
	void setWidth(float width);
	void setMoveSpeed(float moveSpeed);

	void update();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void draw(sf::RenderTarget& target) const;

	void calculateDeltaTime();
};
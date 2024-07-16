#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Body.h"

class Rect : public Body
{
private:
	sf::Vector2f position;
	sf::Clock clock;
	sf::Color color;
	float width;
	float height;
	float deltaTime;
	float moveSpeed;
	bool isControllable;
	std::vector<Vector2> vertices;


	void setDeltaTime(float deltaTime);

public:
	Rect();
	Rect(sf::Vector2f position, float width, float height, float moveSepeed, bool isControllable, sf::Color color);
	Rect(Body& body);
	~Rect();

	sf::Vector2f getPosition();
	float getWidth();
	float getHeight();
	float getMoveSpeed();
	std::vector<Vector2> getVertices();

	void setPosition(sf::Vector2f position);
	void setWidth(float width);
	void setHeight(float height);
	void setMoveSpeed(float moveSpeed);
	void setColor(sf::Color color);

	void update();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void draw(sf::RenderTarget& target) const;

	void calculateDeltaTime();
	void calculateVertices();
};
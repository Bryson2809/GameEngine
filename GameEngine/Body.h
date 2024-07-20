#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Vector2.h"

class Body : public sf::Drawable 
{
private:
	sf::Vector2f position;
	sf::Clock clock;
	sf::Color color;
	float deltaTime;
	bool isControllable;
	std::vector<Vector2> vertices;

	// Physics
	float mass;
	Vector2 velocity;
	Vector2 acceleration;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void draw(sf::RenderTarget& target) const;

public:
	Body(); // Default Contructor
	Body(sf::Vector2f position, bool isControllable, sf::Color color, float mass);
	~Body();

	sf::Vector2f getPosition();
	virtual float getDeltaTime();
	bool getIsControllable();
	virtual std::vector<Vector2> getVertices();
	virtual float getMass();
	virtual Vector2 getVelocity();
	virtual Vector2 getAcceleration();

	virtual void setPosition(sf::Vector2f position);
	virtual void setColor(sf::Color color);
	virtual void setMass(float mass);
	virtual void setVelocity(Vector2 velocity);
	virtual void setAcceleration(Vector2 acceleration);

	// Physics calculations
	virtual void calculatePosition();
	virtual void calculateVelocity();
	virtual void calculateAcceleration();

	virtual void update();
};
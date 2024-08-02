#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Vector2.h"
#include "Environment.h"

class Body : public sf::Drawable 
{
private:
	sf::Vector2f position;
	sf::Clock clock;
	sf::Color color;
	float deltaTime;
	float rotation;
	bool isControllable;
	std::vector<Vector2> vertices;

	// Physics
	float mass;
	Vector2 velocity;
	Vector2 acceleration;

public:
	Body(); // Default Contructor
	Body(sf::Vector2f position, bool isControllable, sf::Color color, float mass);
	~Body();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void draw(sf::RenderTarget& target) const;

	sf::Vector2f getPosition();
	virtual float getRotation();
	virtual float getDeltaTime();
	bool getIsControllable();
	virtual std::vector<Vector2> getVertices();
	virtual float getMass();
	virtual Vector2 getVelocity();
	virtual Vector2 getAcceleration();

	virtual void setPosition(sf::Vector2f position);
	virtual void setRotation(float rotation);
	virtual void setColor(sf::Color color);
	virtual void setMass(float mass);
	virtual void setVelocity(Vector2 velocity);
	virtual void setAcceleration(Vector2 acceleration);

	virtual void calculateVertices();
	virtual void calcualteRelaticeVertices();

	// Physics calculations
	virtual void calculatePosition();
	virtual void calculateVelocity();
	virtual void calculateAcceleration();
	virtual Vector2 calculateRotation(float x, float y, float relativeX, float relativeY);

	virtual void update();
};
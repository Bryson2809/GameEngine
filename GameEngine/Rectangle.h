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
	float rotation;
	bool isControllable;
	bool isColliding;
	std::vector<Vector2> vertices;
	std::vector<Vector2> relativeVertices;

	// Physics
	float mass;
	Vector2 velocity;
	Vector2 acceleration;
	Vector2 netForce;


	void setDeltaTime(float deltaTime);

public:
	Rect();
	Rect(sf::Vector2f position, float width, float height, float moveSepeed, bool isControllable, sf::Color color, float mass);
	Rect(Body& body);
	~Rect();

	sf::Vector2f getPosition();
	float getRotation();
	float getWidth();
	float getHeight();
	float getMoveSpeed();
	float getDeltaTime();
	std::vector<Vector2> getVertices();
	std::vector<Vector2> getRelativeVertices();
	float getMass();
	Vector2 getVelocity();
	Vector2 getAcceleration();
	bool getIsColliding();

	void setPosition(sf::Vector2f position);
	void setRotation(float rotation);
	void setWidth(float width);
	void setHeight(float height);
	void setMoveSpeed(float moveSpeed);
	void setColor(sf::Color color);
	void setMass(float mass);
	void setVelocity(Vector2 velocity);
	void setAcceleration(Vector2 acceleration);
	void setIsColliding(bool isColliding);

	void update();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void draw(sf::RenderTarget& target) const;

	void calculateDeltaTime();
	void calculateVertices();
	void calculateRelativeVertices();

	// Handlers
	void handleCollisionEnter();
	void handleCollisionExit();

	// Physics Calculations
	void calculatePosition();
	void calculateVelocity();
	void calculateAcceleration();
	Vector2 calculateRotation(float x, float y, float relativeX, float relativeY);
	void addForce(Vector2 newtons);
	void calculateAccelerationDueToForce();
};
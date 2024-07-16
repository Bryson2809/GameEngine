#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Constants.h"

struct Vector2 {
	float x;
	float y;

	inline void operator=(Vector2 vec) {
		this->x = vec.x;
		this->y = vec.y;
	}

	inline Vector2 operator-(Vector2 vec) {
		return { this->x - vec.x, this->y - vec.y };
	}

	inline Vector2 operator+(Vector2 vec) {
		return { this->x + vec.x, this->y + vec.y };
	}

	inline Vector2 operator/(float n) {
		return { this->x / n, this->y / n };
	}

	inline static float dot(Vector2 vec1, Vector2 vec2) {
		return (vec1.x * vec2.x) + (vec1.y * vec2.y);
	}

	inline static Vector2 normalize(Vector2 vec) {
		float magnitude = sqrtf((vec.x * vec.x) + (vec.y * vec.y));
		return vec / magnitude;
	}
};

class Body : public sf::Drawable 
{
private:
	sf::Vector2f position;
	sf::Clock clock;
	sf::Color color;
	float deltaTime;
	bool isControllable;
	std::vector<Vector2> vertices;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void draw(sf::RenderTarget& target) const;

public:
	Body(); // Default Contructor
	Body(sf::Vector2f position, bool isControllable, sf::Color color);
	~Body();

	sf::Vector2f getPosition();
	float getDeltaTime();
	bool getIsControllable();
	virtual std::vector<Vector2> getVertices();

	virtual void setPosition(sf::Vector2f position);
	virtual void setColor(sf::Color color);

	virtual void update();
};
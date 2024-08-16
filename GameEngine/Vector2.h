#pragma once

#include <SFML/Graphics.hpp>

struct Vector2 {
	float x;
	float y;

	inline void operator = (Vector2 vec) {
		this->x = vec.x;
		this->y = vec.y;
	}

	inline void operator += (Vector2 vec) {
		this->x += vec.x;
		this->y += vec.y;
	}

	inline void operator -= (Vector2 vec) {
		this->x -= vec.y;
		this->y -= vec.y;
	}

	inline void operator *= (float n) {
		this->x *= n;
		this->y *= n;
	}

	friend std::ostream& operator << (std::ostream& o, Vector2& vec) {
		o << "{ " << vec.x << ", " << vec.y << " }";
		return o;
	}

	inline Vector2 operator-(Vector2 vec) {
		return { this->x - vec.x, this->y - vec.y };
	}

	inline Vector2 operator+(Vector2 vec) {
		return { this->x + vec.x, this->y + vec.y };
	}

	inline Vector2 operator*(float n) {
		return { this->x * n, this->y * n };
	}

	inline Vector2 operator/(float n) {
		return { this->x / n, this->y / n };
	}

	inline Vector2 getNormal() {
		return { -this->y, this->x };
	}

	inline sf::Vector2f convertToVector2f() {
		return sf::Vector2f(this->x, this->y);
	}

	inline static Vector2 convertVector2fToVector2(sf::Vector2f vec) {
		return { vec.x, vec.y };
	}

	inline static float dot(Vector2 vec1, Vector2 vec2) {
		return (vec1.x * vec2.x) + (vec1.y * vec2.y);
	}

	inline static Vector2 normalize(Vector2 vec) {
		float magnitude = sqrtf((vec.x * vec.x) + (vec.y * vec.y));
		return vec / magnitude;
	}

	inline static sf::Vector2f transformToVector2f(Vector2 vec) {
		return sf::Vector2f(vec.x, vec.y);
	}

	inline float getLength() {
		return std::sqrtf((this->x * this->x) + (this->y * this->y));
	}
};
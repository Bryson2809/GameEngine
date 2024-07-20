#pragma once

#include <SFML/Graphics.hpp>

struct Vector2 {
	float x;
	float y;

	inline void operator=(Vector2 vec) {
		this->x = vec.x;
		this->y = vec.y;
	}

	inline void operator+=(Vector2 vec) {
		this->x += vec.x;
		this->y += vec.y;
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
};
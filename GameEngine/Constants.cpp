#include "Constants.h"

const int Constants::MAX_FRAMES = 60;

const float Constants::PI = 3.1415;

const Vector2 Constants::GRAVITY = { 0.f, 9.80665f };

float Constants::cos(float deg) {
	float radians = deg * (PI / 180);

	float val = std::cosf(radians);

	if (std::abs(val) < 0.01f) {
		val = 0.f;
	}

	return val;
}

float Constants::sin(float deg) {
	float radians = deg * (PI / 180);

	float val = std::sinf(radians);

	if (std::abs(val) < 0.01f) {
		val = 0.f;
	}

	return val;
}
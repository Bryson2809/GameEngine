#pragma once

#include "Vector2.h"
#include "iostream"

class Constants {
public:
	static const int MAX_FRAMES; // 60 fps

	static const float PI; // 3.1415

	static const Vector2 GRAVITY; // -9.81 m/s^2

	static float cos(float deg);
	static float sin(float deg);
};
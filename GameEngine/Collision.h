#pragma once
#include "Body.h";
#include "Rectangle.h";

static class Collision {
private:
	bool colliding;

	static void projectVertices(std::vector<Vector2> vertices, Vector2 axis, float& min, float& max);

public:
	static bool polygonVPolygon(Body& b1, Body& b2);
};
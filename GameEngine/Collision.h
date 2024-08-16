#pragma once
#include "Body.h";
#include "Rectangle.h.";

static class Collision {
private:
	bool colliding;

	static void projectVertices(std::vector<Vector2> vertices, Vector2 axis, float& min, float& max);
	static float calculateOverlap(float minA, float maxA, float minB, float maxB);
	static Vector2 getMTV(Vector2 axis, float overlap);

public:
	static bool polygonVPolygon(Body& body1, Body& body2);
};
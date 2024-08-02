#include <iostream>
#include "Collision.h"

bool Collision::polygonVPolygon(Body& b1, Body& b2) {
	std::vector<Vector2> verticesA = b1.getVertices();
	std::vector<Vector2> verticesB = b2.getVertices();

	float maxA;
	float maxB;

	float minA;
	float minB;

	for (int i = 0; i < verticesA.size(); i++) {
		Vector2 edge = verticesA[(i + 1) % verticesA.size()] - verticesA[i];
		Vector2 perpAxis = Vector2::normalize({ edge.y, edge.x });

		Collision::projectVertices(verticesA, perpAxis, minA, maxA);
		Collision::projectVertices(verticesB, perpAxis, minB, maxB);

		if (minA > maxB || minB > maxA) {
			b1.setColor(sf::Color(100, 250, 50));
			b2.setColor(sf::Color(100, 250, 50));
			return false;
		}
	}

	for (int i = 0; i < verticesB.size(); i++) {
		Vector2 edge = verticesB[(i + 1) % verticesB.size()] - verticesB[i];
		Vector2 perpAxis = { -edge.y, edge.x };

		Collision::projectVertices(verticesA, perpAxis, minA, maxA);
		Collision::projectVertices(verticesB, perpAxis, minB, maxB);

		if (minA > maxB || minB > maxA) {
			b1.setColor(sf::Color(100, 250, 50));
			b2.setColor(sf::Color(100, 250, 50));
			return false;
		}
	}
	
	b1.setColor(sf::Color(250, 0, 0));
	b2.setColor(sf::Color(250, 0, 0));
	return true;
}

void Collision::projectVertices(std::vector<Vector2> vertices, Vector2 axis, float& min, float& max) {
	min = FLT_MAX;
	max = FLT_MIN;
	for (Vector2 vec : vertices) {
		float proj = Vector2::dot(vec, axis);

		if (proj < min) min = proj;
		if (proj > max) max = proj;
	}
}
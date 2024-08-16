#include <iostream>
#include <map>
#include <math.h>
#include "Collision.h"

bool Collision::polygonVPolygon(Body& body1, Body& body2) {
	std::vector<Vector2> verticesA = body1.getVertices();
	std::vector<Vector2> verticesB = body2.getVertices();


	float maxA;
	float maxB;

	float minA;
	float minB;

	float smallestOverlap = FLT_MAX;
	Vector2 axisOfLeastOverlap = { 0.f, 0.f };

	for (int i = 0; i < verticesA.size(); i++) {
		Vector2 edge = verticesA[(i + 1) % verticesA.size()] - verticesA[i];
		Vector2 perpAxis = Vector2::normalize({ edge.y, edge.x });

		Collision::projectVertices(verticesA, perpAxis, minA, maxA);
		Collision::projectVertices(verticesB, perpAxis, minB, maxB);

		if (minA > maxB || minB > maxA) {
			/*body1.handleCollisionExit();
			body2.handleCollisionExit();*/
			return false;
		}

		float overlap = calculateOverlap(minA, maxA, minB, maxB);
		if (overlap < smallestOverlap) {
			smallestOverlap = overlap;
			axisOfLeastOverlap = edge;
		}
	}

	for (int i = 0; i < verticesB.size(); i++) {
		Vector2 edge = verticesB[(i + 1) % verticesB.size()] - verticesB[i];
		Vector2 perpAxis = { -edge.y, edge.x };

		Collision::projectVertices(verticesA, perpAxis, minA, maxA);
		Collision::projectVertices(verticesB, perpAxis, minB, maxB);

		if (minA > maxB || minB > maxA) {
			/*body1.handleCollisionExit();
			body2.handleCollisionExit();*/

			return false;
		}

		float overlap = calculateOverlap(minA, maxA, minB, maxB);
		if (overlap < smallestOverlap) {
			smallestOverlap = overlap;
			axisOfLeastOverlap = edge;
		}
	}

	body1.handleCollisionEnter();
	body2.handleCollisionEnter();

	/*Vector2 newPosition = axisOfLeastOverlap / (axisOfLeastOverlap.getLength());
	newPosition = Vector2::normalize(newPosition);*/

	Vector2 newPosition = Vector2::normalize(axisOfLeastOverlap).getNormal();

	Vector2 direction = Vector2::convertVector2fToVector2(body1.getPosition()) - Vector2::convertVector2fToVector2(body2.getPosition());

	if (Vector2::dot(newPosition, direction) < 0.f) {
		newPosition *= -1;
	}

	body1.setPosition((Vector2::convertVector2fToVector2(body1.getPosition()) + Vector2::normalize(newPosition) * smallestOverlap).convertToVector2f());

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

float Collision::calculateOverlap(float minA, float maxA, float minB, float maxB) {
	/*if (maxA > maxB) {
		return maxB - minA;
	}
	else {
		return maxA - minB;
	}*/
	return std::min(maxA - minB, maxB - minA);
}

Vector2 Collision::getMTV(Vector2 axis, float overlap) {
	float angle = atanf(axis.y / axis.x);
	float x = Constants::cos(angle) * overlap;
	float y = Constants::sin(angle) * overlap;

	return { 0.f, 0.f };
}
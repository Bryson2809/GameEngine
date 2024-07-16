#include "Body.h"

Body::Body() 
{
	this->position = { 0.f, 0.f };
	this->isControllable = false;
	this->deltaTime = 0.f;
	this->color = sf::Color(255, 255, 255);
}

Body::Body(sf::Vector2f position, bool isControllable, sf::Color color) 
{
	this->position = position;
	this->isControllable = isControllable;
	this->deltaTime = 0.f;
	this->setColor(color);
}

Body::~Body() {}

sf::Vector2f Body::getPosition()
{
	return this->position;
}

bool Body::getIsControllable() {
	return this->isControllable;
}

float Body::getDeltaTime() {
	return this->deltaTime;
}

std::vector<Vector2> Body::getVertices() {
	std::cout << "this is the body class" << std::endl;
	return this->vertices;
}

void Body::setPosition(sf::Vector2f position) {
	this->position = position;
}

void Body::setColor(sf::Color color) {
	this->color = color;
}

void Body::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
	
}

void Body::draw(sf::RenderTarget& target) const 
{

}

void Body::update() { }
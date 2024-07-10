#include "Body.h"

Body::Body() 
{
	this->position = { 0.f, 0.f };
}

Body::Body(sf::Vector2f position) 
{
	this->position = position;
}

Body::~Body() {}

sf::Vector2f Body::getPosition()
{
	return this->position;
}

void Body::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
	
}

void Body::draw(sf::RenderTarget& target) const 
{

}

void Body::update() { }
#include "Body.h"

Body::Body() 
{
	this->position = { 0.f, 0.f };
	this->isControllable = false;
	this->deltaTime = 0.f;
	this->color = sf::Color(255, 255, 255);
}

Body::Body(sf::Vector2f position, bool isControllable, sf::Color color, float mass) 
{
	this->position = position;
	this->isControllable = isControllable;
	this->deltaTime = 0.f;
	this->setColor(color);
	this->setMass(mass);
	this->setVelocity({ 0.f, 0.f });
	this->setAcceleration({ 0.f, 0.f });
	this->setAcceleration(Constants::GRAVITY);
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
	return this->vertices;
}

float Body::getMass() {
	return this->mass;
}

Vector2 Body::getVelocity() {
	return this->velocity;
}

Vector2 Body::getAcceleration() {
	return this->acceleration;
}

void Body::setPosition(sf::Vector2f position) {
	this->position = position;
}

void Body::setColor(sf::Color color) {
	this->color = color;
}

void Body::setMass(float mass) {
	this->mass = mass;
}

void Body::setVelocity(Vector2 velocity) {
	this->velocity = velocity;
}

void Body::setAcceleration(Vector2 acceleration) {
	this->acceleration = acceleration;
}

void Body::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
	
}

void Body::draw(sf::RenderTarget& target) const 
{

}

// Physics Calculations
void Body::calculatePosition() {
	Vector2 position = { this->position.x, this->position.y };
	position += (this->getVelocity() * this->getDeltaTime()) + (this->getAcceleration() * 0.5f * (this->getDeltaTime() * this->getDeltaTime()));
	this->setPosition(Vector2::transformToVector2f(position));
}

void Body::calculateVelocity() {
	Vector2 velocity = this->getVelocity() + this->getAcceleration() * this->getDeltaTime();
	this->setVelocity(velocity);
}

void Body::calculateAcceleration() {

}

void Body::update() { }
#include "Rectangle.h"

Rect::Rect()
{
	this->position = { 0.f, 0.f };
	this->length = 10.f;
	this->width = 10.f;
}

Rect::Rect(sf::Vector2f position, float length, float width) {
	this->position = position;
	this->length = length;
	this->width = width;
}

Rect::Rect(Body& body) {
	this->position = body.getPosition();
	this->length = 10.f;
	this->width = 10.f;
}

Rect::~Rect() {}

sf::Vector2f Rect::getPosition() {
	return this->position;
}

float Rect::getLength() {
	return this->length;
}

float Rect::getWidth() {
	return this->width;
}

float Rect::getMoveSpeed() {
	return this->moveSpeed;
}

void Rect::setPosition(sf::Vector2f position) {
	this->position = position;
}

void Rect::setLength(float length) {
	this->length = length;
}

void Rect::setWidth(float width) {
	this->width = width;
}

void Rect::setMoveSpeed(float moveSpeed) {
	this->moveSpeed = moveSpeed;
}

void Rect::setDeltaTime(float deltaTime) {
	this->deltaTime = deltaTime;
}

void Rect::update() {
	this->calculateDeltaTime();

	float moveSpeed = 50.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		position.x += moveSpeed * deltaTime;
		this->setPosition(position);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		position.x -= moveSpeed * deltaTime;
		this->setPosition(position);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		position.y -= moveSpeed * deltaTime;
		this->setPosition(position);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		position.y += moveSpeed * deltaTime;
		this->setPosition(position);
	}
}

void Rect::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(this->length, this->width));
	rectangle.setFillColor(sf::Color(100, 250, 50));
	rectangle.setPosition(this->position);
	target.draw(rectangle, states);
}

void Rect::draw(sf::RenderTarget& target) const {
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(this->length, this->width));
	rectangle.setFillColor(sf::Color(100, 250, 50));
	rectangle.setPosition(this->position);
	target.draw(rectangle);
}

void Rect::calculateDeltaTime() {
	float deltaTime = this->clock.restart().asSeconds();

	if (deltaTime < Constants::MAX_FRAMES) {
		deltaTime = Constants::MAX_FRAMES;
	}
	else if (deltaTime > Constants::MIN_FRAMES) {
		deltaTime = Constants::MIN_FRAMES;
	}

	this->setDeltaTime(deltaTime);
}
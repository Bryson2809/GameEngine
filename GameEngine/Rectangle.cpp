#include "Rectangle.h"

Rect::Rect() {
	this->position = { 0.f, 0.f };
	this->width= 10.f;
	this->height = 10.f;
	this->deltaTime = 0.f;
	this->moveSpeed = 50.f;
	this->isControllable = false;
	this->vertices = std::vector<Vector2>(4, { 0.f, 0.f });

	this->calculateVertices();
}

Rect::Rect(sf::Vector2f position, float width, float height, float moveSpeed, bool isControllable, sf::Color color, float mass) : Body::Body(position, isControllable, color, mass) {
	this->position = position;
	this->width = width;
	this->height = height;
	this->deltaTime = 0.f;
	this->moveSpeed = moveSpeed;
	this->isControllable = isControllable;
	this->vertices = std::vector<Vector2>(4, { 0.f, 0.f });
	this->color = color;
	this->setMass(mass);
	this->setAcceleration(Constants::GRAVITY);

	this->calculateVertices();
}

Rect::Rect(Body& body) {
	this->position = body.getPosition();
	this->isControllable = body.getIsControllable();
	this->deltaTime = body.getDeltaTime();
	this->width = 10.f;
	this->height = 10.f;
	this->moveSpeed = 50.f;
	this->vertices = std::vector<Vector2>(4, { 0.f, 0.f });

	this->calculateVertices();
}

Rect::~Rect() {}

sf::Vector2f Rect::getPosition() {
	return this->position;
}

float Rect::getWidth() {
	return this->width;
}

float Rect::getHeight() {
	return this->height;
}

float Rect::getMoveSpeed() {
	return this->moveSpeed;
}

float Rect::getDeltaTime() {
	return this->deltaTime;
}

std::vector<Vector2> Rect::getVertices() {
	return this->vertices;
}

float Rect::getMass() {
	return this->mass;
}

Vector2 Rect::getVelocity() {
	return this->velocity;
}

Vector2 Rect::getAcceleration() {
	return this->acceleration;
}

void Rect::setPosition(sf::Vector2f position) {
	__super::setPosition(position);
	this->position = position;
}

void Rect::setWidth(float width) {
	this->width = width;
}

void Rect::setHeight(float height) {
	this->height = height;
}

void Rect::setMoveSpeed(float moveSpeed) {
	this->moveSpeed = moveSpeed;
}

void Rect::setDeltaTime(float deltaTime) {
	this->deltaTime = deltaTime;
}

void Rect::setColor(sf::Color color) {
	this->color = color;
}

void Rect::setMass(float mass) {
	__super::setMass(mass);
	this->mass = mass;
}

void Rect::setVelocity(Vector2 velocity) {
	__super::setVelocity(velocity);
	this->velocity = velocity;
}

void Rect::setAcceleration(Vector2 acceleration) {
	__super::setAcceleration(acceleration);
	this->acceleration = acceleration;
}

void Rect::update() {
	this->calculateDeltaTime();

	if (this->getPosition().y >= 500) {
		this->setVelocity({ 0.f, 0.f });
		this->setAcceleration({ 0.f, 0.f });
	}

	this->calculateVelocity();
	this->calculatePosition();

	if (this->isControllable) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			position.x += this->moveSpeed * deltaTime;
			this->setPosition(position);
			this->calculateVertices();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			position.x -= this->moveSpeed * deltaTime;
			this->setPosition(position);
			this->calculateVertices();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			position.y -= this->moveSpeed * deltaTime;
			this->setPosition(position);
			this->calculateVertices();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			position.y += this->moveSpeed * deltaTime;
			this->setPosition(position);
			this->calculateVertices();
		}
	}
}

void Rect::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(this->width, this->height));
	rectangle.setFillColor(this->color);
	rectangle.setPosition(this->position);
	target.draw(rectangle);
}

void Rect::draw(sf::RenderTarget& target) const {
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(this->width, this->height));
	rectangle.setFillColor(this->color);
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

void Rect::calculateVertices() {
	this->vertices[0] = { this->position.x - (this->width / 2), this->position.y - (this->height / 2) };
	this->vertices[1] = { this->position.x + (this->width / 2), this->position.y - (this->height / 2) };
	this->vertices[2] = { this->position.x + (this->width / 2), this->position.y + (this->height / 2) };
	this->vertices[3] = { this->position.x - (this->width / 2), this->position.y + (this->height / 2) };

	/*for (Vector2 v : vertices) {
		std::cout << v.x << ", " << v.y << std::endl;
	}*/
}

void Rect::calculatePosition() {
	__super::calculatePosition();
	Vector2 position = { this->position.x, this->position.y };
	position += (this->getVelocity() * this->getDeltaTime()) + (this->getAcceleration() * 0.5f * (this->getDeltaTime() * this->getDeltaTime()));
	this->setPosition(Vector2::transformToVector2f(position));
}

void Rect::calculateVelocity() {
	__super::calculateVelocity();
	Vector2 velocity = this->getVelocity() + this->getAcceleration() * this->getDeltaTime();
	this->setVelocity(velocity);
}

void Rect::calculateAcceleration() {
	__super::calculateAcceleration();
}
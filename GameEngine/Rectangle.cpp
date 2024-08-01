#include "Rectangle.h"

sf::Clock timer;
bool timerOn;
bool initialUpdate;

Rect::Rect() {
	this->position = { 0.f, 0.f };
	this->width= 10.f;
	this->height = 10.f;
	this->deltaTime = 0.f;
	this->moveSpeed = 50.f;
	this->isControllable = false;
	this->vertices = std::vector<Vector2>(4, { 0.f, 0.f });
	this->relativeVertices = std::vector<Vector2>(4, { 0.f, 0.f });
	this->color = color;
	this->setMass(mass);
	this->setAcceleration(Constants::GRAVITY);
	this->setRotation(0.f);

	this->calculateRelativeVertices();
	this->calculateVertices();
}

Rect::Rect(sf::Vector2f position, float width, float height, float moveSpeed, bool isControllable, sf::Color color, float mass) : Body::Body(position, isControllable, color, mass) {
	timer.restart();
	timerOn = true;
	initialUpdate = true;

	this->position = position;
	this->width = width;
	this->height = height;
	this->deltaTime = 0.f;
	this->moveSpeed = moveSpeed;
	this->isControllable = isControllable;
	this->vertices = std::vector<Vector2>(4, { 0.f, 0.f });
	this->relativeVertices = std::vector<Vector2>(4, { 0.f, 0.f });
	this->color = color;
	this->setMass(mass);
	this->setVelocity({ 0.f, 0.f });
	this->setAcceleration(Constants::GRAVITY);
	this->setRotation(0.f);

	this->calculateRelativeVertices();
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
	this->relativeVertices = std::vector<Vector2>(4, { 0.f, 0.f });
	this->color = color;
	this->setMass(mass);
	this->setAcceleration(Constants::GRAVITY);
	this->setRotation(body.getRotation());

	this->calculateRelativeVertices();
	this->calculateVertices();
}

Rect::~Rect() {}

sf::Vector2f Rect::getPosition() {
	return this->position;
}

float Rect::getRotation() {
	return this->rotation;
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

std::vector<Vector2> Rect::getRelativeVertices() {
	return this->relativeVertices;
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

void Rect::setRotation(float rotation) {
	__super::setRotation(rotation);
	this->rotation = std::fmod(rotation, 360.f);
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
	if (this->getPosition().y >= 1000) {
		if (timerOn) {
			std::cout << "Time of fall: " << timer.getElapsedTime().asSeconds() << "s" << std::endl;
			std::cout << "Velocity on impact: " << "{ " << this->velocity.x << "m/s, " << this->velocity.y << "m/s }" << std::endl;
			timerOn = false;
		}

		this->setVelocity({ 0.f, 0.f });
		this->setAcceleration({ 0.f, 0.f });
	}

	this->calculateDeltaTime();

	this->calculateVelocity();
	this->calculatePosition();
	this->calculateVertices();

	if (this->isControllable) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			position.x += this->moveSpeed * deltaTime;
			this->setPosition(position);
			this->calculateVertices();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			position.x -= this->moveSpeed * deltaTime;
			this->setPosition(position);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			position.y -= this->moveSpeed * deltaTime;
			this->setPosition(position);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			position.y += this->moveSpeed * deltaTime;
			this->setPosition(position);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			this->setRotation(this->getRotation() + 5.f * this->deltaTime);
			this->calculateVertices();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			this->setRotation(this->getRotation() - 5.f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			std::cout << "Position: { " << this->position.x << ", " << this->position.y << " }" << std::endl;
			std::cout << "sin(" << this->rotation << "): " << Constants::sin(this->rotation) << std::endl;
			std::cout << "cos(" << this->rotation << "): " << Constants::cos(this->rotation) << std::endl;


			for (Vector2 vertex : vertices) {
				std::cout << "{ " << vertex.x << ", " << vertex.y << " }" << std::endl;
			}

			std::cout << std::endl;
		}
	}
}

void Rect::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(this->width, this->height));
	rectangle.setFillColor(this->color);
	rectangle.setOrigin(this->position);
	rectangle.setPosition(this->position);
	rectangle.rotate(this->rotation);
	target.draw(rectangle);
}

void Rect::draw(sf::RenderTarget& target) const {
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(this->width, this->height));
	rectangle.setFillColor(this->color);
	rectangle.setPosition(this->position);
	rectangle.setOrigin(this->width / 2, this->height / 2);
	rectangle.rotate(this->rotation);
	
	target.draw(rectangle);
}

void Rect::calculateDeltaTime() {
	float deltaTime = this->clock.restart().asSeconds();

	/*if (deltaTime < Constants::MAX_FRAMES) {
		deltaTime = Constants::MAX_FRAMES;
	}
	else if (deltaTime > Constants::MIN_FRAMES) {
		deltaTime = Constants::MIN_FRAMES;
	}*/

	this->setDeltaTime(deltaTime);
}

void Rect::calculateVertices() {
	this->vertices[0] = this->calculateRotation(this->getPosition().x - (this->getWidth() / 2), this->getPosition().y - (this->getHeight() / 2), this->relativeVertices[0].x, this->relativeVertices[0].y);

	this->vertices[1] = this->calculateRotation(this->getPosition().x + (this->getWidth() / 2), this->getPosition().y - (this->getHeight() / 2), this->relativeVertices[1].x, this->relativeVertices[1].y);

	this->vertices[2] = this->calculateRotation(this->getPosition().x + (this->getWidth() / 2), this->getPosition().y + (this->getHeight() / 2), this->relativeVertices[2].x, this->relativeVertices[2].y);

	this->vertices[3] = this->calculateRotation(this->getPosition().x - (this->getWidth() / 2), this->getPosition().y + (this->getHeight() / 2), this->relativeVertices[3].x, this->relativeVertices[3].y);

	
}

void Rect::calculateRelativeVertices() {
	this->relativeVertices[0] = { -width / 2, -height / 2 };

	this->relativeVertices[1] = { width / 2, -height / 2 };

	this->relativeVertices[2] = { width / 2, height / 2 };

	this->relativeVertices[3] = { -width / 2, height / 2 };
}

void Rect::calculatePosition() {
	__super::calculatePosition();
}

void Rect::calculateVelocity() {
	__super::calculateVelocity();
}

void Rect::calculateAcceleration() {
	__super::calculateAcceleration();
}

// TODO clean this shit up and put all of this as virtual methods in Body
Vector2 Rect::calculateRotation(float x, float y, float relativeX, float relativeY) {
	x = (relativeX * Constants::cos(this->getRotation()) - (relativeY * Constants::sin(this->getRotation()))) + this->position.x;
	y = (relativeX * Constants::sin(this->getRotation()) + (relativeY * Constants::cos(this->getRotation()))) + this->position.y;

	return { x, y };
}
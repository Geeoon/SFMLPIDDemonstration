#include "Mass.h"

Mass::Mass() {
	shape.setSize(sf::Vector2f(20, 20));
	shape.setFillColor(sf::Color::Red);
	shape.setOrigin(shape.getLocalBounds().width / 2, shape.getLocalBounds().height / 2);
	shape.setPosition(200, yPosition);
	timeSinceLast = std::chrono::system_clock::now().time_since_epoch().count();
	clock.restart();
}

void Mass::applyForce(double force) {
	netForce += force;
}

void Mass::update() {
	elapsedTime = clock.getElapsedTime();
	clock.restart();
	netForce -= mass * g;
	acceleration = mass * netForce * elapsedTime.asSeconds();
	velocity += acceleration * elapsedTime.asSeconds();
	yPosition -= velocity;
	netForce = 0;
	shape.setPosition(200, yPosition);
	timeSinceLast = std::chrono::system_clock::now().time_since_epoch().count();
}

sf::RectangleShape& Mass::getShape() {
	return shape;
}

double Mass::getPosition() {
	return yPosition;
}
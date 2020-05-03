#include "Mass.h"

Mass::Mass() {
	shape.setSize(sf::Vector2f(20, 20));
	shape.setFillColor(sf::Color::Red);
	shape.setPosition(200, yPosition);
}

void Mass::applyForce(double force) {
	netForce += force;
}

void Mass::update() {
	netForce -= mass * g;
	acceleration = mass * netForce;
	velocity += acceleration;
	yPosition -= velocity * 0.00000008;
	netForce = 0;
	shape.setPosition(200, yPosition);
}

sf::RectangleShape& Mass::getShape() {
	return shape;
}

double Mass::getPosition() {
	return yPosition;
}
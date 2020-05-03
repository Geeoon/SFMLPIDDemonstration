#include "PIDController.h"

PIDController::PIDController() {
	targetLine.setSize(sf::Vector2f(100, 2));
	targetLine.setFillColor(sf::Color::Green);
	targetLine.setPosition(200, target);
}

void PIDController::setConstants(double kP, double kI, double kD) {
	kProportional = kP;
	kIntegral = kI;
	kDerivative = kD;
}

void PIDController::setMass(Mass *m) {
	mass = m;
}

void PIDController::setTarget(double y) {
	target = y;
	targetLine.setPosition(200, target);
}

void PIDController::update() {
	force = calcP();
	mass->applyForce(force);
}

double PIDController::calcP() {
	return (mass->getPosition() - target) * kProportional;
}

double PIDController::calcI() {
	return 0;
}

double PIDController::calcD() {
	return 0;
}

sf::RectangleShape& PIDController::getTargetShape() {
	return targetLine;
}
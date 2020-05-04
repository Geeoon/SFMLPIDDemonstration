#include "PIDController.h"

PIDController::PIDController() {
	targetLine.setSize(sf::Vector2f(100, 2));
	targetLine.setFillColor(sf::Color::Green);
	targetLine.setOrigin(targetLine.getLocalBounds().width / 2, targetLine.getLocalBounds().height / 2);
	targetLine.setPosition(200, target);
}

void PIDController::setConstants(double kP, double kI, double kD) {
	kProportional = kP;
	kIntegral = kI;
	kDerivative = kD;
}

void PIDController::setTarget(double y) {
	target = y;
	targetLine.setPosition(200, target);
}

double PIDController::update(double processVar) {
	error = processVar - target;
	force = calcP();
	return force;
}

double PIDController::calcP() {
	return error * kProportional;
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
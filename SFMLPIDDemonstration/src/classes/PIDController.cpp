#include "PIDController.h"

PIDController::PIDController() {
	targetLine.setSize(sf::Vector2f(100, 2));
	targetLine.setFillColor(sf::Color::Green);
	targetLine.setOrigin(targetLine.getLocalBounds().width / 2, targetLine.getLocalBounds().height / 2);
	targetLine.setPosition(200, target);
	previousTime = std::chrono::system_clock::now().time_since_epoch().count();
	clock.restart();
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
	elapsedTime = clock.getElapsedTime();
	clock.restart();
	error = processVar - target;
	dt = elapsedTime.asSeconds();
	errorSum += error * dt;
	errorRate = (error - lastError) / dt;
	lastError = error;
	force = calcP() + calcI() + calcD();
	return force;
}

double PIDController::calcP() {
	return error * kProportional;
}

double PIDController::calcI() {
	return kIntegral * errorSum;
}

double PIDController::calcD() {
	return kDerivative * errorRate;
}

sf::RectangleShape& PIDController::getTargetShape() {
	return targetLine;
}
#include "PIDController.h"

PIDController::PIDController() {

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
}

void PIDController::update() {
	mass->applyForce(force);
}
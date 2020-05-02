#pragma once
#include "Mass.h"

class PIDController
{
public:
	PIDController();
	void setConstants(double kP, double kI, double kD);
	void setMass(Mass *m);
	void setTarget(double y);
	void update();
private:
	Mass *mass;
	double kProportional = 0;
	double kIntegral = 0;
	double kDerivative = 0;
	double target = 0;
	double force = 100;
};
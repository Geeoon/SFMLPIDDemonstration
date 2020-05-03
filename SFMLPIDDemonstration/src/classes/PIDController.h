#pragma once
#include <SFML/Graphics.hpp>
#include "Mass.h"

class PIDController
{
public:
	PIDController();
	void setConstants(double kP, double kI, double kD);
	void setMass(Mass *m);
	void setTarget(double y);
	void update();
	sf::RectangleShape& getTargetShape();
private:
	sf::RectangleShape targetLine;
	Mass *mass;
	double calcP();
	double calcI();
	double calcD();
	double kProportional = 2.5;
	double kIntegral = 0;
	double kDerivative = 0;
	double target = 100;
	double force = 100;
};
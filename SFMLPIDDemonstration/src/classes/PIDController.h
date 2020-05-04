#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>

class PIDController
{
public:
	PIDController();
	void setConstants(double kP, double kI, double kD);
	void setTarget(double y);
	double update(double processVar);
	sf::RectangleShape& getTargetShape();
private:
	sf::RectangleShape targetLine;
	double calcP();
	double calcI();
	double calcD();
	double kProportional = 2;
	double kIntegral = 0;
	double kDerivative = 0;
	double target = 100;
	double force = 100;
	double error = 0;
	double lastError = 0;
	double previousTime = 0;
	double dt = 0;
	double errorSum = 0;
	double errorRate = 0;
};
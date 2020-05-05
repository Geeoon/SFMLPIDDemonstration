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
	sf::Time elapsedTime;
	sf::Clock clock;
	double calcP();
	double calcI();
	double calcD();
	double kProportional = 1;
	double kIntegral = .1;
	double kDerivative = 1;
	double target = 100;
	double force = 0;
	double error = 0;
	double lastError = 0;
	double dt = 0;
	double errorSum = 0;
	double errorRate = 0;
	bool firstLoop = true;
};
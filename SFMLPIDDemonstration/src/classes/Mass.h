#pragma once
#include <SFML/Graphics.hpp>

class Mass
{
public:
	Mass();
	void applyForce(double force);
	void update();
	sf::RectangleShape& getShape();
private:
	sf::RectangleShape shape;
	double yPosition = 200;
	double velocity = 0;
	double acceleration = 0;
	double mass = 10;
	double g = 10;
	double netForce = 0;
};


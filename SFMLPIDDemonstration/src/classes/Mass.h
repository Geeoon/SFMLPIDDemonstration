#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>

class Mass
{
public:
	Mass();
	void applyForce(double force);
	void update();
	double getPosition();
	sf::RectangleShape& getShape();
private:
	sf::RectangleShape shape;
	sf::Clock clock;
	sf::Time elapsedTime;
	double yPosition = 200;
	double velocity = 0;
	double acceleration = 0;
	double mass = 10;
	double g = 10;
	double netForce = 0;
	double timeSinceLast = 0;

};


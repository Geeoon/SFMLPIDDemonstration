#pragma once
#include <SFML/Graphics.hpp>
class UIManager
{
public:
	UIManager();
	sf::RenderWindow& getWindow();
	void pollEvent();
private:
	sf::RenderWindow window;
};
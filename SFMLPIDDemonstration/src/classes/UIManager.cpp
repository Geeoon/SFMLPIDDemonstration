#include "UIManager.h"

UIManager::UIManager() {
	window.create(sf::VideoMode(800, 800), "PID Demonstration", sf::Style::Close);
	window.setFramerateLimit(60);
}

sf::RenderWindow& UIManager::getWindow() {
	return window;
}

void UIManager::pollEvent() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Resized) {
			sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
			window.setView(sf::View(visibleArea));
		}

		if (event.type == sf::Event::Closed) {
			window.close();
		}
	}
}
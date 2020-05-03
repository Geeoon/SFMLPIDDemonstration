#include "Scene.h"

Scene::Scene() {
	pid.setMass(&mass);
}

void Scene::start() {
	while (ui.getWindow().isOpen()) {
		ui.pollEvent();
		ui.getWindow().clear();

		pid.update();
		ui.getWindow().draw(pid.getTargetShape());
		mass.update();
		
		ui.getWindow().draw(mass.getShape());
		
		ui.getWindow().display();
	}
}
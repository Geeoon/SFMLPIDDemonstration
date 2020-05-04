#include "Scene.h"

Scene::Scene() {

}

void Scene::start() {
	while (ui.getWindow().isOpen()) {
		ui.pollEvent();
		ui.getWindow().clear();

		mass.applyForce(pid.update(mass.getPosition()));
		ui.getWindow().draw(pid.getTargetShape());
		mass.update();
		
		ui.getWindow().draw(mass.getShape());
		
		ui.getWindow().display();
	}
}
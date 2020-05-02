#include "Scene.h"

Scene::Scene() {

}

void Scene::start() {
	while (ui.getWindow().isOpen()) {
		ui.pollEvent();
		ui.getWindow().clear();
		mass.update();
		mass.applyForce(10);
		ui.getWindow().draw(mass.getShape());
		
		ui.getWindow().display();
	}
}
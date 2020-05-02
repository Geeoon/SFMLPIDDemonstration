#pragma once
#include "UIManager.h"
#include "Mass.h"

class Scene
{
public:
	Scene();
	void start();
private:
	UIManager ui;
	Mass mass;
};


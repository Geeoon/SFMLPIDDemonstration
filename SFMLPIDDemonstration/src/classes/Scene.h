#pragma once
#include "UIManager.h"
#include "PIDController.h"
#include "Mass.h"

class Scene
{
public:
	Scene();
	void start();
private:
	UIManager ui;
	PIDController pid;
	Mass mass;
};


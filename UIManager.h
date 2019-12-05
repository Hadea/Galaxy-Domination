#pragma once
#include <vector>
#include "Button.h"

/*
  Manages the ui of a scene. Holds all UI elements and handles collisions with mouse
*/

class UIManager
{
public:
	UIManager();
	~UIManager();
	void Update();
	void Draw();


private:
	std::vector<Button> mButtons;
};
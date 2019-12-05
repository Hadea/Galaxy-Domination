#pragma once
#include "src/Enums.h"
/*
	A button for interaction with the game
*/

class Button
{
public:
	Button();
	~Button();
	void Update();
	void Draw();
	ButtonState	mButtonState;

private:
};


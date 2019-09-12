#pragma once
#include <SFML/Graphics.hpp>

struct GameObject
{
	uint16_t WorldPosX;
	uint16_t WorldPosY;
	float Rotation;
	bool Visible;
	sf::Sprite* DrawableObject;
};


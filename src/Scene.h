#pragma once
#include <SFML\Graphics\RenderTexture.hpp>


class IScene
{
public:
	virtual void Update() = 0;
	virtual sf::RenderTexture& Draw() = 0;
};
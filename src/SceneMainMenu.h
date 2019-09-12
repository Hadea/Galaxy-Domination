#pragma once
#include "Scene.h"
#include "GameObject.h"
#include "Engine.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

/* 
Scene for testing
*/
class SceneMainMenu : public IScene
{
	// Inherited via IScene
public:
	SceneMainMenu();
	~SceneMainMenu();
	virtual void Update() override;
	virtual sf::RenderTexture& Draw() override;


private:
	sf::RenderTexture mFrame;
	std::vector<GameObject*> mSprites;
	sf::Sound SoundEffect;
	sf::SoundBuffer SoundBuff;
};


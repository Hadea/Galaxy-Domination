#pragma once
#include "Enums.h"
#include "Defines.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "GameTime.h"
#include "Scene.h"
#include "SceneMainMenu.h"
#include "AssetManager.h"
#include <stack>


class Engine
{
public:
	void HandleEvents();
	void Update();
	void Draw();
	Engine();
	~Engine();
	EngineState EngineStateGet();
	void EngineStateShutdown();
	GameTime Timer;
	void SceneAdd(IScene& pNewScene);
	AssetManager Assets;
	static Engine& GameEngine();
	static Engine* _instance;
	sf::IntRect WindowSizeGet();
private:
	
	sf::RenderWindow mWindow;
	EngineState mEngineState;
	std::stack<IScene*> mSceneAddresses;

};


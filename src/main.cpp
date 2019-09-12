#include <SFML\Graphics.hpp>
#include "Defines.h"
#include "Engine.h"

int main()
{
	Engine* e = &Engine::GameEngine(); // fireing up the engine

	SceneMainMenu* tempScene = new SceneMainMenu(); // loading first scene of the game. 
	e->SceneAdd(*tempScene);
	while (e->EngineStateGet() != Stoping)
	{
		e->HandleEvents();
		e->Update();
		e->Draw();
	}
	delete(e); // kills engine and all remaining scenes and assets
	return 0;
}
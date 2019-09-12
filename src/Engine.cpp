#include "Engine.h"

Engine* Engine::_instance = nullptr;

Engine::Engine()
{
	mEngineState = Starting;
	mWindow.create(Res720);
	
	//Initialize memory for game objects on Heap

	mEngineState = Running;

}

void Engine::HandleEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
		if (event.type == sf::Event::Closed)
			mEngineState = Stoping;
}

void Engine::Update()
{
	Timer.Update();
	mSceneAddresses.top()->Update();
}

void Engine::Draw()
{
	mWindow.clear();
	sf::Sprite tempSprite(mSceneAddresses.top()->Draw().getTexture());
	mWindow.draw(tempSprite);

	mWindow.display();
}

Engine::~Engine()
{
	mWindow.close();

	mEngineState = Stopped;
}

void Engine::SceneAdd(IScene& pNewScene)
{
	mSceneAddresses.push(&pNewScene);
}

EngineState Engine::EngineStateGet()
{
	return mEngineState;
}

void Engine::EngineStateShutdown()
{
	mEngineState = Stoping;
}

Engine& Engine::GameEngine()
{
	if (_instance == nullptr)
		_instance = new Engine();
		
	return *_instance;
}

sf::IntRect Engine::WindowSizeGet()
{
	return sf::IntRect(mWindow.getPosition().x, mWindow.getPosition().y,mWindow.getSize().x, mWindow.getSize().y);
}

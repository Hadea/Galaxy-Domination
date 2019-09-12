#include "SceneMainMenu.h"

SceneMainMenu::SceneMainMenu()
{
	// initialization stuff, remember RAII
	mFrame.create(1280, 920);

	Engine* e = &Engine::GameEngine();
	e->Assets.TextureLoad("Earth", ".\\assets\\MainMenu\\Earth.png");
	GameObject* newObject = new GameObject;
	newObject->Rotation = 0;
	newObject->DrawableObject = new sf::Sprite(e->Assets.TextureGet("Earth"));
	sf::Rect tempBounds = newObject->DrawableObject->getLocalBounds();
	newObject->DrawableObject->setOrigin(tempBounds.width * 0.5f, tempBounds.height * 0.5f);
	tempBounds = newObject->DrawableObject->getLocalBounds();
	newObject->WorldPosX = tempBounds.width * 0.5f;
	newObject->WorldPosY = tempBounds.height * 0.5f;
	mSprites.push_back(newObject);

	e->Assets.TextureLoad("MainMenuButton", ".\\assets\\MainMenu\\MainMenuButton.png");
	newObject = new GameObject;
	newObject->Rotation = 0;
	newObject->DrawableObject = new sf::Sprite(e->Assets.TextureGet("MainMenuButton"));
	tempBounds = newObject->DrawableObject->getLocalBounds();
	newObject->DrawableObject->setOrigin(tempBounds.width * 0.5f, tempBounds.height * 0.5f);
	tempBounds = newObject->DrawableObject->getLocalBounds();
	newObject->WorldPosX = Engine::_instance->WindowSizeGet().width *0.75f ;
	newObject->WorldPosY = Engine::_instance->WindowSizeGet().height * 0.5f;
	mSprites.push_back(newObject);


}

SceneMainMenu::~SceneMainMenu()
{
	for (GameObject* object : mSprites)
	{
		if (object->DrawableObject != nullptr)
			delete(object->DrawableObject);
		delete(object);
	}
}

void SceneMainMenu::Update()
{
	mSprites[0]->Rotation +=1 * Engine::_instance->Timer.DeltaTime.asSeconds();
	// do something

	sf::FloatRect mMousePos;
	mMousePos.left = sf::Mouse::getPosition().x - Engine::_instance->WindowSizeGet().left;
	mMousePos.top = sf::Mouse::getPosition().y - Engine::_instance->WindowSizeGet().top;
	mMousePos.height = mMousePos.width = 1;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
		mSprites[1]->DrawableObject->getGlobalBounds().intersects(mMousePos))
	{
		Engine::_instance->EngineStateShutdown();

	}
}

sf::RenderTexture& SceneMainMenu::Draw()
{
	mFrame.clear();
	for (GameObject* object : mSprites)
	{
		object->DrawableObject->setPosition(object->WorldPosX,object->WorldPosY);
		object->DrawableObject->setRotation(object->Rotation);

		
		mFrame.draw(*object->DrawableObject);
	}
	mFrame.display();
	return mFrame;
}


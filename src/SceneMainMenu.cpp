#include "SceneMainMenu.h"

SceneMainMenu::SceneMainMenu()
{
	// initialization stuff, remember RAII
	mFrame.create(1280, 920);

	Engine* e = &Engine::GameEngine();
	e->Assets.TextureLoad("Earth", ".\\assets\\__MainMenu\\Earth.png");
	GameObject* newObject = new GameObject;
	newObject->Rotation = 0;
	newObject->DrawableObject = new sf::Sprite(e->Assets.TextureGet("Earth"));
	sf::Rect tempBoundsEarth = newObject->DrawableObject->getLocalBounds();
	newObject->DrawableObject->setOrigin(tempBoundsEarth.width * 0.5f, tempBoundsEarth.height * 0.5f);
	tempBoundsEarth = newObject->DrawableObject->getLocalBounds();
	newObject->WorldPosX = (int16_t)(tempBoundsEarth.width * 0.5f);
	newObject->WorldPosY = (int16_t)(tempBoundsEarth.height * 0.5f);
	mSprites.push_back(newObject);

	e->Assets.TextureLoad("MainMenuButton", ".\\assets\\__MainMenu\\MainMenuButton.png");
	newObject = new GameObject;
	newObject->Rotation = 0;
	newObject->DrawableObject = new sf::Sprite(e->Assets.TextureGet("MainMenuButton"));
	sf::Rect tempBoundsMainMenuButton = newObject->DrawableObject->getLocalBounds();
	newObject->DrawableObject->setOrigin(tempBoundsMainMenuButton.width * 0.5f, tempBoundsMainMenuButton.height * 0.5f);
	tempBoundsMainMenuButton = newObject->DrawableObject->getLocalBounds();
	newObject->WorldPosX = Engine::_instance->WindowSizeGet().width * 0.75f;
	newObject->WorldPosY = Engine::_instance->WindowSizeGet().height * 0.5f;

	mSprites.push_back(newObject);	e->Assets.TextureLoad("MainMenuButton", ".\\assets\\__MainMenu\\MainMenuButton.png");
	newObject = new GameObject;
	newObject->Rotation = 0;
	newObject->DrawableObject = new sf::Sprite(e->Assets.TextureGet("MainMenuButton"));
	sf::Rect tempBoundsAudio = newObject->DrawableObject->getLocalBounds();
	newObject->DrawableObject->setOrigin(tempBoundsAudio.width * 0.5f, tempBoundsAudio.height * 0.5f);
	tempBoundsAudio = newObject->DrawableObject->getLocalBounds();
	newObject->WorldPosX = Engine::_instance->WindowSizeGet().width * 0.75f;
	newObject->WorldPosY = Engine::_instance->WindowSizeGet().height * 0.6f;
	mSprites.push_back(newObject);


	
	//e->Assets.SoundLoad("ButtonClick", ".\\assets\\__MainMenu\\ButtonClickLong.wav");
	
	SoundBuff.loadFromFile(".\\assets\\__MainMenu\\ButtonClickLong.wav");
	SoundEffect.setBuffer(SoundBuff);
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
	mSprites[0]->Rotation += 1 * Engine::_instance->Timer.DeltaTime.asSeconds();
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

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
		mSprites[2]->DrawableObject->getGlobalBounds().intersects(mMousePos))
	{

		sf::SoundSource::Status EffectStatus = SoundEffect.getStatus();
		if (EffectStatus != 2)
		{
			SoundEffect.play();
		}
	}

	if (SoundEffect.getStatus() != 2)
	{
		mSprites[2]->DrawableObject->setColor(sf::Color::White);
	}
	else
	{
		mSprites[2]->DrawableObject->setColor(sf::Color::Red);
	}

}

sf::RenderTexture& SceneMainMenu::Draw()
{
	mFrame.clear();
	for (GameObject* object : mSprites)
	{
		object->DrawableObject->setPosition(object->WorldPosX, object->WorldPosY);
		object->DrawableObject->setRotation(object->Rotation);


		mFrame.draw(*object->DrawableObject);
	}
	mFrame.display();
	return mFrame;
}


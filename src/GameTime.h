#pragma once
#include <SFML/System/Time.hpp>
#include <SFML\System\Clock.hpp>
class GameTime
{
public:
	GameTime();
	void Update();

	sf::Time GameStart;
	sf::Time DeltaTime;
private:
	sf::Clock mClock;
	sf::Time mLastFrame;
};


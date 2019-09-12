#include "GameTime.h"

GameTime::GameTime()
{
	GameStart = mClock.restart();
	mLastFrame = GameStart;
}

void GameTime::Update()
{
	DeltaTime = mClock.getElapsedTime() - mLastFrame;
	mLastFrame = mClock.getElapsedTime();
}

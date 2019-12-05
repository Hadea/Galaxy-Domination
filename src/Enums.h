#pragma once

enum EngineState
{
	Starting,
	Running,
	Stoping,
	Stopped
};

enum class ButtonState
{
	Idle,
	Inactive,
	Hover,
	Focus,
	Clicked
};
#pragma once

#include <sfml\Window\Keyboard.hpp>
#include <sfml\Window\Mouse.hpp>
#include "MapDrawer.h"

#define MapDrwr MapDrawer::getInstance()

class InputManager
{
public:
	static InputManager& getInstance()
	{
		static InputManager instance;
		// Instantiated on first use.
		return instance;
	}

	void InputCycle();

private:
	InputManager();

	// technique of deleting the methods we don't want.
	InputManager(InputManager const&) = delete;
	void operator=(InputManager const&) = delete;
};


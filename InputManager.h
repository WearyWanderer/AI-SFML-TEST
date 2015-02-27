#pragma once

#include <sfml\Window\Keyboard.hpp>
#include <sfml\Window\Mouse.hpp>
#include "MapDrawer.h"
#include "ViewManager.h"

#define MapDrwr MapDrawer::getInstance()
#define ViewMngr ViewManager::getInstance()

class InputManager
{
public:
	static InputManager& getInstance()
	{
		static InputManager instance;
		// Instantiated on first use.
		return instance;
	}

	void InputCycle(sf::RenderWindow* targetWindow);

private:
	InputManager();

	// technique of deleting the methods we don't want.
	InputManager(InputManager const&) = delete;
	void operator=(InputManager const&) = delete;
};


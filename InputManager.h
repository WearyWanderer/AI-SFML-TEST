#pragma once

#include <sfml\Window\Keyboard.hpp>
#include <sfml\Window\Mouse.hpp>
#include "MapDrawer.h"
#include "ViewManager.h"
#include "RTT_Tree.h"

#define MapDrwr MapDrawer::getInstance()
#define ViewMngr ViewManager::getInstance()
#define Tree RTT_Tree::getInstance()

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
	sf::Vector2i lastGoalNode;
private:
	InputManager();

	// technique of deleting the methods we don't want.
	InputManager(InputManager const&) = delete;
	void operator=(InputManager const&) = delete;

	bool leftMouseDown = false;
	bool rightMouseDown = false;
	
};


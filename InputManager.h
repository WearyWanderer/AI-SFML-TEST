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
	inline bool GetMode(){ return inputMode; }
	inline sf::Text GetModeText(){ return firstModeTest; }

	sf::Font defaultFont; //publicly accessible by other systems, i.e state manager, simply left here because it was intially developed here
private:
	InputManager();

	// technique of deleting the methods we don't want.
	InputManager(InputManager const&) = delete;
	void operator=(InputManager const&) = delete;

	bool leftMouseDown = false;
	bool modeToggleDown = false;

	bool inputMode = true; //true is mapping mode, false is pathfinding mode
	
	sf::Text firstModeTest;
};


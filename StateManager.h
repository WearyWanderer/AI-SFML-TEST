#pragma once

#include <iostream>
#include <string>
#include <time.h>
#include <Windows.h>
#include <stdio.h>
#include <SFML/Graphics.hpp>

#include "StateManager.h"
#include "MapLoader.h"
#include "MapDrawer.h"
#include "InputManager.h"
#include "ViewManager.h"
#include "RTT_Tree.h"

#define MapMngr MapLoader::getInstance()
#define MapDrwr MapDrawer::getInstance()
#define InputMngr InputManager::getInstance()
#define ViewMngr ViewManager::getInstance()
#define Tree RTT_Tree::getInstance()

class StateManager
{
public:
	static StateManager& getInstance()
	{
		static StateManager instance;
		// Instantiated on first use.
		return instance;
	}


	inline void SwitchState(int newState){ currentState = newState; }

	inline void SwitchMapSel(int map){ selectedMap += map; }

	inline int GetState(){ return currentState; }

	inline int GetMap(){ return selectedMap; }

	void MainLoop(sf::RenderWindow* window);

	std::vector<std::string> mapList;
private:
	StateManager();

	// technique of deleting the methods we don't want.
	StateManager(StateManager const&) = delete;
	void operator=(StateManager const&) = delete;

	std::string mapLocExt = "\\maps\\*.txt";
	int currentState = 1;

	inline wchar_t *convertCharArrayToLPCWSTR(const char* charArray)
	{
		wchar_t* wString = new wchar_t[4096];
		MultiByteToWideChar(CP_ACP, 0, charArray, -1, wString, 4096);
		return wString;
	}

	sf::Text mapListText;
	sf::Text headerText;
	int selectedMap = 0;
};

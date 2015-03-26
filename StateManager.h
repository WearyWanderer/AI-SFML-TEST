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

enum states
{
	mainMenu = 1,
	mapMode = 2
};

class StateManager
{
public:
	StateManager();
	~StateManager();

	inline void SwitchState(int newState){ currentState = newState; }

	inline int GetState(){ return currentState; }

	void MainLoop(sf::RenderWindow* window);

private:
	std::string mapLocExt = "\\maps\\*.txt";
	int currentState = 1;

	inline wchar_t *convertCharArrayToLPCWSTR(const char* charArray)
	{
		wchar_t* wString = new wchar_t[4096];
		MultiByteToWideChar(CP_ACP, 0, charArray, -1, wString, 4096);
		return wString;
	}

	std::vector<std::string> mapList;
	sf::Text mapListText;
	sf::Text headerText;
	int selectedMap = 0;
};

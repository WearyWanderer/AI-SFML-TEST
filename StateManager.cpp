#include "StateManager.h"

StateManager::StateManager()
{
	mapListText.setFont(InputMngr.defaultFont);
	headerText.setFont(InputMngr.defaultFont);
	headerText.setPosition(110,10);
	headerText.setColor(sf::Color::Cyan);
	headerText.setScale(0.75, 0.75);
	headerText.setString("RRT Pathfinding Algorithm - Andrew Ayre, 2015");

	inst[0] = "Welcome to my RRT Demo!";
	inst[1] = "-Press Up / Down & Enter to cycle and select a map";
	inst[2] = "-Click anywhere on a map to begin generating a RRT Tree [Spacebar to pause/resume]";
	inst[3] = "-Press 'H' to switch between RRT and agent pathfinding, click anywhere to show agent's route";
	inst[4] = "-Press 1,2,3 or 4 to alter zoom level";

	instructionText.setFont(InputMngr.defaultFont);
	instructionText.setColor(sf::Color::Cyan);
	instructionText.setScale(0.4, 0.4);

//below is a quick regioned area where I push the name extensions of all maps in a directory into a vector for later loading
#pragma region MapLoading
	const char* folder = "maps\\*.map";
	WIN32_FIND_DATA file_data;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	if ((hFind = FindFirstFile(convertCharArrayToLPCWSTR(folder), &file_data)) == INVALID_HANDLE_VALUE)
	{
		std::cout << "error\n";
		return;
	}

	//wide char array
	std::wstring ch = file_data.cFileName;

	//A std:string  using the char* constructor.
	std::string ss;
	ss.assign(ch.begin(), ch.end());
	mapList.push_back(ss);
	std::cout << ss << std::endl;

	while (FindNextFile(hFind, &file_data))
	{
		//wide char array
		std::wstring ch = file_data.cFileName;

		//A std:string  using the char* constructor.
		std::string ss;
		ss.assign(ch.begin(), ch.end());
		mapList.push_back(ss);
		std::cout << ss << std::endl;
	}
	FindClose(hFind);
#pragma endregion
}

void StateManager::MainLoop(sf::RenderWindow* window)
{
	window->clear(); //clear the window
	
	switch (currentState)
	{
	case mainMenu:
	{
		window->draw(headerText); //draw the title

		instructionText.setPosition(285, 560);
		instructionText.setString(inst[0]);
		window->draw(instructionText);
		for (unsigned int i = 0; i < 4; i++)
		{
			instructionText.setPosition(80, 580 + (i * 20));
			instructionText.setString(inst[i + 1]);
			window->draw(instructionText);
		}
		for (unsigned int i = 0; i < mapList.size(); i++)
		{
			if (selectedMap == i)
			{
				mapListText.setColor(sf::Color::Red);
				mapListText.setString(mapList[i].substr(0, mapList[i].length() - 4));
				mapListText.setPosition((float)365,(float) 200 + (i * 30));
				window->draw(mapListText);
				mapListText.setColor(sf::Color::White);
			}
			else
			{
				mapListText.setString(mapList[i].substr(0, mapList[i].length() - 4));
				mapListText.setPosition((float)365,(float) 200 + (i * 30));
				window->draw(mapListText);
			}
			
		}

		InputMngr.InputCycle(window, mainMenu); //take in inputs

		break;
	}
	case mapMode:
	{
		MapDrwr.DrawMap(window); //draw the map texture

		InputMngr.InputCycle(window, mapMode); //take in inputs

		if (Tree.IfDrawing())
		{
			Tree.GenerateNode(20);
			Tree.InitTreeTexture(window);
		}

		Tree.DrawTree(window); //draw the tree texture
		window->draw(InputMngr.GetModeText());

		break;
	}
	default:
		break;
	}

	window->display(); //call the display	
}

void StateManager::AILoop(sf::RenderWindow* window)
{
	if (Tree.pathfindingAgent.pathDrawn)
	{
		Tree.pathfindingAgent.ProgressForward();
	}
}
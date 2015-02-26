#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sfml\Graphics.hpp>

class MapDrawer
{
public:
	static MapDrawer& getInstance()
	{
		static MapDrawer instance;
		// Instantiated on first use.
		return instance;
	}

	void DrawMap(sf::RenderWindow* screen, int mapToDraw[], int mapHeight, int mapWidth);

private:
	MapDrawer();

	// technique of deleting the methods we don't want.
	MapDrawer(MapDrawer const&) = delete;
	void operator=(MapDrawer const&) = delete;
};


#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sfml\System\Vector2.hpp>
#include <sfml\Graphics.hpp>
#include "ViewManager.h"

#define ViewMngr ViewManager::getInstance()

enum zoomLevels
{
	Zoomx1 = 1,
	Zoomx2 = 2
};

class MapDrawer
{
public:
	static MapDrawer& getInstance()
	{
		static MapDrawer instance;
		// Instantiated on first use.
		return instance;
	}

	#pragma region DrawingMap
		void DrawMap(sf::RenderWindow* screen, int* mapToDraw, int mapHeight, int mapWidth);
		inline void ToggleRedraw(){ needsRedraw = !needsRedraw; }
		inline bool GetRedrawState(){ return needsRedraw; }
	#pragma endregion

	inline void SetZoom(int zoomToSet){ currentZoom = zoomToSet; }
	float GetZoomValue(int currentZoom);

private:
	MapDrawer();

	// technique of deleting the methods we don't want.
	MapDrawer(MapDrawer const&) = delete;
	void operator=(MapDrawer const&) = delete;

	bool needsRedraw = true;
	int currentZoom = Zoomx1;
};


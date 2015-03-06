#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sfml\System\Vector2.hpp>
#include <sfml\Graphics.hpp>
#include "ViewManager.h"
#include "MapLoader.h"

#define ViewMngr ViewManager::getInstance()

enum zoomLevels
{
	Zoomx1 = 1,
	Zoomx2 = 2,
	Zoomx3 = 3
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
		void MapDrawer::InitMapTexture(sf::RenderWindow* screen, Tile mapToDraw[], int mapHeight, int mapWidth);
		void DrawMap(sf::RenderWindow* screen);
		inline void ToggleRedraw(){ needsRedraw = !needsRedraw; }
		inline bool GetRedrawState(){ return needsRedraw; }
	#pragma endregion

	inline void SetZoom(int zoomToSet){ mapSprite.setScale(zoomToSet, zoomToSet); currentZoom = zoomToSet; }
	inline int GetZoomValue(){ return currentZoom; };

	sf::Sprite mapSprite;
private:
	MapDrawer();

	// technique of deleting the methods we don't want.
	MapDrawer(MapDrawer const&) = delete;
	void operator=(MapDrawer const&) = delete;

	bool needsRedraw = true;
	int currentZoom = Zoomx1;

	sf::Texture texture;
	
};


#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sfml\System\Vector2.hpp>
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

	#pragma region DrawingMap
		void DrawMap(sf::RenderWindow* screen, int mapToDraw[], int mapHeight, int mapWidth);
		inline void ToggleRedraw(){ needsRedraw = !needsRedraw; }
		inline bool GetRedrawState(){ return needsRedraw; }
	#pragma endregion

	void AlterCameraOffset(sf::Vector2i xAndY);
	inline void ResetCameraOffset(){ cameraOffset = sf::Vector2i(0, 0); };

private:
	MapDrawer();

	// technique of deleting the methods we don't want.
	MapDrawer(MapDrawer const&) = delete;
	void operator=(MapDrawer const&) = delete;

	bool needsRedraw = true;
	sf::Vector2i cameraOffset;
};


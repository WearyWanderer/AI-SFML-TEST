#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sfml\System\Vector2.hpp>
#include <sfml\Graphics\Rect.hpp>

//structure of each tile in the isometric grid
struct Tile
{
	int x, y;
	char tileSymbol;

	Tile();
	Tile(int xPos, int yPos, char tileSymbolID) : x(xPos), y(yPos), tileSymbol(tileSymbolID) {}; //constructor

	inline char checkSymbol(){ return tileSymbol; }
	inline sf::Vector2i getPos(){ return sf::Vector2i(x, y); }
};

class MapLoader
{
public:
	static MapLoader& getInstance()
	{
		static MapLoader instance;
		// Instantiated on first use.
		return instance;
	}

	void LoadMap(std::string filepath);
	inline Tile* GetMap(){ return mapArray; }
	inline int GetMapHeight(){ return mapHeight; }
	inline int GetMapWidth(){ return mapWidth; }
	inline sf::IntRect GetMapRect(){ return boundsRect; }

private:
	MapLoader();

	// technique of deleting the methods we don't want.
	MapLoader(MapLoader const&) = delete;
	void operator=(MapLoader const&) = delete;

	Tile mapArray[512*513]; //defaults to a 512x512 map, but this can be reallocated
	int mapWidth;
	int	mapHeight;
	sf::IntRect boundsRect;
};


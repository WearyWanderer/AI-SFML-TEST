#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>


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
	inline std::vector<int> GetMap(){ return mapVector; }
	inline int GetMapHeight(){ return mapHeight; }
	inline int GetMapWidth(){ return mapWidth; }

private:
	MapLoader();

	// technique of deleting the methods we don't want.
	MapLoader(MapLoader const&) = delete;
	void operator=(MapLoader const&) = delete;

	std::vector<int> mapVector;
	int mapWidth;
	int	mapHeight;
};


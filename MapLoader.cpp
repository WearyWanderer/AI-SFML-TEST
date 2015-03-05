#include "MapLoader.h"

Tile::Tile()
{

}

MapLoader::MapLoader()
{

}

void MapLoader::LoadMap(std::string filepath)
{
	std::ifstream mapFile(filepath);
	//Variables
	int mapHeaders = 3; //the amount of lines that need to be parsed as lines first

	for (int i = 0; i <= mapHeaders; i++)
	{
		std::string thisLine;
		getline(mapFile, thisLine);

		if (i == 1)
		{
			thisLine.erase(0, 6);
			mapHeight = std::stoi(thisLine);
		}
		if (i == 2)
		{
			thisLine.erase(0, 6);
			mapWidth = std::stoi(thisLine);
		}
	}

	int arrayStorage = 0;
	for (int y = 0; y < mapHeight; y++)
	{
		for (int x = 0; x < mapWidth; x++)
		{
			char thisTileSymbol;
			mapFile.get(thisTileSymbol);

			if (thisTileSymbol == '\n') //if it is a newline, re-get
				mapFile.get(thisTileSymbol);

			if (x == 511 || y == 511) //if the last tile so must be a border tile
				mapArray[arrayStorage] = Tile(x + 1, y + 1, '@');
			else
				mapArray[arrayStorage] = Tile(x + 1, y + 1, thisTileSymbol);
			
			arrayStorage++;
		}
	}

	boundsRect = sf::IntRect(1, 1, mapWidth, mapHeight);
}




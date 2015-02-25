#include "MapLoader.h"


MapLoader::MapLoader()
{

}

void MapLoader::LoadMap(std::string filepath)
{
	std::ifstream mapFile(filepath);
	//Variables
	int mapHeaders = 4; //the amount of lines that need to be parsed as lines first

	for (int i = 0; i < mapHeaders; i++)
	{
		std::string thisLine;
		getline(mapFile, thisLine);

		if (i == 1)
		{
			thisLine.erase(0, 6);
			mapWidth = std::stoi(thisLine);
		}
		if (i == 2)
		{
			thisLine.erase(0, 6);
			mapHeight = std::stoi(thisLine);
		}
	}

	for (int x = 0; x < mapWidth; x++)
	{
		for (int y = 0; y < mapWidth; y++)
		{
			char thisTileSymbol;
			mapFile.get(thisTileSymbol);

			switch (thisTileSymbol)
			{
			case '@': //terrain out of bounds
			{
				mapVector.push_back(1);
			}
				break;
			case '.': //impassable terrain
			{
				mapVector.push_back(2);
			}
				break;
			case ' ': //area that is moveable
			{
				mapVector.push_back(0);
			}
				break;
			default:
				break;
			}

		}
	}



}
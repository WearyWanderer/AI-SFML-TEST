#include "MapDrawer.h"

MapDrawer::MapDrawer()
{
}

void MapDrawer::InitMapTexture(sf::RenderWindow* screen, Tile mapToDraw[], int mapHeight, int mapWidth)
{
	texture.create(mapWidth, mapHeight);

	sf::Uint8* pixels = new sf::Uint8[mapWidth*mapHeight*4];

	int currentCell = 0;
	int index = 0;
	for (int y = 0; y < mapHeight; y++)
	{
		for (int x = 0; x < mapWidth; x++)
		{
			for (int i = 0; i < 4; i++)
			{
				switch (mapToDraw[currentCell].checkSymbol())
				{
					case 'G':
					case '.': //walkable terrain, draw nothing
					{
						pixels[index] = 0;
					}
						break;
					case '@': //impassable terrain
					case 'O':
					case 'T':
					case 'W':
					{
						switch (i)
						{
							case 0:
								//r
								pixels[index] = 0;
								break;
							case 1:
								//g
								pixels[index] = 0;
								break;
							case 2:
								//b
								pixels[index] = 255;
								break;
							case 3:
								//a
								pixels[index] = 255;
								break;
						}
					}
						break;
					default:
						break;
				}
				index++;
			}
			currentCell++;
		}
	}
	texture.update(pixels);
	texture.setSmooth(true);
	texture.copyToImage().saveToFile("map.png");
	mapSprite.setTexture(texture);
	mapSprite.setPosition(0, 0);
}

void MapDrawer::DrawMap(sf::RenderWindow* screen)
{
	screen->draw(mapSprite);
}
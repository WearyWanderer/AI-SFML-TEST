#include "MapDrawer.h"


MapDrawer::MapDrawer()
{

}

void MapDrawer::DrawMap(sf::RenderWindow* screen, int mapToDraw[], int mapHeight, int mapWidth)
{
	int currentX = 1;
	int currentY = 1;
	int arrayCount = mapHeight * mapWidth;
	sf::CircleShape circle(5,10);
	circle.setFillColor(sf::Color::Blue);
	circle.setPosition(5,5);

	for (int i = 0; i < arrayCount - 1; i++)
	{
		switch (mapToDraw[i])
		{
		case 0: //walkable terrain, draw nothing
			break;
		case 1:
		{
			if (currentX * 5 < 960 && currentY * 5 < 720)
			screen->draw(circle);
		}
			break;
		case 2:
		{

		}
			break;
		default:
			break;
		}

		if (currentX == mapWidth)
		{
			currentX = 1;
			currentY += 1;
			circle.setPosition(5, currentY * 5);
		}
		else
		{
			currentX += 1;
			circle.move(5, 0);
		}

	}

}
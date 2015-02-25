#include "MapDrawer.h"


MapDrawer::MapDrawer()
{

}

void MapDrawer::DrawMap(sf::RenderWindow* screen, std::vector<int> mapToDraw, int mapHeight, int mapWidth)
{
	int currentX = 1;
	int currentY = 1;
	sf::CircleShape circle(5,10);
	circle.setFillColor(sf::Color::Blue);
	circle.setPosition(5,5);
	for each (int i in mapToDraw)
	{
		switch (i)
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
		circle.setPosition(5 * currentX, 5 * currentY);
		if (currentX != 512)
			currentX += 1;
		else
		{
			currentX = 1;
			currentY += 1;
		}

	}

}
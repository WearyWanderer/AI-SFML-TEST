#include "MapDrawer.h"


MapDrawer::MapDrawer()
{
}

void MapDrawer::DrawMap(sf::RenderWindow* screen, int mapToDraw[], int mapHeight, int mapWidth)
{
	if (needsRedraw)
	{
		int currentX = 1;
		int currentY = 1;
		int arrayCount = mapHeight * mapWidth;
		sf::RectangleShape circle(sf::Vector2f(2.5f, 2.5f));
		circle.setFillColor(sf::Color::Blue);
		circle.setPosition(2.5, 2.5);

		for (int i = 0; i < arrayCount; i++)
		{
			if (currentX == mapWidth + 1)
			{
				currentX = 1;
				currentY += 1;
				circle.setPosition(2.5, currentY * 2.5);
			}
			else
			{
				currentX += 1;
				circle.move(2.5, 0);
			}

			if (currentY == mapHeight - 1 || currentX == mapWidth + 1)
			{ 
				if (!ViewMngr.IsInsideView(sf::Vector2f(currentX * 2.5, currentY * 2.5))) // if it's outside of what the current screen's boundaries are, don't bother trying to draw
					screen->draw(circle);
			}
			else
			{
				switch (mapToDraw[i])
				{
				case 0: //walkable terrain, draw nothing
				{

				}
					break;
				case 1:
				{
					if (!ViewMngr.IsInsideView(sf::Vector2f(currentX * 2.5, currentY * 2.5))) // if it's outside of what the current screen's boundaries are, don't bother trying to draw
						screen->draw(circle);
				}
					break;
				default:
					break;
				}
			}
		}
	}
	ToggleRedraw();
}
#include "MapDrawer.h"


MapDrawer::MapDrawer()
{
	cameraOffset = sf::Vector2i(0, 0);
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

		for (int i = 1; i <= arrayCount; i++)
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

			switch (mapToDraw[i])
			{
			case 0: //walkable terrain, draw nothing
			{

			}
				break;
			case 1:
			{
				if (currentX * 2.5 <= 960 && currentY * 2.5 <= 720 * 2.5) // if it's outside of what the current screen's boundaries are, don't bother trying to draw
					screen->draw(circle);
			}
				break;
			default:
				break;
			}
		}
	}
	ToggleRedraw();
}

void MapDrawer::AlterCameraOffset(sf::Vector2i xAndY)
{
	if (cameraOffset.x + xAndY.x >= -555 + (960 / 2.5) && cameraOffset.x + xAndY.x <= 0)
		cameraOffset.x += xAndY.x;

	if (cameraOffset.y + xAndY.y >= -500 && cameraOffset.y + xAndY.y <= 0)
		cameraOffset.y += xAndY.y;
}
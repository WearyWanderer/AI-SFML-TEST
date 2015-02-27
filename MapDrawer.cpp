#include "MapDrawer.h"


MapDrawer::MapDrawer()
{
	cameraOffset = sf::Vector2i(0, 0);
}

void MapDrawer::DrawMap(sf::RenderWindow* screen, int mapToDraw[], int mapHeight, int mapWidth)
{
	if (needsRedraw)
	{
		int currentX = 1 + cameraOffset.x;
		int currentY = 1 + cameraOffset.y;
		int arrayCount = mapHeight * mapWidth;
		sf::RectangleShape circle(sf::Vector2f(2.5f, 2.5f));
		circle.setFillColor(sf::Color::Blue);
		circle.setPosition(5 + (cameraOffset.x * 5), 5 + (cameraOffset.y * 5));

		for (int i = 0; i < arrayCount - 1; i++)
		{
			if (currentX == mapWidth + 1)
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

			switch (mapToDraw[i])
			{
			case 0: //walkable terrain, draw nothing
				break;
			case 1:
			{
				if ((currentX + cameraOffset.x) * 5 < 960 + (cameraOffset.x * 5) && (currentY + cameraOffset.y) * 5 < 720 + (cameraOffset.y * 5))
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
	if (cameraOffset.x + xAndY.x >= -515 + (960 / 5) && cameraOffset.x + xAndY.x <= 0)
		cameraOffset.x += xAndY.x;

	if (cameraOffset.y + xAndY.y >= -500 && cameraOffset.y + xAndY.y <= 0)
		cameraOffset.y += xAndY.y;
}
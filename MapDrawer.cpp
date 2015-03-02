#include "MapDrawer.h"


MapDrawer::MapDrawer()
{
}

void MapDrawer::DrawMap(sf::RenderWindow* screen, Tile mapToDraw[], int mapHeight, int mapWidth)
{
	if (needsRedraw)
	{
		float zoomValue = GetZoomValue(currentZoom);
		int currentX = 1;
		int currentY = 1;
		int arrayCount = mapHeight * mapWidth;
		sf::RectangleShape circle(sf::Vector2f(zoomValue, zoomValue));
		circle.setFillColor(sf::Color::Blue);
		circle.setPosition(zoomValue, zoomValue);

		for (int i = 0; i < arrayCount; i++)
		{
			if (currentX == mapWidth + 1)
			{
				currentX = 1;
				currentY += 1;
				circle.setPosition(zoomValue, currentY * zoomValue);
			}
			else
			{
				currentX += 1;
				circle.move(zoomValue, 0);
			}

			if (currentY == mapHeight - 1 || currentX == mapWidth + 1)
			{ 
				if (!ViewMngr.IsInsideView(sf::Vector2f(currentX * zoomValue, currentY * zoomValue))) // if it's outside of what the current screen's boundaries are, don't bother trying to draw
					screen->draw(circle);
			}
			else
			{
				switch (mapToDraw[i].checkSymbol())
				{
				case 'G':
				case '.': //walkable terrain, draw nothing
				{

				}
					break;
				case '@':
				case 'O':
				{
					if (!ViewMngr.IsInsideView(sf::Vector2f(currentX * zoomValue, currentY * zoomValue))) // if it's outside of what the current screen's boundaries are, don't bother trying to draw
						screen->draw(circle);
				}
					break;
				case 'T':
				{

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

float MapDrawer::GetZoomValue(int currentZoom)
{
	switch (currentZoom)
	{
	case 1:
	{
		return 2.5f;
	}
		break;
	case 2:
	{
		return 1.25f;
	}
		break;
	default:
		break;
	}
}
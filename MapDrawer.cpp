#include "MapDrawer.h"


MapDrawer::MapDrawer()
{
	texture.create(960, 720);
	mapSprite.setTexture(texture);
}

void MapDrawer::InitMapTexture(sf::RenderWindow* screen, Tile mapToDraw[], int mapHeight, int mapWidth)
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
		if (mapToDraw[i].getPos().x == 1 && i != 0)
		{
			currentX = 1;
			currentY += 1;
			circle.setPosition(zoomValue, currentY * zoomValue);
		}
		else
		{
			circle.move(zoomValue, 0);
			currentX += 1;
		}
		switch (mapToDraw[i].checkSymbol())
		{
		case 'G':
		case '.': //walkable terrain, draw nothing
		{

		}
			break;
		case '@': //impassable terrain
		case 'O':
		{
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
	ToggleRedraw();
	texture.update(*screen);
}

void MapDrawer::DrawMap(sf::RenderWindow* screen)
{
		screen->draw(mapSprite);
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
		return 0;
		break;
	}
}
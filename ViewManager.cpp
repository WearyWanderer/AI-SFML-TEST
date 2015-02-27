#include "ViewManager.h"


ViewManager::ViewManager()
{
}

void ViewManager::SetView(sf::FloatRect newView)
{
	mainWindow = sf::View(newView);
}

void ViewManager::AlterView(int x, int y)
{
	mainWindow.move(x, y);
}

bool ViewManager::IsInsideView(sf::Vector2f pixelPos)
{
	if (mainWindow.getViewport().contains(pixelPos))
		return true;
	else
		return false;
}

#pragma once

#include <sfml\Graphics.hpp>

class ViewManager
{
public:
	static ViewManager& getInstance()
	{
		static ViewManager instance;
		// Instantiated on first use.
		return instance;
	}

	inline sf::View GetView(){ return mainWindow; }
	void SetView(sf::FloatRect newView);
	void AlterView(int x, int y);
	bool IsInsideView(sf::Vector2f pixelPos);

private:
	ViewManager();

	// technique of deleting the methods we don't want.
	ViewManager(ViewManager const&) = delete;
	void operator=(ViewManager const&) = delete;

	sf::View mainWindow;
	int scrollSpeed = 4;
};


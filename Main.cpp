#ifdef SFML_STATIC
#pragma comment(lib, "glew.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "jpeg.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")  
#endif // SFML_STATIC

#include <iostream>
#include <string>
#include <time.h>
#include <SFML/Graphics.hpp>

#include "StateManager.h"
#include "MapLoader.h"
#include "MapDrawer.h"
#include "InputManager.h"
#include "ViewManager.h"
#include "RTT_Tree.h"

#define ViewMngr ViewManager::getInstance()
#define Tree RTT_Tree::getInstance()
#define Game StateManager::getInstance()

float getFPS(const sf::Time& time);

int main()
{

	sf::RenderWindow window(sf::VideoMode(960, 720), "AndrewAyre AI Pathfinding Algorithm Test");
	//window.setFramerateLimit(0);
	
	srand((unsigned int)time(NULL));
	sf::Clock FPSClock;
	sf::Clock tickClock;
	float fps = 0;
	float timerCurrent = 0.f;
	float timerTotal = 0.02f;
	ViewMngr.SetView(sf::FloatRect(0, 0, 960, 720));

	window.setView(ViewMngr.GetView());
	Tree.screen = &window;
	
	while (window.isOpen())
	{
		#pragma region windowCloser
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

#pragma region mouseWheelScroll, removed for button zoom
			//if (event.type == sf::Event::MouseWheelMoved)
			//{
			//	if (event.mouseWheel.delta >= 0) //if zooming in
			//	{
			//		MapDrwr.SetZoom(MapDrwr.GetZoomValue() + event.mouseWheel.delta);
			//		Tree.SetZoom(MapDrwr.GetZoomValue() + event.mouseWheel.delta);
			//	}
			//	else //zooming out
			//	{
			//		if (MapDrwr.GetZoomValue() + event.mouseWheel.delta >= 1) //if we aren't zooming past the minimum scale (zoom down to scale 1)
			//		{
			//			MapDrwr.SetZoom(MapDrwr.GetZoomValue() + event.mouseWheel.delta);
			//			Tree.SetZoom(MapDrwr.GetZoomValue() + event.mouseWheel.delta);
			//		}
			//	}
			//}
#pragma endregion

		}
		#pragma endregion

		if (timerCurrent >= timerTotal)
		{
			Game.AILoop(&window);
			timerCurrent -= timerTotal;
#ifdef _DEBUG		
			std::cout << fps << std::endl;
#endif
		}

		Game.MainLoop(&window);
		
		fps = getFPS(FPSClock.restart());
		timerCurrent += tickClock.restart().asSeconds();
	}
	return 0;
}

float getFPS(const sf::Time& time) 
{
	return (1000000.0f / time.asMicroseconds());
}
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

#include "MapLoader.h"
#include "MapDrawer.h"
#include "InputManager.h"
#include "ViewManager.h"
#include "RTT_Tree.h"

#define MapMngr MapLoader::getInstance()
#define MapDrwr MapDrawer::getInstance()
#define InputMngr InputManager::getInstance()
#define ViewMngr ViewManager::getInstance()
#define Tree RTT_Tree::getInstance()

float getFPS(const sf::Time& time);

int main()
{
	sf::RenderWindow window(sf::VideoMode(960, 720), "AndrewAyre AI Pathfinding Algorithm Test");
	//window.setFramerateLimit(0);
	
	//window.setVerticalSyncEnabled(false);

	srand(time(NULL));
	MapMngr.LoadMap("maps/maze1.map"); //load the map
	sf::Clock FPSClock;
	sf::Clock WorldTickClock;

	sf::Clock clock;
	sf::Time elapsed;
	sf::Int32 TicksPerFrame = 0;

	int FPSCounter = 0;

	ViewMngr.SetView(sf::FloatRect(0, 0, 960, 720));

	window.setView(ViewMngr.GetView());

	MapDrwr.InitMapTexture(&window, MapMngr.GetMap(), MapMngr.GetMapHeight(), MapMngr.GetMapWidth()); //create the map into a texture

	while (window.isOpen())
	{
		#pragma region windowCloser
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		#pragma endregion
		
		#pragma region FPSCounter
				//Fixed this
				elapsed = clock.restart();
				TicksPerFrame += elapsed.asMilliseconds();

				if (TicksPerFrame >= 500)
				{
					std::cout << FPSCounter << std::endl;
					FPSCounter = 0;

					TicksPerFrame = 0;
					WorldTickClock.restart();
				}
				FPSCounter++;
		#pragma endregion

	
		InputMngr.InputCycle(&window);
		

		window.clear();
		MapDrwr.DrawMap(&window);
		Tree.DrawTree(&window);
		window.display();
		
		
	}
	return 0;
}

float getFPS(const sf::Time& time)
{
	return (1000000.0f / time.asMicroseconds());
}
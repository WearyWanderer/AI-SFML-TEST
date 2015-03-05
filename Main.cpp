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
	sf::RenderWindow window(sf::VideoMode(960, 720), "AndrewAyre AI Pathfinding Algorithm Test", sf::Style::Close);
	//window.setFramerateLimit(0);
	
	//window.setVerticalSyncEnabled(false);

	srand(time(NULL));
	MapMngr.LoadMap("maps/dungeon2.map"); //load the map
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

		window.clear(); //clear the window
		MapDrwr.DrawMap(&window); //draw the map texture

		if (TicksPerFrame >= 30)
			InputMngr.InputCycle(&window); //take in inputs

		Tree.DrawTree(&window); //draw the tree texture
		window.display(); //call the display
		
		
	}
	return 0;
}
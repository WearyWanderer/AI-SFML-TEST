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
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(960, 720), "AndrewAyre AI Pathfinding Algorithm Test");

	sf::Clock clock;
	float lastTime = 0;


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

		float currentTime = clock.restart().asSeconds();
		float fps = 1.f / currentTime;
		lastTime = currentTime;
		std::cout << fps << std::endl; 

		window.clear();
		window.display();
	}

	return 0;
}
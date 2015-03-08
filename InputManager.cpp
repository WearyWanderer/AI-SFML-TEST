#include "InputManager.h"

InputManager::InputManager()
{
	defaultFont.loadFromFile("fonts/kenvector_future.ttf");
	firstModeTest = sf::Text("RTT-Generation Mode [Press'H' to switch]", defaultFont, 18);
	firstModeTest.setColor(sf::Color::Red);
	firstModeTest.setPosition(250, 650);
}

void InputManager::InputCycle(sf::RenderWindow* targetWindow)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		ViewMngr.AlterView(1, 0);
		targetWindow->setView(ViewMngr.GetView());
		firstModeTest.move(1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		ViewMngr.AlterView(-1, 0);
		targetWindow->setView(ViewMngr.GetView());
		firstModeTest.move(-1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		ViewMngr.AlterView(0, 1);
		targetWindow->setView(ViewMngr.GetView());
		firstModeTest.move(0, 1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		ViewMngr.AlterView(0, -1);
		targetWindow->setView(ViewMngr.GetView());
		firstModeTest.move(0, -1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		ViewMngr.SetView(sf::FloatRect(0, 0, 960, 720));
		targetWindow->setView(ViewMngr.GetView());
		firstModeTest.setPosition(250, 650);
	}

#pragma region zoomControls
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		MapDrwr.SetZoom(Zoomx1);
		Tree.SetZoom(Zoomx1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		MapDrwr.SetZoom(Zoomx2);
		Tree.SetZoom(Zoomx2);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
	{
		MapDrwr.SetZoom(Zoomx3);
		Tree.SetZoom(Zoomx3);
	}
#pragma endregion

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (!leftMouseDown)
		{
			leftMouseDown = true;

			sf::Vector2i mousePos
			(
				(sf::Mouse::getPosition(*targetWindow).x + (targetWindow->getView().getCenter().x - (targetWindow->getView().getSize().x / 2))) / MapDrwr.GetZoomValue(), 
				(sf::Mouse::getPosition(*targetWindow).y + (targetWindow->getView().getCenter().y - (targetWindow->getView().getSize().y / 2))) / MapDrwr.GetZoomValue()
			);

			#ifdef _DEBUG
				std::cout << mousePos.x << " X-Pos" << std::endl;
				std::cout << mousePos.y << " Y-Pos" << std::endl;
			#endif

			Tree.SetNewRoot(sf::Vector2i(mousePos.x, mousePos.y), targetWindow);
		}
	}
	else
	{
		leftMouseDown = false;
	}

	if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		if (!rightMouseDown)
		{
			rightMouseDown = true;

			sf::Vector2i mousePos
				(
				(sf::Mouse::getPosition(*targetWindow).x + (targetWindow->getView().getCenter().x - (targetWindow->getView().getSize().x / 2))) / MapDrwr.GetZoomValue(),
				(sf::Mouse::getPosition(*targetWindow).y + (targetWindow->getView().getCenter().y - (targetWindow->getView().getSize().y / 2))) / MapDrwr.GetZoomValue()
				);

		#ifdef _DEBUG
			std::cout << mousePos.x << " X-Pos" << std::endl;
			std::cout << mousePos.y << " Y-Pos" << std::endl;
		#endif

			Tree.BeginDrawing();
			Tree.GenerateNode(40, mousePos);

			lastGoalNode = mousePos;
			Tree.InitTreeTexture(targetWindow);
		}
	}
	else
	{
		rightMouseDown = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		Tree.StopDrawing();
	}
}
#include "InputManager.h"

InputManager::InputManager()
{

}

void InputManager::InputCycle(sf::RenderWindow* targetWindow)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		//MapDrwr.AlterCameraOffset(sf::Vector2i(-1, 0));
		ViewMngr.AlterView(1, 0);
		targetWindow->setView(ViewMngr.GetView());
		if (!MapDrwr.GetRedrawState())
			MapDrwr.ToggleRedraw();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		//MapDrwr.AlterCameraOffset(sf::Vector2i(1, 0));
		ViewMngr.AlterView(-1, 0);
		targetWindow->setView(ViewMngr.GetView());
		if (!MapDrwr.GetRedrawState())
			MapDrwr.ToggleRedraw();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		//MapDrwr.AlterCameraOffset(sf::Vector2i(0, -1));
		ViewMngr.AlterView(0, 1);
		targetWindow->setView(ViewMngr.GetView());
		if (!MapDrwr.GetRedrawState())
			MapDrwr.ToggleRedraw();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		//MapDrwr.AlterCameraOffset(sf::Vector2i(0, 1));
		ViewMngr.AlterView(0, -1);
		targetWindow->setView(ViewMngr.GetView());
		if (!MapDrwr.GetRedrawState())
			MapDrwr.ToggleRedraw();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		//MapDrwr.ResetCameraOffset();
		ViewMngr.SetView(sf::FloatRect(0, 0, 960, 720));
		targetWindow->setView(ViewMngr.GetView());
		if (!MapDrwr.GetRedrawState())
			MapDrwr.ToggleRedraw();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		//MapDrwr.ResetCameraOffset();
		MapDrwr.SetZoom(1);
		targetWindow->setView(ViewMngr.GetView());
		if (!MapDrwr.GetRedrawState())
			MapDrwr.ToggleRedraw();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		//MapDrwr.ResetCameraOffset();
		MapDrwr.SetZoom(2);
		targetWindow->setView(ViewMngr.GetView());
		if (!MapDrwr.GetRedrawState())
			MapDrwr.ToggleRedraw();
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (!leftMouseDown)
		{
			leftMouseDown = true;
			sf::Vector2i mousePos(sf::Mouse::getPosition(*targetWindow).x, sf::Mouse::getPosition(*targetWindow).y);
			std::cout << mousePos.x << " X-Pos" << std::endl;
			std::cout << mousePos.y << " Y-Pos" << std::endl;
			//std::cout << "Viewport is " <<  << " " <<  << std::endl;
			Tree.SetNewRoot(targetWindow->mapPixelToCoords(sf::Vector2i(mousePos.x / 2.5, mousePos.y / 2.5), ViewMngr.GetView()));
			if (!MapDrwr.GetRedrawState())
				MapDrwr.ToggleRedraw();
		}
	}
	else
	{
		leftMouseDown = false;
	}
}
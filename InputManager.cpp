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

			sf::Vector2i mousePos
			(
				(sf::Mouse::getPosition(*targetWindow).x + (targetWindow->getView().getCenter().x - (targetWindow->getView().getSize().x / 2))) / 2.5, 
				(sf::Mouse::getPosition(*targetWindow).y + (targetWindow->getView().getCenter().y - (targetWindow->getView().getSize().y / 2))) / 2.5
			);

			#ifdef _DEBUG
				std::cout << mousePos.x << " X-Pos" << std::endl;
				std::cout << mousePos.y << " Y-Pos" << std::endl;
			#endif

			Tree.SetNewRoot(sf::Vector2f(mousePos.x, mousePos.y));
			if (!MapDrwr.GetRedrawState())
				MapDrwr.ToggleRedraw();
		}
	}
	else
	{
		leftMouseDown = false;
	}
}
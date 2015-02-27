#include "InputManager.h"

InputManager::InputManager()
{

}

void InputManager::InputCycle(sf::RenderWindow* targetWindow)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		//MapDrwr.AlterCameraOffset(sf::Vector2i(-1, 0));
		ViewMngr.AlterView(2, 0);
		targetWindow->setView(ViewMngr.GetView());
		if (!MapDrwr.GetRedrawState())
			MapDrwr.ToggleRedraw();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		//MapDrwr.AlterCameraOffset(sf::Vector2i(1, 0));
		ViewMngr.AlterView(-2, 0);
		targetWindow->setView(ViewMngr.GetView());
		if (!MapDrwr.GetRedrawState())
			MapDrwr.ToggleRedraw();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		//MapDrwr.AlterCameraOffset(sf::Vector2i(0, -1));
		ViewMngr.AlterView(0, 2);
		targetWindow->setView(ViewMngr.GetView());
		if (!MapDrwr.GetRedrawState())
			MapDrwr.ToggleRedraw();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		//MapDrwr.AlterCameraOffset(sf::Vector2i(0, 1));
		ViewMngr.AlterView(0, -2);
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
}
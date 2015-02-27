#include "InputManager.h"

InputManager::InputManager()
{

}

void InputManager::InputCycle()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		MapDrwr.AlterCameraOffset(sf::Vector2i(-1, 0));
		if (!MapDrwr.GetRedrawState())
			MapDrwr.ToggleRedraw();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		MapDrwr.AlterCameraOffset(sf::Vector2i(1, 0));
		if (!MapDrwr.GetRedrawState())
			MapDrwr.ToggleRedraw();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		MapDrwr.AlterCameraOffset(sf::Vector2i(0, -1));
		if (!MapDrwr.GetRedrawState())
			MapDrwr.ToggleRedraw();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		MapDrwr.AlterCameraOffset(sf::Vector2i(0, 1));
		if (!MapDrwr.GetRedrawState())
			MapDrwr.ToggleRedraw();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		MapDrwr.ResetCameraOffset();
		if (!MapDrwr.GetRedrawState())
			MapDrwr.ToggleRedraw();
	}
}
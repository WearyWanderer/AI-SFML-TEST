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
		//MapDrwr.mapSprite.move(1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		//MapDrwr.AlterCameraOffset(sf::Vector2i(1, 0));
		ViewMngr.AlterView(-1, 0);
		targetWindow->setView(ViewMngr.GetView());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		//MapDrwr.AlterCameraOffset(sf::Vector2i(0, -1));
		ViewMngr.AlterView(0, 1);
		targetWindow->setView(ViewMngr.GetView());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		//MapDrwr.AlterCameraOffset(sf::Vector2i(0, 1));
		ViewMngr.AlterView(0, -1);
		targetWindow->setView(ViewMngr.GetView());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		//MapDrwr.ResetCameraOffset();
		ViewMngr.SetView(sf::FloatRect(0, 0, 960, 720));
		targetWindow->setView(ViewMngr.GetView());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		//MapDrwr.ResetCameraOffset();
		MapDrwr.SetZoom(Zoomx1);
		Tree.SetZoom(Zoomx1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		//MapDrwr.ResetCameraOffset();
		MapDrwr.SetZoom(Zoomx2);
		Tree.SetZoom(Zoomx2);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
	{
		//MapDrwr.ResetCameraOffset();
		MapDrwr.SetZoom(Zoomx3);
		Tree.SetZoom(Zoomx3);
	}

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
			Tree.GenerateNode(10, mousePos);
			lastGoalNode = mousePos;
			Tree.InitTreeTexture(targetWindow);
		}
	}
	else
	{
		rightMouseDown = false;
	}
}
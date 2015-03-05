#include "RTT_Node.h"

RTT_Node::RTT_Node()
{
}

RTT_Node::RTT_Node(int x, int y)
{
	nodePos = sf::Vector2i(x, y);
}

RTT_Node::~RTT_Node()
{
}

sf::Vector2i RTT_Node::GetNodePos()
{
	return nodePos;
}

bool RTT_Node::SetNodePos(int x, int y, Tile mapInfo[], sf::IntRect boundsRect)
{ 
	if (boundsRect.contains(sf::Vector2i(x,y)))
	{
		int arrayPoint = ((y * MapMngr.GetMapHeight()) + x) - (MapMngr.GetMapWidth() + 1);
		if (mapInfo[arrayPoint].tileSymbol == '@')
		{
			#ifdef _DEBUG
				std::cout << "Hit Collision Wall" << std::endl;
			#endif
			return false;
		}
		else
		{
			nodePos.x = x;
			nodePos.y = y;
			return true;
		}
	}
}

bool RTT_Node::SetNodePos(sf::Vector2i newPos, Tile mapInfo[], sf::IntRect boundsRect)
{ 
	if (boundsRect.contains(newPos))
	{
		int arrayPoint = ((newPos.y * MapMngr.GetMapHeight()) + newPos.x) - (MapMngr.GetMapWidth() + 1);
		if (mapInfo[arrayPoint].tileSymbol == '@')
		{
			#ifdef _DEBUG
				std::cout << mapInfo[arrayPoint].x << std::endl;
				std::cout << mapInfo[arrayPoint].y << std::endl;
				std::cout << "Hit Collision Wall" << std::endl;
				return false;
			#endif
		}
		else
		{
			nodePos = newPos;
			return true;
		}
	}
	else
		return false;
}

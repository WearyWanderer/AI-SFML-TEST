#include "RTT_Node.h"

RTT_Node::RTT_Node()
{
}

RTT_Node::RTT_Node(int x, int y)
{
	nodePos = sf::Vector2f(x, y);
}

RTT_Node::~RTT_Node()
{
}

sf::Vector2f RTT_Node::GetNodePos()
{
	return nodePos;
}

void RTT_Node::SetNodePos(int x, int y, Tile mapInfo[], sf::IntRect boundsRect)
{ 
	if (boundsRect.contains(sf::Vector2i(x,y)))
	{
		int arrayPoint = ((y * 512) + x) - 513;
		if (mapInfo[arrayPoint].tileSymbol == '@')
		{
			std::cout << "Hit Collision Wall" << std::endl;
		}
		else
		{
			nodePos.x = x;
			nodePos.y = y;
		}
	}
}

void RTT_Node::SetNodePos(sf::Vector2f newPos, Tile mapInfo[], sf::IntRect boundsRect)
{ 
	if (boundsRect.contains((sf::Vector2i)newPos))
	{
		int arrayPoint = ((newPos.y * 512) + newPos.x) - 513;
		if (mapInfo[arrayPoint].tileSymbol == '@')
		{
			std::cout << mapInfo[arrayPoint].x << std::endl;
			std::cout << mapInfo[arrayPoint].y << std::endl;
			std::cout << "Hit Collision Wall" << std::endl;
		}
		else
			nodePos = newPos;
	}
}

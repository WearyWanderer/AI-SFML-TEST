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

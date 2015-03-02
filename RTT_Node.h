#pragma once

#include <sfml\System.hpp>
#include <vector>

class RTT_Node
{
public:
	RTT_Node();
	RTT_Node(int x, int y);
	~RTT_Node();

private:

	sf::Vector2i nodePos;
	std::vector<RTT_Node*> adjacentNodes;
};


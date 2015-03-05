#pragma once

#include <sfml\System.hpp>
#include <sfml\Graphics.hpp>
#include <vector>
#include "MapLoader.h"

class RTT_Node
{
public:
	RTT_Node();
	RTT_Node(int x, int y);
	~RTT_Node();

	sf::Vector2f GetNodePos();
	void SetNodePos(int x, int y, Tile mapInfo[]);
	void SetNodePos(sf::Vector2f newPos, Tile mapInfo[]);

private:

	sf::Vector2f nodePos;
	
};


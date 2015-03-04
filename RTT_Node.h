#pragma once

#include <sfml\System.hpp>
#include <sfml\Graphics.hpp>
#include <vector>

class RTT_Node
{
public:
	RTT_Node();
	RTT_Node(int x, int y);
	~RTT_Node();

	sf::Vector2f GetNodePos();
	inline void SetNodePos(int x, int y){ nodePos.x = x; nodePos.y = y; }
	inline void SetNodePos(sf::Vector2f newPos){ nodePos = newPos; }

private:

	sf::Vector2f nodePos;
	
};


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

	void DrawNode();

private:

	sf::Vector2i nodePos;
	sf::RectangleShape nodeShape = sf::RectangleShape(sf::Vector2f(2.5, 2.5));
	std::vector<RTT_Node*> adjacentNodes;
};


#pragma once

#include <sfml\System.hpp>
#include <sfml\Graphics.hpp>
#include <vector>
#include "MapLoader.h"

#define MapMngr MapLoader::getInstance()

class RTT_Node
{
public:
	RTT_Node();
	RTT_Node(int x, int y);
	~RTT_Node();

	sf::Vector2i GetNodePos();
	bool SetNodePos(int x, int y, Tile mapInfo[], sf::IntRect boundsRect);
	bool SetNodePos(sf::Vector2i newPos, Tile mapInfo[], sf::IntRect boundsRect);
	inline bool isTarget(){ return isTargetNode; }
	inline void SetTargetNode(){ isTargetNode = true; }
	inline void SetParent(RTT_Node* parent){ parentNode = parent; }
	inline RTT_Node* GetParent(){ return parentNode; }

#pragma region OverloadForSorting
	bool operator < (const RTT_Node& str) const
	{
		return (nodePos.x < str.nodePos.x);
	}
	bool operator << (const RTT_Node& str) const
	{
		return (nodePos.y < str.nodePos.y);
	}
#pragma endregion

private:

	RTT_Node* parentNode;
	sf::Vector2i nodePos;
	bool isTargetNode = false;
	
};


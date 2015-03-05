#pragma once

#include <vector>
#include <sfml\Graphics.hpp>
#include "RTT_Node.h"
#include "MapLoader.h"

#define MapMngr MapLoader::getInstance()

class RTT_Tree
{
public:
	static RTT_Tree& getInstance()
	{
		static RTT_Tree instance(-100,-100);
		// Instantiated on first use.
		return instance;
	}

	void SetNewRoot(int x, int y);
	void SetNewRoot(sf::Vector2i pos);
	void GenerateNodes(int nodeLength, sf::Vector2i goalNode);
	void DrawTree(sf::RenderWindow* screen);


#pragma region TreeNodeLookup_Lines
	RTT_Node* GetNearestNode(RTT_Node* searchingNode);
	bool BuildLine(RTT_Node* node1, RTT_Node* node2);
#pragma endregion

private:
	RTT_Tree(int rootX, int rootY);

	// technique of deleting the methods we don't want.
	RTT_Tree(RTT_Tree const&) = delete;
	void operator=(RTT_Tree const&) = delete;

	RTT_Node rootNode;
	std::vector<RTT_Node> nodeTree;
	sf::Texture treeTexture;
	sf::Sprite treeSprite;
	
};


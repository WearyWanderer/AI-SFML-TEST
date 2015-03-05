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

	void SetNewRoot(int x, int y, sf::RenderWindow* screen);
	void SetNewRoot(sf::Vector2i pos, sf::RenderWindow* screen);
	void GenerateNodes(int nodeLength, sf::Vector2i goalNode);
	void RTT_Tree::InitTreeTexture(sf::RenderWindow* screen);
	void DrawTree(sf::RenderWindow* screen);


#pragma region TreeNodeLookup_Lines
	bool IfExistingNode(sf::Vector2i position);
	RTT_Node* GetNearestNode(RTT_Node* searchingNode, int maxDistance);
	bool BuildLine(RTT_Node* node1, RTT_Node* node2);
#pragma endregion

private:
	RTT_Tree(int rootX, int rootY);

	// technique of deleting the methods we don't want.
	RTT_Tree(RTT_Tree const&) = delete;
	void operator=(RTT_Tree const&) = delete;

	RTT_Node rootNode;
	std::vector<RTT_Node> nodeTree;
	std::vector<RTT_Node*> potentialNodes; //used in the function of getting the nearest nodes, rather than calling ever frame, just have as a member variable

	sf::Texture treeTexture;
	sf::Sprite treeSprite;
	
};


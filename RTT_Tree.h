#pragma once

#include <vector>
#include <ctime>
#include <sfml\Graphics.hpp>
#include "RTT_Node.h"
#include "MapLoader.h"

#define MapMngr MapLoader::getInstance()

class RTT_Tree
{
public:
	static RTT_Tree& getInstance()
	{
		static RTT_Tree instance(2,2);
		// Instantiated on first use.
		return instance;
	}

	void SetNewRoot(int x, int y, sf::RenderWindow* screen);
	void SetNewRoot(sf::Vector2i pos, sf::RenderWindow* screen);
	void GenerateNode(int nodeLength, sf::Vector2i goalNode);
	void RTT_Tree::GenerateNode(int nodeLength);
	void RTT_Tree::InitTreeTexture(sf::RenderWindow* screen);
	void DrawTree(sf::RenderWindow* screen);
	inline void SetZoom(int zoomToSet){ treeSprite.setScale(zoomToSet, zoomToSet); }

#pragma region TreeNodeLookup_Lines
	bool IfExistingNode(sf::Vector2i position);
	RTT_Node* GetNearestNode(RTT_Node* searchingNode, int maxDistance);
	bool BuildLine(RTT_Node* node1, RTT_Node* node2);
	inline void BeginDrawing(){ continueDrawing = true; targetReached = false; }
	inline bool IfDrawing(){ return continueDrawing; }
	int manhattanDistance(sf::Vector2i pos, sf::Vector2i pos2);
#pragma endregion

	sf::RenderWindow* screen;
private:
	RTT_Tree(int rootX, int rootY);

	// technique of deleting the methods we don't want.
	RTT_Tree(RTT_Tree const&) = delete;
	void operator=(RTT_Tree const&) = delete;

	RTT_Node rootNode;
	RTT_Node previousNode;
	std::vector<RTT_Node> nodeTree;
	std::vector<RTT_Node*> potentialNodes; //used in the function of getting the nearest nodes, rather than calling ever frame, just have as a member variable
	bool targetReached = true;
	bool continueDrawing = false;

	sf::Texture treeTexture;
	sf::Sprite treeSprite;
	
	
};


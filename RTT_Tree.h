#pragma once

#include <vector>
#include <random>
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
	void GenerateNode(int nodeLength, bool withRoot);
	inline std::vector<RTT_Node> GetTree(){ return nodeTree; }
	void GenerateNode(int nodeLength);
	void InitTreeTexture(sf::RenderWindow* screen);
	void DrawTree(sf::RenderWindow* screen);
	inline sf::Sprite GetLineSprite(){ return lineSprite; }
	inline void SetZoom(int zoomToSet){ treeSprite.setScale((float)zoomToSet, (float)zoomToSet); lineSprite.setScale((float)zoomToSet, (float)zoomToSet); pathSprite.setScale((float)zoomToSet, (float)zoomToSet); }

#pragma region TreeNodeLookup_Lines
	bool IfExistingNode(sf::Vector2i position);
	RTT_Node* GetNearestNode(RTT_Node* searchingNode, int maxDistance);
	unsigned int GetNearestNode(sf::Vector2i position, int maxDistance);
	bool BuildLine(RTT_Node* node1, RTT_Node* node2);
	void BuildPath(RTT_Node* destinationNode);
	inline void BeginDrawing(){ continueDrawing = true; targetReached = false; }
	inline void StopDrawing(){ continueDrawing = false; targetReached = false; }
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
	std::vector<RTT_Node> nodeTree;
	bool targetReached = true;
	bool continueDrawing = false;

	sf::Texture treeTexture;
	sf::Sprite treeSprite;
	sf::Texture lineTexture;
	sf::Sprite lineSprite;
	sf::Texture pathTexture;
	sf::Sprite pathSprite;

	sf::Uint8* lineTexturePixels = new sf::Uint8[MapMngr.GetMapWidth() * MapMngr.GetMapHeight() * 4];
	sf::Uint8* pathTexturePixels = new sf::Uint8[MapMngr.GetMapWidth() * MapMngr.GetMapHeight() * 4];
	
	
};


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
		static RTT_Tree instance(2,2);
		// Instantiated on first use.
		return instance;
	}

	void SetNewRoot(int x, int y);
	void SetNewRoot(sf::Vector2f pos);
	void DrawTree(sf::RenderWindow* screen);

private:
	RTT_Tree(int rootX, int rootY);

	// technique of deleting the methods we don't want.
	RTT_Tree(RTT_Tree const&) = delete;
	void operator=(RTT_Tree const&) = delete;

	RTT_Node rootNode;
	
};


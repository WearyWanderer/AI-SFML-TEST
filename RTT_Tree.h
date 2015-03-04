#pragma once

#include <vector>
#include <sfml\Graphics.hpp>
#include "RTT_Node.h"

class RTT_Tree
{
public:
	static RTT_Tree& getInstance()
	{
		static RTT_Tree instance(0,0);
		// Instantiated on first use.
		return instance;
	}

	void SetNewRoot(int x, int y);
	void SetNewRoot(sf::Vector2f pos);

private:
	RTT_Tree(int rootX, int rootY);

	// technique of deleting the methods we don't want.
	RTT_Tree(RTT_Tree const&) = delete;
	void operator=(RTT_Tree const&) = delete;

	RTT_Node rootNode;
	
};


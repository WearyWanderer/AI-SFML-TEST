#pragma once

#include <vector>
#include <sfml\Graphics.hpp>
#include "RTT_Node.h"

class RTT_Tree
{
public:
	RTT_Tree(int rootX, int rootY);
	~RTT_Tree();

private:

	RTT_Node rootNode;
	
};


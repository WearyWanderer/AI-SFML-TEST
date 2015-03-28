#include "RTT_Tree.h"
#include <time.h>


RTT_Tree::RTT_Tree(int rootX, int rootY)
{
	rootNode = RTT_Node(rootX, rootY);
	rootNode.SetParent(0);
}

void RTT_Tree::InitTexts()
{
	treeTexture.create(MapMngr.GetMapWidth(), MapMngr.GetMapHeight());
	lineTexture.create(MapMngr.GetMapWidth(), MapMngr.GetMapHeight());
	pathTexture.create(MapMngr.GetMapWidth(), MapMngr.GetMapHeight());
	lineTexturePixels.resize(MapMngr.GetMapWidth() * MapMngr.GetMapHeight() * 4);
	pathTexturePixels.resize(MapMngr.GetMapWidth() * MapMngr.GetMapHeight() * 4);
}

void RTT_Tree::SetNewRoot(int x, int y, sf::RenderWindow* screen)
{
	rootNode.SetNodePos(sf::Vector2i(x, y), MapMngr.GetMap(), MapMngr.GetMapRect());
	nodeTree.clear(); //empty the old tree
	continueDrawing = false;
	for (int i = 0; i < MapMngr.GetMapWidth() * MapMngr.GetMapHeight() * 4; i++) //clean up the previous texture data
	{
		lineTexturePixels[i] = 0;
	}
	for (int i = 0; i < MapMngr.GetMapWidth() * MapMngr.GetMapHeight() * 4; i++)
	{
		pathTexturePixels[i] = 0;
	}
	lineTexture.update(lineTexturePixels.data());
	pathTexture.update(pathTexturePixels.data());
	InitTreeTexture(screen); //reinitilise the tree screen
}

void RTT_Tree::SetNewRoot(sf::Vector2i pos, sf::RenderWindow* screen)
{
	rootNode.SetNodePos(pos, MapMngr.GetMap(), MapMngr.GetMapRect());
	nodeTree.clear(); //empty the old tree
	continueDrawing = false;
	for (int i = 0; i < MapMngr.GetMapWidth() * MapMngr.GetMapHeight() * 4; i++)
	{
		lineTexturePixels[i] = 0;
	}
	for (int i = 0; i < MapMngr.GetMapWidth() * MapMngr.GetMapHeight() * 4; i++)
	{
		pathTexturePixels[i] = 0;
	}
	lineTexture.update(lineTexturePixels.data());
	pathTexture.update(pathTexturePixels.data());
	InitTreeTexture(screen);
}

void RTT_Tree::GenerateNode(int nodeLength, bool withRoot)
{
	nodeTree.push_back(rootNode); //first node in the list

	std::default_random_engine generator(time(NULL)); //set up random generator for positions
	std::uniform_int_distribution<int> distributionX(1, MapMngr.GetMapWidth());
	std::uniform_int_distribution<int> distributionY(1, MapMngr.GetMapHeight());

	for (int i = 0; i < 20; i++) //seed 20 nodes
	{
		RTT_Node tempNode = RTT_Node();
		sf::Vector2i randomPoint = sf::Vector2i(distributionX(generator), distributionY(generator)); //random point on the map
		if (!IfExistingNode(randomPoint)) //if an existing node is not at this position and it is not the target node
		{
			if (tempNode.SetNodePos(randomPoint, MapMngr.GetMap(), MapMngr.GetMapRect())) //if it's a valid map point
			{
				RTT_Node* nearestNode = GetNearestNode(&tempNode, nodeLength, 3);
				if (nearestNode) //if there is a node within the range of this node
				{
					if (BuildLine(&tempNode, nearestNode))
					{
						tempNode.SetParent(GetNearestNode(tempNode.GetNodePos(), nodeLength, 3));
						nodeTree.push_back(tempNode);
						return;
					}
					else
					{
						i--;
					}
				}
				else
				{
					i--;
				}
			}
			else
			{
				i--;
			}
		}
		else
		{
			i--;
		}
	}

}

void RTT_Tree::GenerateNode(int nodeLength)
{
	std::default_random_engine generator(time(NULL)); //set up random generator for positions
	std::uniform_int_distribution<int> distributionX(1, MapMngr.GetMapWidth());
	std::uniform_int_distribution<int> distributionY(1, MapMngr.GetMapHeight());

	for (int i = 0; i < 20; i++) //seed 20 nodes
	{
		RTT_Node& tempNode = RTT_Node();
		sf::Vector2i randomPoint = sf::Vector2i(distributionX(generator), distributionY(generator)); //random point on the map
		if (!IfExistingNode(randomPoint)) //if an existing node is not at this position and it is not the target node
		{
			if (tempNode.SetNodePos(randomPoint, MapMngr.GetMap(), MapMngr.GetMapRect())) //if it's a valid map point
			{
				RTT_Node* nearestNode = GetNearestNode(&tempNode, nodeLength, 3);
				if (nearestNode) //if there is a node within the range of this node
				{
					if (BuildLine(&tempNode, nearestNode))
					{
						tempNode.SetParent(GetNearestNode(tempNode.GetNodePos(), nodeLength, 3));
						nodeTree.push_back(tempNode);
						return;
					}
					else
					{
						i--;
					}
				}
				else
				{
					i--;
				}
			}
			else
			{
				i--;
			}
		}
		else
		{
			i--;
		}
	}
}

void RTT_Tree::InitTreeTexture(sf::RenderWindow* screen) //add the RTT_Tree to the draw buffer
{
	treeTexture.create(MapMngr.GetMapWidth(), MapMngr.GetMapHeight());

	sf::Uint8* pixels = new sf::Uint8[MapMngr.GetMapWidth() * MapMngr.GetMapHeight() * 4];

	for (int i = 0; i < MapMngr.GetMapWidth() * MapMngr.GetMapHeight() * 4; i++)
	{
		pixels[i] = 0;
	}

	int pixelArrayPos = (((rootNode.GetNodePos().y * MapMngr.GetMapWidth()) + rootNode.GetNodePos().x) * 4);
	pixels[pixelArrayPos] = 0;
	pixels[pixelArrayPos + 1] = 255;
	pixels[pixelArrayPos + 2] = 0;
	pixels[pixelArrayPos + 3] = 255;

	for each (RTT_Node i in nodeTree)
	{
		if (i.isTarget()) // if target draw red
		{
			int pixelArrayPos = (((i.GetNodePos().y * MapMngr.GetMapWidth()) + i.GetNodePos().x) * 4);
			pixels[pixelArrayPos] = 255;
			pixels[pixelArrayPos + 1] = 0;
			pixels[pixelArrayPos + 2] = 0;
			pixels[pixelArrayPos + 3] = 255;
		}
		else
		{
			int pixelArrayPos = (((i.GetNodePos().y * MapMngr.GetMapWidth()) + i.GetNodePos().x) * 4);
			pixels[pixelArrayPos] = 0;
			pixels[pixelArrayPos + 1] = 255;
			pixels[pixelArrayPos + 2] = 0;
			pixels[pixelArrayPos + 3] = 255;
		}
	}

	treeTexture.update(pixels);
	treeSprite.setTexture(treeTexture);
	treeSprite.setPosition(0, 0);

	delete[] pixels;
}

void RTT_Tree::DrawTree(sf::RenderWindow* screen) //add the RTT_Tree to the draw buffer
{
	screen->draw(lineSprite);
	screen->draw(treeSprite);
	screen->draw(pathSprite);
}

bool SortTree(RTT_Node* e1, RTT_Node* e2)
{
	if (e1->GetNodePos().x != e2->GetNodePos().x)
		return (e1->GetNodePos().x < e2->GetNodePos().x);
	return (e1->GetNodePos().y < e2->GetNodePos().y);
}

bool RTT_Tree::IfExistingNode(sf::Vector2i position)
{
	for each (RTT_Node node in nodeTree)
	{
		if (node.GetNodePos().x == position.x && node.GetNodePos().y == position.y)
			return true;
	}
	return false;
}

RTT_Node* RTT_Tree::GetNearestNode(RTT_Node* searchingNode, int maxDistance, int minDist)
{
	RTT_Node* winner = nullptr;
	int manDist = maxDistance;
	for (RTT_Node& node : nodeTree)
	{
		if (manhattanDistance(node.GetNodePos(), searchingNode->GetNodePos()) <= manDist && manhattanDistance(node.GetNodePos(), searchingNode->GetNodePos()) >= minDist)
		{
			manDist = manhattanDistance(node.GetNodePos(), searchingNode->GetNodePos());
			winner = &node;
		}
	}
	return winner;
}

unsigned int RTT_Tree::GetNearestNode(sf::Vector2i position, int maxDistance, int minDist)
{
	unsigned int winnerPos = NULL;
	int manDist = maxDistance;
	for (RTT_Node& node : nodeTree)
	{
		for (unsigned int i = 0; i < nodeTree.size(); i++)
		{
			if (manhattanDistance(nodeTree[i].GetNodePos(), position) <= manDist && manhattanDistance(node.GetNodePos(), position) >= minDist)
			{
				manDist = manhattanDistance(nodeTree[i].GetNodePos(), position);
				winnerPos = i;
			}
		}
	}
	return winnerPos;
}

bool RTT_Tree::BuildLine(RTT_Node* node1, RTT_Node* node2)
{
	sf::Vector2i pos1 = node1->GetNodePos();
	sf::Vector2i pos2 = node2->GetNodePos();

	const sf::Vector2i directionVector = pos2 - pos1;
	const float magnitude =(const float)sqrt((directionVector.y * directionVector.y) + (directionVector.x * directionVector.x));
	const sf::Vector2f unitVector = (sf::Vector2f)directionVector / magnitude;

	for (int i = 0; i < magnitude; i++)
	{
		sf::Vector2i arrayLoc(pos1 + (sf::Vector2i)((float)i * unitVector));
		if (MapMngr.GetMap()[(arrayLoc.y * MapMngr.GetMapWidth()) + arrayLoc.x].checkSymbol() == '@')
		{
			return false;
		}
	}

	for (int i = 0; i < magnitude; i++)
	{
		sf::Vector2i arrayLoc(pos1 + (sf::Vector2i)((float)i * unitVector));
		for (int i = 0; i < 4; i++)
		{
			switch (i)
			{
			case 0:
				//r
				lineTexturePixels[((arrayLoc.y * MapMngr.GetMapWidth()) + arrayLoc.x) * 4 + i] = 255;
				break;
			case 1:
				//g
				lineTexturePixels[((arrayLoc.y * MapMngr.GetMapWidth()) + arrayLoc.x) * 4 + i] = 255;
				break;
			case 2:
				//b
				lineTexturePixels[((arrayLoc.y * MapMngr.GetMapWidth()) + arrayLoc.x) * 4 + i] = 255;
				break;
			case 3:
				//a
				lineTexturePixels[((arrayLoc.y * MapMngr.GetMapWidth()) + arrayLoc.x) * 4 + i] = 255;
				break;
			}
		}
	}

	lineTexture.update(lineTexturePixels.data());
	lineSprite.setTexture(lineTexture);
	return true;
}

void RTT_Tree::BuildPath(RTT_Node* destinationNode)
{
	for (int i = 0; i < MapMngr.GetMapWidth() * MapMngr.GetMapHeight() * 4; i++) //remove existing path
	{
		pathTexturePixels[i] = 0;
	}

	RTT_Node* currentNode = destinationNode;

	while (currentNode->GetNodePos().x != rootNode.GetNodePos().x && currentNode->GetNodePos().y != rootNode.GetNodePos().y) //while we arent drawing to the root node
	{
		sf::Vector2i pos1 = currentNode->GetNodePos();
		sf::Vector2i pos2 = nodeTree[currentNode->GetParent()].GetNodePos();
		const sf::Vector2i directionVector = pos2 - pos1;
		const float magnitude =(const float)sqrt((directionVector.y * directionVector.y) + (directionVector.x * directionVector.x));
		const sf::Vector2f unitVector = (sf::Vector2f)directionVector / magnitude;

		for (int i = 0; i < magnitude; i++)
		{
			sf::Vector2i arrayLoc(pos1 + (sf::Vector2i)((float)i * unitVector));
			for (int i = 0; i < 4; i++)
			{
				switch (i)
				{
				case 0:
					//r
					pathTexturePixels[((arrayLoc.y * MapMngr.GetMapWidth()) + arrayLoc.x) * 4 + i] = 230;
					break;
				case 1:
					//g
					pathTexturePixels[((arrayLoc.y * MapMngr.GetMapWidth()) + arrayLoc.x) * 4 + i] = 145;
					break;
				case 2:
					//b
					pathTexturePixels[((arrayLoc.y * MapMngr.GetMapWidth()) + arrayLoc.x) * 4 + i] = 35;
					break;
				case 3:
					//a
					pathTexturePixels[((arrayLoc.y * MapMngr.GetMapWidth()) + arrayLoc.x) * 4 + i] = 255;
					break;
				}
			}
		}
		currentNode = &nodeTree[currentNode->GetParent()];
	}

	pathTexture.update(pathTexturePixels.data());
	pathSprite.setTexture(pathTexture);
}

int RTT_Tree::manhattanDistance(sf::Vector2i pos, sf::Vector2i pos2)
{
	int x = pos.x - pos2.x;
	int y = pos.y - pos2.y;

	if (x < 0){
		x *= -1;
	}

	if (y < 0){
		y *= -1;
	}

	return x + y;
}


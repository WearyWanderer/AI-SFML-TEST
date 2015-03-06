#include "RTT_Tree.h"


RTT_Tree::RTT_Tree(int rootX, int rootY)
{
	rootNode = RTT_Node(rootX, rootY);
	treeTexture.create(960, 720);
}

void RTT_Tree::SetNewRoot(int x, int y, sf::RenderWindow* screen)
{
	rootNode.SetNodePos(sf::Vector2i(x, y), MapMngr.GetMap(), MapMngr.GetMapRect());
	nodeTree.clear(); //empty the old tree
	InitTreeTexture(screen);
}

void RTT_Tree::SetNewRoot(sf::Vector2i pos, sf::RenderWindow* screen)
{
	rootNode.SetNodePos(pos, MapMngr.GetMap(), MapMngr.GetMapRect());
	nodeTree.clear(); //empty the old tree
	InitTreeTexture(screen);
}

void RTT_Tree::GenerateNode(int nodeLength, sf::Vector2i goalNode)
{
	RTT_Node goalNode_ = RTT_Node(0, 0);
	if (goalNode_.SetNodePos(goalNode, MapMngr.GetMap(), MapMngr.GetMapRect()))
	{
		goalNode_.SetTargetNode();
		nodeTree.push_back(goalNode_); //set this as the target node to reach
		for (int i = 0; i <= 10; i++)
		{
			RTT_Node newNode(0, 0);
			sf::Vector2i randomPoint = sf::Vector2i(rand() % MapMngr.GetMapWidth() + 1, rand() % MapMngr.GetMapHeight() + 1); //random point on the map
			if (!IfExistingNode(randomPoint) || (randomPoint.x == nodeTree[0].GetNodePos().x && randomPoint.y == nodeTree[0].GetNodePos().y)) //if an existing node is not at this position and it is not the target node
			{
				if (newNode.SetNodePos(randomPoint, MapMngr.GetMap(), MapMngr.GetMapRect())) //if it's a valid map point
				{
					RTT_Node* nearestNode = GetNearestNode(&newNode, nodeLength);
					if (nearestNode == nullptr)
					{
						if (randomPoint.x == nodeTree[0].GetNodePos().x && randomPoint.y == nodeTree[0].GetNodePos().y) //if we've hit the target point
						{
							targetReached = true;
							continueDrawing = false;
						}
						else
						{
							nodeTree.push_back(newNode);
							//previousNode = newNode; //make this node become the next node to base the search off
						}
					}
					else
					{
						if (randomPoint.x == nodeTree[0].GetNodePos().x && randomPoint.y == nodeTree[0].GetNodePos().y) //if we've hit the target point
						{
							targetReached = true;
							continueDrawing = false;
						}
						//if (BuildLine(nearestNode, &newNode))
					}
				}
			}
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
	//treeTexture.copyToImage().saveToFile("treeDrawn.png");
	treeSprite.setTexture(treeTexture);
	treeSprite.setPosition(0, 0);
}

void RTT_Tree::DrawTree(sf::RenderWindow* screen) //add the RTT_Tree to the draw buffer
{
	screen->draw(treeSprite);
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

RTT_Node* RTT_Tree::GetNearestNode(RTT_Node* searchingNode, int maxDistance)
{
	potentialNodes.clear(); //empty the old potential nodes
	for each (RTT_Node node in nodeTree)
	{
		if (manhattanDistance(node.GetNodePos(), searchingNode->GetNodePos()) <= maxDistance)
		{
			potentialNodes.push_back(&node); //add to potential nodes
		}
	}
	std::sort(potentialNodes.begin(), potentialNodes.end(), SortTree); //sort the potential nodes into a checkable order
	//std::vector<RTT_Node>::iterator nearestIterator; //create an iterator to retrieve the correct node
	if (!potentialNodes.empty())
	{
		return potentialNodes[0];
	}
	else
		return nullptr;
}

bool RTT_Tree::BuildLine(RTT_Node* node1, RTT_Node* node2)
{
	return true;
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


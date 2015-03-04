#include "RTT_Tree.h"


RTT_Tree::RTT_Tree(int rootX, int rootY)
{
	rootNode = RTT_Node(rootX, rootY);
}

void RTT_Tree::SetNewRoot(int x, int y)
{
	rootNode.SetNodePos(sf::Vector2f(x, y));
}

void RTT_Tree::SetNewRoot(sf::Vector2f pos)
{
	rootNode.SetNodePos(pos);
}

void RTT_Tree::DrawTree(sf::RenderWindow* screen)
{
	sf::RectangleShape nodeShape(sf::Vector2f(3.5f,3.5f));
	nodeShape.setFillColor(sf::Color::Green);

	nodeShape.setPosition(rootNode.GetNodePos().x * 2.5f, rootNode.GetNodePos().y * 2.5f);
	screen->draw(nodeShape);
}

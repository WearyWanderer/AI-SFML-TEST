#include "Agent.hpp"

Agent::Agent()
{
	agentTexture.loadFromFile("tex/Agent.png");
	agentSprite.setTexture(agentTexture);
}


Agent::~Agent()
{
}

void Agent::SetSpriteRelativePos(int x, int y)
{
	int offsetX = (x - 2);
	int offsetY = (y - 2);
	agentSprite.setPosition((float)offsetX * zoomSet,(float) offsetY * zoomSet);
}

void Agent::GenerateStraightPath() //get the line from the current node to the next to follow
{
	currentPathPos.clear();
	for (unsigned int i = 0; i < nodesToFollow.size(); i++) //we loop through the nodes and find the next node we're travelling towards (I know doing this every time is silly, will work upon it after basic concept in place
	{
		if (nodesToFollow[i] == lastNodePos && nodesToFollow[i] != nodesToFollow.back())
		{
			nextNodePos = nodesToFollow[i + 1];
			break;
		}
	}

	sf::Vector2i pos1 = lastNodePos;
	sf::Vector2i pos2 = nextNodePos;
	const sf::Vector2i directionVector = pos2 - pos1;
	const float magnitude = (const float)sqrt((directionVector.y * directionVector.y) + (directionVector.x * directionVector.x));
	const sf::Vector2f unitVector = (sf::Vector2f)directionVector / magnitude;

	for (int i = 0; i <= magnitude; i++)
	{
		sf::Vector2i arrayLoc(pos1 + (sf::Vector2i)((float)i * unitVector));

		currentPathPos.push_back(arrayLoc);
	}

	currentPathPos.push_back(nextNodePos);
	magAlongPath = 0;
}

void Agent::ProgressForward()
{
	magAlongPath++;
	if (magAlongPath > currentPathPos.size() - 1 || (currentPathPos[magAlongPath - 1].x == nextNodePos.x && currentPathPos[magAlongPath - 1].y == nextNodePos.y)) //if we're at the last place, and thus at the final node
	{
		if (nextNodePos != nodesToFollow.back()) //if we aren't at the end of the path
		{
			SetSpriteRelativePos(nextNodePos.x, nextNodePos.y);
			lastNodePos = nextNodePos;
			GenerateStraightPath();
		}
	}
	else
	{
		SetSpriteRelativePos(currentPathPos[magAlongPath - 1].x, currentPathPos[magAlongPath - 1].y);
	}
}
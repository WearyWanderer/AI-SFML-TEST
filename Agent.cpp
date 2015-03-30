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
#pragma once

#include <sfml\Graphics.hpp>

class Agent
{
public:
	Agent();
	~Agent();

	inline void SetZoom(int zoomToSet)
	{
		zoomSet = zoomToSet;
	}
	void SetSpriteRelativePos(int x, int y);

	bool pathDrawn = false;
	sf::Texture agentTexture;
	sf::Sprite agentSprite;

	int zoomSet = 1;
};


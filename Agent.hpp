#pragma once

#include <vector>
#include <sfml\Graphics.hpp>
#include <sfml\System\Vector2.hpp>

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
	void GenerateStraightPath();
	void ProgressForward();

	bool pathDrawn = false;
	sf::Texture agentTexture;
	sf::Sprite agentSprite;

	int zoomSet = 1;
	sf::Vector2i lastNodePos;
	sf::Vector2i nextNodePos;
	float magAlongPath = 0;

	std::vector<sf::Vector2i> nodesToFollow;
	std::vector<sf::Vector2i> currentPathPos;
};


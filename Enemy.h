#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string.h>
#include "Bomb.h"

using namespace sf;

class Enemy
{

public:
	Texture texture;
	Sprite sprite;

	int x, y;

	Enemy()
	{
		x = 340;
		y = 100;

		sprite.setPosition(x, y);
		sprite.setScale(0.5, 0.5);
	}

	virtual void fire(int px) = 0;
};
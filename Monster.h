#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string.h>
#include "Lightning.h"

using namespace sf;

class Monster : public Enemy
{

public:
	bool left, right, moveMonster;

	Lightning *lightning;

	Monster(string img)
	{
		texture.loadFromFile(img);
		sprite.setTexture(texture);

		x = -300;
		y = -800;

		right = true;
		left = false;
		moveMonster = true;

		sprite.setPosition(x, y);
		sprite.setScale(1.2, 1.2);

		lightning = new Lightning(x);
	}

	void fire(int px)
	{
		moveMonster = false;
		lightning->sprite.setPosition(sprite.getPosition().x + 150, 0);
	}

	void move()
	{
		if (sprite.getPosition().x > 550)
		{
			right = false;
			left = true;
		}

		if (sprite.getPosition().x < -285)
		{
			right = true;
			left = false;
		}

		if (right == true && moveMonster == true)
			sprite.move(0.5, 0);

		if (left == true && moveMonster == true)
			sprite.move(-0.5, 0);

		lightning->sprite.setPosition(x, -850);
	}
};
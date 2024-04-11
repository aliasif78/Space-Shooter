#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string.h>
#include "dragonFire.h"

using namespace sf;

class Dragon : public Enemy
{

public:
	dragonFire *dFire;

	Dragon(string img)
	{
		texture.loadFromFile(img);
		sprite.setTexture(texture);

		x = -500;
		y = -800;

		sprite.setPosition(x, y);

		dFire = new dragonFire(0, -800);
	}

	void fire(int px)
	{
		if (px > -100 && px < 220)
			dFire->sprite.setPosition(80, 0);
			
		if (px > 220 && px < 520)
			dFire->sprite.setPosition(340, 0);
			
		if (px > 520 && px < 900)
			dFire->sprite.setPosition(600, 0);
	}
};
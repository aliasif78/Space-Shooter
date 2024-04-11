#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string.h>

using namespace sf;

class Gamma : public Invader
{

public:
	Gamma()
	{
		texture.loadFromFile("img/enemy_2.png");
		sprite.setTexture(texture);

		x = -340;
		y = -100;

		sprite.setPosition(x, y);
		sprite.setScale(0.5, 0.5);

		bomb = new Bomb(x, y);
	}

	void fire(int px)
	{
		bomb->move();
	}

	~Gamma()
	{
		delete bomb;
	}
};
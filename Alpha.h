#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string.h>

using namespace sf;

class Alpha : public Invader
{

public:
	Alpha()
	{
		texture.loadFromFile("img/enemy_3.png");
		sprite.setTexture(texture);

		x = 340;
		y = 100;

		sprite.setPosition(x, y);
		sprite.setScale(0.5, 0.5);

		bomb = new Bomb(x, y);
	}

	void fire(int px)
	{
		bomb->move();
	}

	~Alpha()
	{
		delete bomb;
	}
};
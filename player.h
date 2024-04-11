#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "bullet.h"
#include <string.h>

using namespace sf;
using namespace std;

class Player
{

public:
	Texture tex, tex2, tex3, bTex, fireTex;
	Sprite sprite;

	Bullet *b1;
	Bullet *b2;
	Bullet *b3;
	Bullet *b4;
	Bullet *b5;
	Bullet *b6;

	float speed = 0.3;
	int x, y, lives;

	Player(string img)
	{
		// Max lives are 3
		lives = 3;

		x = 50;
		y = 650;

		tex.loadFromFile(img);
		tex2.loadFromFile("img/pLeftTilt.png");
		tex3.loadFromFile("img/pRightTilt.png");

		fireTex.loadFromFile("img/fireBullet.png");
		bTex.loadFromFile("img/bullet1.png");

		sprite.setTexture(tex);
		sprite.setPosition(x, y);

		b1 = new Bullet(x + 42.5, y);
		b2 = new Bullet(x + 42.5, y);
		b3 = new Bullet(x + 42.5, y);
		b4 = new Bullet(x + 42.5, y);
		b5 = new Bullet(x + 42.5, y);
		b6 = new Bullet(x + 42.5, y);
	}

	void fire(float timer)
	{
		timer -= 0.5;

		if (timer > 5)
			b1->move(sprite.getPosition().x + 42.5, sprite.getPosition().y, timer - 5);

		if (timer > 5.5)
			b2->move(sprite.getPosition().x + 42.5, sprite.getPosition().y, timer - 5.5);

		if (timer > 6)
			b3->move(sprite.getPosition().x + 42.5, sprite.getPosition().y, timer - 6);

		if (timer > 6.5)
			b4->move(sprite.getPosition().x + 42.5, sprite.getPosition().y, timer - 6.5);

		if (timer > 7)
			b5->move(sprite.getPosition().x + 42.5, sprite.getPosition().y, timer - 7);

		if (timer > 7.5)
			b6->move(sprite.getPosition().x + 42.5, sprite.getPosition().y, timer - 7.5);
	}

	void wrapAround()
	{
		if (sprite.getPosition().x < -75)
			sprite.setPosition(780, sprite.getPosition().y);

		if (sprite.getPosition().x > 780)
			sprite.setPosition(-75, sprite.getPosition().y);

		if (sprite.getPosition().y < -75)
			sprite.setPosition(sprite.getPosition().x, 780);

		if (sprite.getPosition().y > 780)
			sprite.setPosition(sprite.getPosition().x, -75);
	}

	void move(string s, bool &fireBulletPNG)
	{
		float delta_x = 0, delta_y = 0;

		if (s == "l")
		{
			sprite.setTexture(tex);
			delta_x = -1;

			if (fireBulletPNG == false)
			{
				b1->sprite.setTexture(bTex);
				b2->sprite.setTexture(bTex);
				b3->sprite.setTexture(bTex);
				b4->sprite.setTexture(bTex);
				b5->sprite.setTexture(bTex);
				b6->sprite.setTexture(bTex);
			}

			else
			{
				b1->sprite.setTexture(fireTex);
				b2->sprite.setTexture(fireTex);
				b3->sprite.setTexture(fireTex);
				b4->sprite.setTexture(fireTex);
				b5->sprite.setTexture(fireTex);
				b6->sprite.setTexture(fireTex);
			}
		}

		if (s == "r")
		{
			sprite.setTexture(tex);
			delta_x = 1;

			if (fireBulletPNG == false)
			{
				b1->sprite.setTexture(bTex);
				b2->sprite.setTexture(bTex);
				b3->sprite.setTexture(bTex);
				b4->sprite.setTexture(bTex);
				b5->sprite.setTexture(bTex);
				b6->sprite.setTexture(bTex);
			}

			else
			{
				b1->sprite.setTexture(fireTex);
				b2->sprite.setTexture(fireTex);
				b3->sprite.setTexture(fireTex);
				b4->sprite.setTexture(fireTex);
				b5->sprite.setTexture(fireTex);
				b6->sprite.setTexture(fireTex);
			}
		}

		if (s == "u")
		{
			sprite.setTexture(tex);
			delta_y = -1;

			if (fireBulletPNG == false)
			{
				b1->sprite.setTexture(bTex);
				b2->sprite.setTexture(bTex);
				b3->sprite.setTexture(bTex);
				b4->sprite.setTexture(bTex);
				b5->sprite.setTexture(bTex);
				b6->sprite.setTexture(bTex);
			}

			else
			{
				b1->sprite.setTexture(fireTex);
				b2->sprite.setTexture(fireTex);
				b3->sprite.setTexture(fireTex);
				b4->sprite.setTexture(fireTex);
				b5->sprite.setTexture(fireTex);
				b6->sprite.setTexture(fireTex);
			}
		}

		if (s == "d")
		{
			sprite.setTexture(tex);
			delta_y = 1;

			if (fireBulletPNG == false)
			{
				b1->sprite.setTexture(bTex);
				b2->sprite.setTexture(bTex);
				b3->sprite.setTexture(bTex);
				b4->sprite.setTexture(bTex);
				b5->sprite.setTexture(bTex);
				b6->sprite.setTexture(bTex);
			}

			else
			{
				b1->sprite.setTexture(fireTex);
				b2->sprite.setTexture(fireTex);
				b3->sprite.setTexture(fireTex);
				b4->sprite.setTexture(fireTex);
				b5->sprite.setTexture(fireTex);
				b6->sprite.setTexture(fireTex);
			}
		}

		if (s == "q")
		{
			sprite.setTexture(tex3);

			if (fireBulletPNG == false)
			{
				b1->sprite.setTexture(bTex);
				b2->sprite.setTexture(bTex);
				b3->sprite.setTexture(bTex);
				b4->sprite.setTexture(bTex);
				b5->sprite.setTexture(bTex);
				b6->sprite.setTexture(bTex);
			}

			else
			{
				b1->sprite.setTexture(fireTex);
				b2->sprite.setTexture(fireTex);
				b3->sprite.setTexture(fireTex);
				b4->sprite.setTexture(fireTex);
				b5->sprite.setTexture(fireTex);
				b6->sprite.setTexture(fireTex);
			}
		}

		if (s == "w")
		{
			sprite.setTexture(tex2);

			if (fireBulletPNG == false)
			{
				b1->sprite.setTexture(bTex);
				b2->sprite.setTexture(bTex);
				b3->sprite.setTexture(bTex);
				b4->sprite.setTexture(bTex);
				b5->sprite.setTexture(bTex);
				b6->sprite.setTexture(bTex);
			}

			else
			{
				b1->sprite.setTexture(fireTex);
				b2->sprite.setTexture(fireTex);
				b3->sprite.setTexture(fireTex);
				b4->sprite.setTexture(fireTex);
				b5->sprite.setTexture(fireTex);
				b6->sprite.setTexture(fireTex);
			}
		}

		if (s == "t")
		{
			sprite.setTexture(tex2);

			if (fireBulletPNG == false)
			{
				b1->sprite.setTexture(bTex);
				b2->sprite.setTexture(bTex);
				b3->sprite.setTexture(bTex);
				b4->sprite.setTexture(bTex);
				b5->sprite.setTexture(bTex);
				b6->sprite.setTexture(bTex);
			}

			else
			{
				b1->sprite.setTexture(fireTex);
				b2->sprite.setTexture(fireTex);
				b3->sprite.setTexture(fireTex);
				b4->sprite.setTexture(fireTex);
				b5->sprite.setTexture(fireTex);
				b6->sprite.setTexture(fireTex);
			}
		}

		if (s == "s")
		{
			sprite.setTexture(tex3);

			if (fireBulletPNG == false)
			{
				b1->sprite.setTexture(bTex);
				b2->sprite.setTexture(bTex);
				b3->sprite.setTexture(bTex);
				b4->sprite.setTexture(bTex);
				b5->sprite.setTexture(bTex);
				b6->sprite.setTexture(bTex);
			}

			else
			{
				b1->sprite.setTexture(fireTex);
				b2->sprite.setTexture(fireTex);
				b3->sprite.setTexture(fireTex);
				b4->sprite.setTexture(fireTex);
				b5->sprite.setTexture(fireTex);
				b6->sprite.setTexture(fireTex);
			}
		}

		delta_x *= speed;
		delta_y *= speed;

		sprite.move(delta_x, delta_y);
		wrapAround();
	}

	void hitLife(int x1, int y1, bool &moveLife, Sound sound)
	{
		if (((sprite.getPosition().y < y1 + 10 && sprite.getPosition().y > y1) || (sprite.getPosition().y + 80 < y1 + 10 && sprite.getPosition().y + 80 > y1)) && ((sprite.getPosition().x > x1 && sprite.getPosition().x < x1 + 70) || (sprite.getPosition().x + 100 > x1 && sprite.getPosition().x + 100 < x1 + 70)) && lives < 3)
		{
			lives++;
			moveLife = false;

			int temp = 1;

			while (true)
			{
				if (temp == 1)
					sound.play();

				temp = 0;

				if (Keyboard::isKeyPressed(Keyboard::Slash))
					break;
			}
		}
	}

	void hitDanger(int x1, int y1, bool &moveDanger, Sound sound, int &Score)
	{
		if (((sprite.getPosition().y < y1 + 10 && sprite.getPosition().y > y1) || (sprite.getPosition().y + 80 < y1 + 10 && sprite.getPosition().y + 80 > y1)) && ((sprite.getPosition().x > x1 && sprite.getPosition().x < x1 + 50) || (sprite.getPosition().x + 100 > x1 && sprite.getPosition().x + 100 < x1 + 50)))
		{
			lives--;
			moveDanger = false;

			sprite.setPosition(340, 650);
			int temp = 1;

			while (true)
			{
				if (temp == 1)
					sound.play();

				temp = 0;

				if (Keyboard::isKeyPressed(Keyboard::Slash))
					break;
			}
		}

		else if (y1 > 779)
			Score += 5;
	}

	void hitFire(int x1, int y1, bool &moveFire, Sound sound, bool &fireBulletPNG, bool &upgradePNG)
	{
		if (((sprite.getPosition().y < y1 + 10 && sprite.getPosition().y > y1) || (sprite.getPosition().y + 80 < y1 + 10 && sprite.getPosition().y + 80 > y1)) && ((sprite.getPosition().x > x1 && sprite.getPosition().x < x1 + 70) || (sprite.getPosition().x + 100 > x1 && sprite.getPosition().x + 100 < x1 + 70)))
		{
			moveFire = false;
			fireBulletPNG = true;
			upgradePNG = false;

			int temp = 1;

			while (true)
			{
				if (temp == 1)
					sound.play();

				temp = 0;

				if (Keyboard::isKeyPressed(Keyboard::Slash))
					break;
			}
		}
	}

	void hitUpgrade(int x1, int y1, bool &moveUpgrade, Sound sound, bool &fireBulletPNG, bool &upgradePNG)
	{
		if (((sprite.getPosition().y < y1 + 10 && sprite.getPosition().y > y1) || (sprite.getPosition().y + 80 < y1 + 10 && sprite.getPosition().y + 80 > y1)) && ((sprite.getPosition().x > x1 && sprite.getPosition().x < x1 + 70) || (sprite.getPosition().x + 100 > x1 && sprite.getPosition().x + 100 < x1 + 70)))
		{
			moveUpgrade = false;
			fireBulletPNG = false;
			upgradePNG = true;

			int temp = 1;

			while (true)
			{
				if (temp == 1)
					sound.play();

				temp = 0;

				if (Keyboard::isKeyPressed(Keyboard::Slash))
					break;
			}
		}
	}

	void hitBomb(int x1, int y1, Sound sound, bool &shoot)
	{
		if (((sprite.getPosition().y < y1 + 10 && sprite.getPosition().y > y1) || (sprite.getPosition().y + 80 < y1 + 10 && sprite.getPosition().y + 80 > y1)) && ((sprite.getPosition().x > x1 && sprite.getPosition().x < x1 + 10) || (sprite.getPosition().x + 100 > x1 && sprite.getPosition().x + 100 < x1 + 1)))
		{
			lives--;
			shoot = false;

			sprite.setPosition(340, 650);
			int temp = 1;

			while (true)
			{
				if (temp == 1)
					sound.play();

				temp = 0;

				if (Keyboard::isKeyPressed(Keyboard::Slash))
					break;
			}
		}
	}

	void hitMonster(int x1, Sound sound, bool &moveMonster, float &second5, int &Score)
	{
		if ((sprite.getPosition().x > x1 + 50 && sprite.getPosition().x < x1 + 140) || (sprite.getPosition().x + 100 > x1 + 50 && sprite.getPosition().x + 100 < x1 + 140))
		{
			lives--;

			sprite.setPosition(340, 650);
			int temp = 1;

			while (true)
			{
				if (temp == 1)
					sound.play();

				temp = 0;

				if (Keyboard::isKeyPressed(Keyboard::Slash))
					break;
			}

			moveMonster = true;
			second5 = 0;
		}

		else if (second5 > 4.999)
			Score += 10;
	}

	void hitDragon(int x1, Sound sound, float &second5, int &Score)
	{
		if ((sprite.getPosition().x > x1 + 30 && sprite.getPosition().x < x1 + 80) || (sprite.getPosition().x + 100 > x1 + 30 && sprite.getPosition().x + 100 < x1 + 80))
		{
			lives--;

			sprite.setPosition(0, 770);
			int temp = 1;

			while (true)
			{
				if (temp == 1)
					sound.play();

				temp = 0;

				if (Keyboard::isKeyPressed(Keyboard::Slash))
					break;
			}

			second5 = 0;
		}

		else if (second5 > 4.999)
			Score += 8;
	}

	~Player()
	{
		delete b1;
		delete b2;
		delete b3;
		delete b4;
		delete b5;
		delete b6;
	}
};
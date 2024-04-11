#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string.h>

using namespace sf;

class Bomb
{

public:
    Texture texture;
    Sprite sprite;

    int x, y, firingNo;
    float speed = 0.4;
    bool shoot;

    Bomb(int ex, int ey)
    {
        texture.loadFromFile("img/bomb.png");
        sprite.setTexture(texture);

        x = ex;
        y = ey + 10;
        firingNo = 0;
        shoot = false;

        sprite.setPosition(x, y + 20);
    }

    void move()
    {
        float delta_y = 1;
        delta_y *= speed;

        sprite.move(0, delta_y);
    }
};
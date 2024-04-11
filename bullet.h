#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string.h>

using namespace sf;

class Bullet
{

public:
    Texture texture;
    Sprite sprite;

    int x, y;
    float speed = 0.275;

    Bullet(int px, int py)
    {
        texture.loadFromFile("img/bullet1.png");
        sprite.setTexture(texture);

        x = px;
        y = py + 10;

        sprite.setPosition(x, y);
    }

    void move(int px, int py, float timer)
    {
        float delta_y = -1;
        delta_y *= speed;

        if (int(timer) % 3 == 1)
            sprite.setPosition(px, py + 10);

        sprite.move(0, delta_y);
    }
};
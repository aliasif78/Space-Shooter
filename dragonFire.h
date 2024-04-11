#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string.h>

using namespace sf;

class dragonFire
{

public:
    Texture texture;
    Sprite sprite;

    int x, y;

    dragonFire(int px, int py)
    {
        texture.loadFromFile("img/dragonFire.png");
        sprite.setTexture(texture);

        x = px;
        y = py;

        sprite.setPosition(x, y);
    }
};
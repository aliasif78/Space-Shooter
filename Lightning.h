#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string.h>

using namespace sf;

class Lightning
{

public:
    Texture texture;
    Sprite sprite;

    int x, y;

    Lightning(int px)
    {
        texture.loadFromFile("img/lightning.png");
        sprite.setTexture(texture);

        x = px;
        y = -800;

        sprite.setPosition(x, y);
    }
};
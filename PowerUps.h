#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string.h>

using namespace sf;

class PowerUps
{

public:

    Sprite sprite;
    Texture texture;

    int x, y, random;
    float speed = 0.5;

    PowerUps()
    {
        x = 100;
        y = 0;
        random = 100;
    }

    virtual void move(bool &) = 0;
};
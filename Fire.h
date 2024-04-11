#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string.h>

using namespace sf;
using namespace std;

class Fire : public PowerUps
{

public:
    Fire(string img)
    {
        texture.loadFromFile(img);
        sprite.setTexture(texture);

        x = 400;
        y = -50;

        sprite.setPosition(x, y);
    }

    void move(bool &moveFire)
    {
        float delta_y = 1;

        delta_y *= speed;
        random += 1;

        if (random > 760)
            random = 5;

        sprite.move(0, delta_y);

        if (sprite.getPosition().y > 780)
        {
            moveFire = false;
            sprite.setPosition(random, -50);
        }
    }
};
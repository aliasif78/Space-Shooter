#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string.h>

using namespace sf;

class Invader : public Enemy
{
public:
    Bomb *bomb;
};
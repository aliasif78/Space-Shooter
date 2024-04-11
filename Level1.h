#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
#include <time.h>
#include <iostream>
#include <cstdlib>

using namespace std;

class Level1
{

public:
    int noEnemies;

    Level1()
    {
        noEnemies = 15;
    }

    void Phase2(Invader *en)
    {
        en[0].sprite.setPosition(360, 100);

        en[1].sprite.setPosition(260, 200);
        en[2].sprite.setPosition(460, 200);

        en[3].sprite.setPosition(160, 300);
        en[4].sprite.setPosition(260, 300);
        en[5].sprite.setPosition(360, 300);
        en[6].sprite.setPosition(460, 300);
        en[7].sprite.setPosition(560, 300);

        en[8].sprite.setPosition(60, 400);
        en[9].sprite.setPosition(160, 400);
        en[10].sprite.setPosition(260, 400);
        en[11].sprite.setPosition(360, 400);
        en[12].sprite.setPosition(460, 400);
        en[13].sprite.setPosition(560, 400);
        en[14].sprite.setPosition(660, 400);
    }

    void Phase3(Invader *en)
    {
        // SETTING ENEMIES
        en[2].sprite.setPosition(660, 50);
        en[3].sprite.setPosition(560, 100);
        en[4].sprite.setPosition(460, 150);

        en[5].sprite.setPosition(260, 250);
        en[6].sprite.setPosition(160, 300);
        en[7].sprite.setPosition(60, 350);

        en[8].sprite.setPosition(60, 50);
        en[9].sprite.setPosition(160, 100);
        en[10].sprite.setPosition(260, 150);

        en[11].sprite.setPosition(360, 200);
        en[0].sprite.setPosition(360, 200);
        en[1].sprite.setPosition(360, 200);

        en[12].sprite.setPosition(460, 250);
        en[13].sprite.setPosition(560, 300);
        en[14].sprite.setPosition(660, 350);
    }

    ~Level1()
    {
    }
};
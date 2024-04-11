#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
#include <time.h>
#include <iostream>
#include <cstdlib>

using namespace std;

#include "player.h"

#include "Enemy.h"
#include "Invader.h"
#include "Alpha.h"
#include "Beta.h"
#include "Gamma.h"
#include "Monster.h"
#include "Dragon.h"

#include "PowerUps.h"
#include "Life.h"
#include "Danger.h"
#include "Fire.h"
#include "Upgrade.h"

#include "Level1.h"

const char title[] = "OOP-Project, Spring-2023";

using namespace sf;

class Game
{

public:
    Sprite background, pauseScreen1, pauseScreen2, pauseScreen3, gameEndIMG, gameWonIMG, lp1IMG, lp1ClearedIMG, lp2IMG, lp2ClearedIMG, lp3IMG, lp3ClearedIMG, life1IMG, life2IMG, life3IMG, monsterIntroIMG, monsterIMG, mIndiIMG, dragonIntroIMG, dragonIMG, dIndiIMG, scoreIndiIMG, timeIndiIMG;
    Texture bg_texture, pauseScreenTex1, pauseScreenTex2, gameEndTex, gameWonTex, lp1Tex, lp1ClearedTex, lp2Tex, lp2ClearedTex, lp3Tex, lp3ClearedTex, life1Tex, life2Tex, life3Tex, monsterIntroTex, monsterTex, mIndiTex, dragonIntroTex, dragonTex, dIndiTex, scoreIndiTex, timeIndiTex;

    Player *p;

    Invader *alpha;
    Invader *beta;
    Invader *gamma;

    Monster *monster;
    Dragon *dragon;

    PowerUps *life;
    PowerUps *danger;
    PowerUps *fire;
    PowerUps *upgrade;

    Level1 *level1;

    Game()
    {
        // Player and Enemies
        p = new Player("img/player_ship2.png");

        alpha = new Alpha[15];
        beta = new Beta[15];
        gamma = new Gamma[15];

        monster = new Monster("img/monsterFace.png");
        dragon = new Dragon("img/dragonFace.png");

        life = new Life("img/healthPack.png");
        danger = new Danger("img/danger.png");
        fire = new Fire("img/fire.png");
        upgrade = new Life("img/powerup.png");

        level1 = new Level1;

        // ASSIGNING VALUES TO BOMBS
        for (int i = 0; i < 15; i++)
            alpha[i].bomb->firingNo = i + 10;

        for (int i = 0; i < 15; i++)
            beta[i].bomb->firingNo = i + 10;

        for (int i = 0; i < 15; i++)
            gamma[i].bomb->firingNo = i + 10;

        // --- IMAGES --- //
        bg_texture.loadFromFile("img/bgA.png");
        background.setTexture(bg_texture);
        background.setPosition(0, -780);

        pauseScreenTex1.loadFromFile("img/pause2.png");
        pauseScreen1.setTexture(pauseScreenTex1);
        pauseScreen1.setPosition(140, 140);

        pauseScreenTex2.loadFromFile("img/pause3.png");
        pauseScreen2.setTexture(pauseScreenTex2);
        pauseScreen2.setPosition(140, 140);

        gameEndTex.loadFromFile("img/gameEnd.png");
        gameEndIMG.setTexture(gameEndTex);
        gameEndIMG.setPosition(140, 140);

        lp1Tex.loadFromFile("img/lp1.png");
        lp1IMG.setTexture(lp1Tex);
        lp1IMG.setPosition(640, 5);
        lp1IMG.setScale(0.25, 0.25);

        lp1ClearedTex.loadFromFile("img/lp1Cleared.png");
        lp1ClearedIMG.setTexture(lp1ClearedTex);
        lp1ClearedIMG.setPosition(140, 140);

        lp2Tex.loadFromFile("img/lp2.png");
        lp2IMG.setTexture(lp2Tex);
        lp2IMG.setPosition(640, 5);
        lp2IMG.setScale(0.25, 0.25);

        lp2ClearedTex.loadFromFile("img/lp2Cleared.png");
        lp2ClearedIMG.setTexture(lp2ClearedTex);
        lp2ClearedIMG.setPosition(140, 140);

        lp3Tex.loadFromFile("img/lp3.png");
        lp3IMG.setTexture(lp3Tex);
        lp3IMG.setPosition(640, 5);
        lp3IMG.setScale(0.25, 0.25);

        mIndiTex.loadFromFile("img/monsterIndi.png");
        mIndiIMG.setTexture(mIndiTex);
        mIndiIMG.setPosition(640, 3);
        mIndiIMG.setScale(0.25, 0.25);

        dIndiTex.loadFromFile("img/dragonIndi.png");
        dIndiIMG.setTexture(dIndiTex);
        dIndiIMG.setPosition(640, 3);
        dIndiIMG.setScale(0.25, 0.25);

        lp3ClearedTex.loadFromFile("img/lp3Cleared.png");
        lp3ClearedIMG.setTexture(lp3ClearedTex);
        lp3ClearedIMG.setPosition(140, 140);

        life1Tex.loadFromFile("img/life1.png");
        life1IMG.setTexture(life1Tex);
        life1IMG.setPosition(640, 60);
        life1IMG.setScale(0.25, 0.3);

        life2Tex.loadFromFile("img/life2.png");
        life2IMG.setTexture(life2Tex);
        life2IMG.setPosition(640, 60);
        life2IMG.setScale(0.25, 0.3);

        life3Tex.loadFromFile("img/life3.png");
        life3IMG.setTexture(life3Tex);
        life3IMG.setPosition(640, 60);
        life3IMG.setScale(0.25, 0.3);

        scoreIndiTex.loadFromFile("img/scoreIndi.png");
        scoreIndiIMG.setTexture(scoreIndiTex);
        scoreIndiIMG.setPosition(640, 100);
        scoreIndiIMG.setScale(0.25, 0.3);

        timeIndiTex.loadFromFile("img/timeIndi.png");
        timeIndiIMG.setTexture(timeIndiTex);
        timeIndiIMG.setPosition(640, 135);
        timeIndiIMG.setScale(0.25, 0.3);

        // MONSTER SCREEN
        monsterIntroTex.loadFromFile("img/monsterScreen.png");
        monsterIntroIMG.setTexture(monsterIntroTex);
        monsterIntroIMG.setPosition(0, 0);

        // DRAGON SCREEN
        dragonIntroTex.loadFromFile("img/dragonIntro.png");
        dragonIntroIMG.setTexture(dragonIntroTex);
        dragonIntroIMG.setPosition(0, 0);

        gameWonTex.loadFromFile("img/gameWon.png");
        gameWonIMG.setTexture(gameWonTex);
        gameWonIMG.setPosition(0, 0);
    }

    void setEnemies(float timer, float second)
    {
        if (timer < 1)
        {
            alpha[0].sprite.setPosition(-100, 350);
            alpha[1].sprite.setPosition(880, 350);
        }

        static int b = 1;

        if (second > 0.5 && b == 1)
        {
            alpha[0].sprite.move(0.4, 0);
            alpha[1].sprite.move(-0.4, 0);

            if (alpha[0].sprite.getPosition().x > alpha[1].sprite.getPosition().x)
                b = 2;
        }

        int ex = 60, ey = 100;
        static int c = 1;

        for (int i = 0; i < 15 && c == 1 && b == 2; i++)
        {
            if (i < 5)
                ex += 100;

            if (i == 5)
            {
                ex = 60;
                ey = 200;
            }

            if (i > 4 && i < 10)
                ex += 100;

            if (i == 10)
            {
                ex = 60;
                ey = 300;
            }

            if (i > 9 && i < 15)
                ex += 100;

            alpha[i].sprite.setPosition(ex, ey);
            alpha[i].bomb->sprite.setPosition(ex + 30, ey + 30);
        }

        if (timer > 5 && timer < 10 && b == 2)
            c = 2;
    }

    void pauseGame(RenderWindow &window, Sound beep, Sound pause)
    {
        int x = 0;

        window.draw(pauseScreen1);
        window.display();

        pause.setPlayingOffset(seconds(0.3));
        pause.play();

        while (true)
        {
            if (Keyboard::isKeyPressed(Keyboard::Up))
            {
                beep.play();
                window.draw(pauseScreen1);
                window.display();

                x = 1;
            }

            if (Keyboard::isKeyPressed(Keyboard::Down))
            {
                beep.play();
                window.draw(pauseScreen2);
                window.display();

                x = 2;
            }

            if (Keyboard::isKeyPressed(Keyboard::Enter) && x == 1)
                break;

            if (Keyboard::isKeyPressed(Keyboard::Enter) && x == 2)
                window.close();
        }
    }

    void hitEnemy(int &x, bool &fireBulletPNG, int &Score)
    {
        // ALPHA
        for (int i = 0; i < 15; i++)
        {
            if (p->b1->sprite.getPosition().y < alpha[i].sprite.getPosition().y + 30 && p->b1->sprite.getPosition().y > alpha[i].sprite.getPosition().y && p->b1->sprite.getPosition().x + 15 >= alpha[i].sprite.getPosition().x && p->b1->sprite.getPosition().x + 3 <= alpha[i].sprite.getPosition().x + 70)
            {
                alpha[i].sprite.setPosition(-200, 0);

                if (fireBulletPNG == false)
                    p->b1->sprite.setPosition(-100, p->b1->sprite.getPosition().y);

                x++;
                Score += 10;
            }

            if (p->b2->sprite.getPosition().y < alpha[i].sprite.getPosition().y + 30 && p->b2->sprite.getPosition().y > alpha[i].sprite.getPosition().y && p->b2->sprite.getPosition().x + 15 >= alpha[i].sprite.getPosition().x && p->b2->sprite.getPosition().x + 3 <= alpha[i].sprite.getPosition().x + 70)
            {
                alpha[i].sprite.setPosition(-200, 0);

                if (fireBulletPNG == false)
                    p->b2->sprite.setPosition(-100, p->b2->sprite.getPosition().y);

                x++;
                Score += 10;
            }

            if (p->b3->sprite.getPosition().y < alpha[i].sprite.getPosition().y + 30 && p->b3->sprite.getPosition().y > alpha[i].sprite.getPosition().y && p->b3->sprite.getPosition().x + 15 >= alpha[i].sprite.getPosition().x && p->b3->sprite.getPosition().x + 3 <= alpha[i].sprite.getPosition().x + 70)
            {
                alpha[i].sprite.setPosition(-200, 0);

                if (fireBulletPNG == false)
                    p->b3->sprite.setPosition(-100, p->b3->sprite.getPosition().y);

                x++;
                Score += 10;
            }

            if (p->b4->sprite.getPosition().y < alpha[i].sprite.getPosition().y + 30 && p->b4->sprite.getPosition().y > alpha[i].sprite.getPosition().y && p->b4->sprite.getPosition().x + 15 >= alpha[i].sprite.getPosition().x && p->b4->sprite.getPosition().x + 3 <= alpha[i].sprite.getPosition().x + 70)
            {
                alpha[i].sprite.setPosition(-200, 0);

                if (fireBulletPNG == false)
                    p->b4->sprite.setPosition(-100, p->b4->sprite.getPosition().y);

                x++;
                Score += 10;
            }

            if (p->b5->sprite.getPosition().y < alpha[i].sprite.getPosition().y + 30 && p->b5->sprite.getPosition().y > alpha[i].sprite.getPosition().y && p->b5->sprite.getPosition().x + 15 >= alpha[i].sprite.getPosition().x && p->b5->sprite.getPosition().x + 3 <= alpha[i].sprite.getPosition().x + 70)
            {
                alpha[i].sprite.setPosition(-200, 0);

                if (fireBulletPNG == false)
                    p->b5->sprite.setPosition(-100, p->b5->sprite.getPosition().y);

                x++;
                Score += 10;
            }

            if (p->b6->sprite.getPosition().y < alpha[i].sprite.getPosition().y + 30 && p->b6->sprite.getPosition().y > alpha[i].sprite.getPosition().y && p->b6->sprite.getPosition().x + 15 >= alpha[i].sprite.getPosition().x && p->b6->sprite.getPosition().x + 3 <= alpha[i].sprite.getPosition().x + 70)
            {
                alpha[i].sprite.setPosition(-200, 0);

                if (fireBulletPNG == false)
                    p->b6->sprite.setPosition(-100, p->b6->sprite.getPosition().y);

                x++;
                Score += 10;
            }
        }

        // BETA
        for (int i = 0; i < 15; i++)
        {
            if (p->b1->sprite.getPosition().y < beta[i].sprite.getPosition().y + 30 && p->b1->sprite.getPosition().y > beta[i].sprite.getPosition().y && p->b1->sprite.getPosition().x + 15 >= beta[i].sprite.getPosition().x && p->b1->sprite.getPosition().x + 3 <= beta[i].sprite.getPosition().x + 70)
            {
                beta[i].sprite.setPosition(-200, 0);

                if (fireBulletPNG == false)
                    p->b1->sprite.setPosition(-100, p->b1->sprite.getPosition().y);

                x++;
                Score += 20;
            }

            if (p->b2->sprite.getPosition().y < beta[i].sprite.getPosition().y + 30 && p->b2->sprite.getPosition().y > beta[i].sprite.getPosition().y && p->b2->sprite.getPosition().x + 15 >= beta[i].sprite.getPosition().x && p->b2->sprite.getPosition().x + 3 <= beta[i].sprite.getPosition().x + 70)
            {
                beta[i].sprite.setPosition(-200, 0);

                if (fireBulletPNG == false)
                    p->b2->sprite.setPosition(-100, p->b2->sprite.getPosition().y);

                x++;
                Score += 20;
            }

            if (p->b3->sprite.getPosition().y < beta[i].sprite.getPosition().y + 30 && p->b3->sprite.getPosition().y > beta[i].sprite.getPosition().y && p->b3->sprite.getPosition().x + 15 >= beta[i].sprite.getPosition().x && p->b3->sprite.getPosition().x + 3 <= beta[i].sprite.getPosition().x + 70)
            {
                beta[i].sprite.setPosition(-200, 0);

                if (fireBulletPNG == false)
                    p->b3->sprite.setPosition(-100, p->b3->sprite.getPosition().y);

                x++;
                Score += 20;
            }

            if (p->b4->sprite.getPosition().y < beta[i].sprite.getPosition().y + 30 && p->b4->sprite.getPosition().y > beta[i].sprite.getPosition().y && p->b4->sprite.getPosition().x + 15 >= beta[i].sprite.getPosition().x && p->b4->sprite.getPosition().x + 3 <= beta[i].sprite.getPosition().x + 70)
            {
                beta[i].sprite.setPosition(-200, 0);

                if (fireBulletPNG == false)
                    p->b4->sprite.setPosition(-100, p->b4->sprite.getPosition().y);

                x++;
                Score += 20;
            }

            if (p->b5->sprite.getPosition().y < beta[i].sprite.getPosition().y + 30 && p->b5->sprite.getPosition().y > beta[i].sprite.getPosition().y && p->b5->sprite.getPosition().x + 15 >= beta[i].sprite.getPosition().x && p->b5->sprite.getPosition().x + 3 <= beta[i].sprite.getPosition().x + 70)
            {
                beta[i].sprite.setPosition(-200, 0);

                if (fireBulletPNG == false)
                    p->b5->sprite.setPosition(-100, p->b5->sprite.getPosition().y);

                x++;
                Score += 20;
            }

            if (p->b6->sprite.getPosition().y < beta[i].sprite.getPosition().y + 30 && p->b6->sprite.getPosition().y > beta[i].sprite.getPosition().y && p->b6->sprite.getPosition().x + 15 >= beta[i].sprite.getPosition().x && p->b6->sprite.getPosition().x + 3 <= beta[i].sprite.getPosition().x + 70)
            {
                beta[i].sprite.setPosition(-200, 0);

                if (fireBulletPNG == false)
                    p->b6->sprite.setPosition(-100, p->b6->sprite.getPosition().y);

                x++;
                Score += 20;
            }
        }

        // GAMMA
        for (int i = 0; i < 15; i++)
        {
            if (p->b1->sprite.getPosition().y < gamma[i].sprite.getPosition().y + 30 && p->b1->sprite.getPosition().y > gamma[i].sprite.getPosition().y && p->b1->sprite.getPosition().x + 15 >= gamma[i].sprite.getPosition().x && p->b1->sprite.getPosition().x + 3 <= gamma[i].sprite.getPosition().x + 70)
            {
                gamma[i].sprite.setPosition(-200, 0);

                if (fireBulletPNG == false)
                    p->b1->sprite.setPosition(-100, p->b1->sprite.getPosition().y);

                x++;
                Score += 30;
            }

            if (p->b2->sprite.getPosition().y < gamma[i].sprite.getPosition().y + 30 && p->b2->sprite.getPosition().y > gamma[i].sprite.getPosition().y && p->b2->sprite.getPosition().x + 15 >= gamma[i].sprite.getPosition().x && p->b2->sprite.getPosition().x + 3 <= gamma[i].sprite.getPosition().x + 70)
            {
                gamma[i].sprite.setPosition(-200, 0);

                if (fireBulletPNG == false)
                    p->b2->sprite.setPosition(-100, p->b2->sprite.getPosition().y);

                x++;
                Score += 30;
            }

            if (p->b3->sprite.getPosition().y < gamma[i].sprite.getPosition().y + 30 && p->b3->sprite.getPosition().y > gamma[i].sprite.getPosition().y && p->b3->sprite.getPosition().x + 15 >= gamma[i].sprite.getPosition().x && p->b3->sprite.getPosition().x + 3 <= gamma[i].sprite.getPosition().x + 70)
            {
                gamma[i].sprite.setPosition(-200, 0);

                if (fireBulletPNG == false)
                    p->b3->sprite.setPosition(-100, p->b3->sprite.getPosition().y);

                x++;
                Score += 30;
            }

            if (p->b4->sprite.getPosition().y < gamma[i].sprite.getPosition().y + 30 && p->b4->sprite.getPosition().y > gamma[i].sprite.getPosition().y && p->b4->sprite.getPosition().x + 15 >= gamma[i].sprite.getPosition().x && p->b4->sprite.getPosition().x + 3 <= gamma[i].sprite.getPosition().x + 70)
            {
                gamma[i].sprite.setPosition(-200, 0);

                if (fireBulletPNG == false)
                    p->b4->sprite.setPosition(-100, p->b4->sprite.getPosition().y);

                x++;
                Score += 30;
            }

            if (p->b5->sprite.getPosition().y < gamma[i].sprite.getPosition().y + 30 && p->b5->sprite.getPosition().y > gamma[i].sprite.getPosition().y && p->b5->sprite.getPosition().x + 15 >= gamma[i].sprite.getPosition().x && p->b5->sprite.getPosition().x + 3 <= gamma[i].sprite.getPosition().x + 70)
            {
                gamma[i].sprite.setPosition(-200, 0);

                if (fireBulletPNG == false)
                    p->b5->sprite.setPosition(-100, p->b5->sprite.getPosition().y);

                x++;
                Score += 30;
            }

            if (p->b6->sprite.getPosition().y < gamma[i].sprite.getPosition().y + 30 && p->b6->sprite.getPosition().y > gamma[i].sprite.getPosition().y && p->b6->sprite.getPosition().x + 15 >= gamma[i].sprite.getPosition().x && p->b6->sprite.getPosition().x + 3 <= gamma[i].sprite.getPosition().x + 70)
            {
                gamma[i].sprite.setPosition(-200, 0);

                if (fireBulletPNG == false)
                    p->b6->sprite.setPosition(-100, p->b6->sprite.getPosition().y);

                x++;
                Score += 30;
            }
        }
    }

    void hitSpaceship(Sound sound)
    {
        int x = 0;

        // ALPHA
        for (int i = 0; i < 15; i++)
            if (((p->sprite.getPosition().y < alpha[i].sprite.getPosition().y + 40 && p->sprite.getPosition().y > alpha[i].sprite.getPosition().y) || (p->sprite.getPosition().y + 80 < alpha[i].sprite.getPosition().y + 40 && p->sprite.getPosition().y + 80 > alpha[i].sprite.getPosition().y)) && ((p->sprite.getPosition().x > alpha[i].sprite.getPosition().x && p->sprite.getPosition().x < alpha[i].sprite.getPosition().x + 70) || (p->sprite.getPosition().x + 100 > alpha[i].sprite.getPosition().x && p->sprite.getPosition().x + 100 < alpha[i].sprite.getPosition().x + 70)))
            {
                p->lives -= 1;
                p->sprite.setPosition(340, 650);
                x = 1;

                while (true)
                {
                    if (x == 1)
                        sound.play();

                    x = 0;

                    if (Keyboard::isKeyPressed(Keyboard::Slash))
                        break;
                }
            }

        // BETA
        for (int i = 0; i < 15; i++)
            if (((p->sprite.getPosition().y < beta[i].sprite.getPosition().y + 40 && p->sprite.getPosition().y > beta[i].sprite.getPosition().y) || (p->sprite.getPosition().y + 80 < beta[i].sprite.getPosition().y + 40 && p->sprite.getPosition().y + 80 > beta[i].sprite.getPosition().y)) && ((p->sprite.getPosition().x > beta[i].sprite.getPosition().x && p->sprite.getPosition().x < beta[i].sprite.getPosition().x + 70) || (p->sprite.getPosition().x + 100 > beta[i].sprite.getPosition().x && p->sprite.getPosition().x + 100 < beta[i].sprite.getPosition().x + 70)))
            {
                p->lives -= 1;
                p->sprite.setPosition(340, 650);
                x = 1;

                while (true)
                {
                    if (x == 1)
                        sound.play();

                    x = 0;

                    if (Keyboard::isKeyPressed(Keyboard::Slash))
                        break;
                }
            }

        // GAMMA
        for (int i = 0; i < 15; i++)
            if (((p->sprite.getPosition().y < gamma[i].sprite.getPosition().y + 40 && p->sprite.getPosition().y > gamma[i].sprite.getPosition().y) || (p->sprite.getPosition().y + 80 < gamma[i].sprite.getPosition().y + 40 && p->sprite.getPosition().y + 80 > gamma[i].sprite.getPosition().y)) && ((p->sprite.getPosition().x > gamma[i].sprite.getPosition().x && p->sprite.getPosition().x < gamma[i].sprite.getPosition().x + 70) || (p->sprite.getPosition().x + 100 > gamma[i].sprite.getPosition().x && p->sprite.getPosition().x + 100 < gamma[i].sprite.getPosition().x + 70)))
            {
                p->lives -= 1;
                p->sprite.setPosition(340, 650);
                x = 1;

                while (true)
                {
                    if (x == 1)
                        sound.play();

                    x = 0;

                    if (Keyboard::isKeyPressed(Keyboard::Slash))
                        break;
                }
            }
    }

    void endGame(RenderWindow &window, Sound sound)
    {
        if (p->lives == 0)
        {
            window.draw(gameEndIMG);
            window.display();
            sound.play();

            while (true)
                if (Keyboard::isKeyPressed(Keyboard::Enter))
                    window.close();
        }
    }

    void phaseCleared(Sound sound, RenderWindow &window, int &enemiesHit)
    {
        int x = 1;

        window.draw(lp1ClearedIMG);
        window.display();

        while (true)
        {
            if (x == 1)
                sound.play();

            x = 0;

            if (Keyboard::isKeyPressed(Keyboard::Enter))
                break;
        }

        enemiesHit = 16;
    }

    void phase2Cleared(Sound sound, RenderWindow &window, int &enemiesHit)
    {
        int x = 1;

        window.draw(lp2ClearedIMG);
        window.display();

        while (true)
        {
            if (x == 1)
                sound.play();

            x = 0;

            if (Keyboard::isKeyPressed(Keyboard::Enter))
                break;
        }

        enemiesHit = 32;
    }

    void phase3Cleared(Sound sound, RenderWindow &window, int &enemiesHit)
    {
        int x = 1;

        window.draw(lp3ClearedIMG);
        window.display();

        while (true)
        {
            if (x == 1)
                sound.play();

            x = 0;

            if (Keyboard::isKeyPressed(Keyboard::Enter))
                break;
        }
    }

    void monsterScreen(Sound sound, RenderWindow &window)
    {
        int x = 1;

        window.draw(monsterIntroIMG);
        window.display();

        while (true)
        {
            if (x == 1)
                sound.play();

            x = 0;

            if (Keyboard::isKeyPressed(Keyboard::X))
                break;
        }
    }

    void dragonScreen(Sound sound, RenderWindow &window)
    {
        int x = 1;

        window.draw(dragonIntroIMG);
        window.display();

        while (true)
        {
            if (x == 1)
                sound.play();

            x = 0;

            if (Keyboard::isKeyPressed(Keyboard::X))
                break;
        }
    }

    void gameFin(Sound sound, RenderWindow &window)
    {
        int x = 1;

        window.draw(gameWonIMG);
        window.display();

        while (true)
        {
            if (x == 1)
                sound.play();

            x = 0;

            if (Keyboard::isKeyPressed(Keyboard::Enter))
                window.close();
        }
    }

    void startGame(RenderWindow &window)
    {
        srand(time(0));

        // Defining and loading Fonts to be used for Text
        Font font;
        font.loadFromFile("Roboto-Bold.ttf");

        // --- MENU NAVIGATION Sound Effect --- //
        SoundBuffer beepB;
        beepB.loadFromFile("img/beep.wav");
        Sound beep;
        beep.setBuffer(beepB);
        // ------------------------------------ //

        // --- PAUSE Sound Effect --- //
        SoundBuffer pauseB;
        pauseB.loadFromFile("img/pause.wav");
        Sound pauseS;
        pauseS.setBuffer(pauseB);
        // ------------------------------------ //

        // --- LIFE LOST Sound Effect --- //
        SoundBuffer lifeLostB;
        lifeLostB.loadFromFile("img/lifeLost.wav");
        Sound lifeLostS;
        lifeLostS.setBuffer(lifeLostB);
        //  ------------------------------------ //

        // --- GAME OVER Sound Effect --- //
        SoundBuffer gameEndB;
        gameEndB.loadFromFile("img/gameEnd.wav");
        Sound gameEndS;
        gameEndS.setBuffer(gameEndB);
        //  ------------------------------------ //

        // --- PHASE CLEARED Sound Effect --- //
        SoundBuffer pClearB;
        pClearB.loadFromFile("img/phaseCleared.wav");
        Sound pClearS;
        pClearS.setBuffer(pClearB);
        //  ------------------------------------ //

        // --- COUNTDOWN FIGHT Sound Effect --- //
        SoundBuffer fightB;
        fightB.loadFromFile("img/fight.wav");
        Sound fightS;
        fightS.setBuffer(fightB);
        //  ------------------------------------ //

        // --- HEALTH PACK Sound Effect --- //
        SoundBuffer healthB;
        healthB.loadFromFile("img/healthSE.wav");
        Sound healthS;
        healthS.setBuffer(healthB);
        //  ------------------------------------ //

        // --- MONSTER INTRO Sound Effect --- //
        SoundBuffer monsterIntroB;
        monsterIntroB.loadFromFile("img/monsterIntro.wav");
        Sound monsterSE;
        monsterSE.setBuffer(monsterIntroB);
        //  ------------------------------------ //

        // --- DRAGON INTRO Sound Effect --- //
        SoundBuffer diB;
        diB.loadFromFile("img/dragon.wav");
        Sound dragonIntroSE;
        dragonIntroSE.setBuffer(diB);
        //  ------------------------------------ //

        // --- GAME WON Sound Effect --- //
        SoundBuffer gwB;
        gwB.loadFromFile("img/gameWon.wav");
        Sound gameWonSE;
        gameWonSE.setBuffer(gwB);
        //  ------------------------------------ //

        Clock clock;

        float timer = 0, second = 0, second5 = 0, second30 = 30;
        int RNG = 0, Score = 0;
        bool moveLife = false, moveDanger = false, moveFire = false, moveUpgrade = false, hitL = false, fireBulletPNG = false, upgradePNG = false, hitD = false, hitE = false, hitB = false;

        // Text : SCORE
        Text scoreDisp;
        scoreDisp.setFont(font);
        scoreDisp.setCharacterSize(14);
        scoreDisp.setFillColor(Color::Green);
        scoreDisp.setString("Score : " + to_string(Score));
        scoreDisp.setPosition(710, 166);

        // Text : TIME
        Text timeDisp;
        timeDisp.setFont(font);
        timeDisp.setCharacterSize(14);
        timeDisp.setFillColor(Color::Yellow);
        timeDisp.setString("Score : " + to_string(second30));
        timeDisp.setPosition(710, 200);

        while (window.isOpen())
        {
            float time = clock.getElapsedTime().asSeconds();
            clock.restart();

            timer += time;
            second += time;
            second5 += time;
            second30 -= time;

            if (second > 1)
                second = 0;

            if (second5 > 5.005)
                second5 = 0;

            if (second30 < 0)
                second30 = 30;

            Event e;

            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed)
                    window.close();
            }

            if (timer > 12)
            {
                if (Keyboard::isKeyPressed(Keyboard::Left)) // If left key is pressed
                    p->move("l", fireBulletPNG);            // Player will move to left

                if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
                    p->move("r", fireBulletPNG);             // player will move to right

                if (Keyboard::isKeyPressed(Keyboard::Up)) // If up key is pressed,
                    p->move("u", fireBulletPNG);          // playet will move upwards

                if (Keyboard::isKeyPressed(Keyboard::Down)) // If down key is pressed
                    p->move("d", fireBulletPNG);            // player will move downwards

                if (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Left))
                    p->move("q", fireBulletPNG);

                if (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Right))
                    p->move("w", fireBulletPNG);

                if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Left))
                    p->move("t", fireBulletPNG);

                if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Right))
                    p->move("s", fireBulletPNG);
            }

            ////////////////////////////////////////////////
            /////  Call your functions here            ////
            //////////////////////////////////////////////

            static int enemiesHit = 0;

            // MOVING BACKGROUND
            background.move(0, 0.013);

            if (background.getPosition().y > 0)
                background.setPosition(0, -780);

            // COUNTDOWN
            while (timer > 7.8 && timer < 7.805)
            {
                fightS.play();
                break;
            }

            // PAUSE GAME
            if (Keyboard::isKeyPressed(Keyboard::P))
                pauseGame(window, beep, pauseS);

            window.clear(Color::Black); // clears the screen
            window.draw(background);    // setting background

            // BULLETS
            if (timer > 10)
            {
                window.draw(p->b1->sprite);
                window.draw(p->b2->sprite);
                window.draw(p->b3->sprite);
                window.draw(p->b4->sprite);
                window.draw(p->b5->sprite);
                window.draw(p->b6->sprite);
            }

            p->fire(timer);

            // LIFE
            if (moveLife == false && timer > 15)
                RNG = rand() % 10000;

            if (RNG == 1)
                moveLife = true;

            if (timer > 15 && moveLife == true)
            {
                life->move(moveLife);
                p->hitLife(life->sprite.getPosition().x, life->sprite.getPosition().y, moveLife, healthS);
                window.draw(life->sprite);
            }

            if (moveLife == false)
                life->sprite.setPosition(life->random, -50);

            // DANGER
            if (RNG == 2)
                moveDanger = true;

            if (timer > 15 && moveDanger == true)
            {
                danger->move(moveDanger);
                p->hitDanger(danger->sprite.getPosition().x, danger->sprite.getPosition().y, moveDanger, lifeLostS, Score);
                window.draw(danger->sprite);
            }

            if (moveDanger == false)
                danger->sprite.setPosition(danger->random, -50);

            // FIRE
            if (RNG == 3)
                moveFire = true;

            if (fireBulletPNG == true)
                moveFire = false;

            if (timer > 15 && moveFire == true)
            {
                fire->move(moveFire);
                p->hitFire(fire->sprite.getPosition().x, fire->sprite.getPosition().y, moveFire, healthS, fireBulletPNG, upgradePNG);
                window.draw(fire->sprite);
            }

            if (moveFire == false)
                fire->sprite.setPosition(fire->random, -50);

            // UPGRADE
            if (RNG == 4)
                moveUpgrade = true;

            if (upgradePNG == true)
                moveUpgrade = false;

            if (timer > 15 && moveUpgrade == true)
            {
                upgrade->move(moveUpgrade);
                p->hitUpgrade(upgrade->sprite.getPosition().x, upgrade->sprite.getPosition().y, moveUpgrade, healthS, fireBulletPNG, upgradePNG);
                window.draw(upgrade->sprite);
            }

            if (moveUpgrade == false)
                upgrade->sprite.setPosition(upgrade->random, -50);

            // PLAYER
            window.draw(p->sprite);

            // ENEMY - PHASE 1
            setEnemies(timer, second);

            // START BATTLE
            if (timer > 10)
            {
                hitSpaceship(lifeLostS);
                hitEnemy(enemiesHit, fireBulletPNG, Score);
            }

            // ALPHA
            if (enemiesHit < 16)
                for (int i = 0; i < 15 && timer > 2.68; i++)
                    window.draw(alpha[i].sprite);

            // BETA
            if (enemiesHit > 15 && enemiesHit < 32)
                for (int i = 0; i < 15; i++)
                    window.draw(beta[i].sprite);

            // GAMMA
            if (enemiesHit > 31 && enemiesHit < 48)
                for (int i = 0; i < 15; i++)
                    window.draw(gamma[i].sprite);

            // BOMBS
            for (int i = 0; i < 15; i++)
                if (second5 > 5)
                {
                    alpha[i].bomb->sprite.setPosition(alpha[i].sprite.getPosition().x + 20, alpha[i].sprite.getPosition().y + 5);
                    beta[i].bomb->sprite.setPosition(beta[i].sprite.getPosition().x + 20, beta[i].sprite.getPosition().y + 5);
                    gamma[i].bomb->sprite.setPosition(gamma[i].sprite.getPosition().x + 20, gamma[i].sprite.getPosition().y + 5);
                }

            for (int i = 0; i < 15; i++)
            {
                // ALPHA
                if (timer > 15)
                {
                    if (alpha[i].sprite.getPosition().x > 0 && alpha[i].sprite.getPosition().x < 780 && RNG == alpha[i].bomb->firingNo)
                        alpha[i].bomb->shoot = true;

                    if (alpha[i].bomb->shoot == true)
                    {
                        alpha[i].fire(0);
                        window.draw(alpha[i].bomb->sprite);
                        p->hitBomb(alpha[i].bomb->sprite.getPosition().x, alpha[i].bomb->sprite.getPosition().y, lifeLostS, alpha[i].bomb->shoot);
                    }

                    if (alpha[i].bomb->sprite.getPosition().y > 780)
                        alpha[i].bomb->shoot = false;
                }

                // BETA
                if (enemiesHit > 15 && enemiesHit < 32)
                {
                    if (beta[i].sprite.getPosition().x > 0 && beta[i].sprite.getPosition().x < 780 && (RNG == beta[i].bomb->firingNo || RNG == beta[i].bomb->firingNo + 100 || RNG == beta[i].bomb->firingNo + 200))
                        beta[i].bomb->shoot = true;

                    if (beta[i].bomb->shoot == true)
                    {
                        beta[i].fire(0);
                        window.draw(beta[i].bomb->sprite);
                        p->hitBomb(beta[i].bomb->sprite.getPosition().x, beta[i].bomb->sprite.getPosition().y, lifeLostS, beta[i].bomb->shoot);
                    }

                    if (beta[i].bomb->sprite.getPosition().y > 780)
                        beta[i].bomb->shoot = false;
                }

                // GAMMA
                if (enemiesHit > 31 && enemiesHit < 48)
                {
                    if (gamma[i].sprite.getPosition().x > 0 && gamma[i].sprite.getPosition().x < 780 && (RNG == gamma[i].bomb->firingNo || RNG == gamma[i].bomb->firingNo + 107 || RNG == gamma[i].bomb->firingNo + 108 || RNG == gamma[i].bomb->firingNo + 175 || RNG == gamma[i].bomb->firingNo + 156))
                        gamma[i].bomb->shoot = true;

                    if (gamma[i].bomb->shoot == true)
                    {
                        gamma[i].fire(0);
                        window.draw(gamma[i].bomb->sprite);
                        p->hitBomb(gamma[i].bomb->sprite.getPosition().x, gamma[i].bomb->sprite.getPosition().y, lifeLostS, gamma[i].bomb->shoot);
                    }

                    if (gamma[i].bomb->sprite.getPosition().y > 780)
                        gamma[i].bomb->shoot = false;
                }
            }

            // PHASE 1
            if (enemiesHit == 15)
            {
                for (int i = 0; i < 15; i++)
                    alpha[i].bomb->shoot = false;

                phaseCleared(pClearS, window, enemiesHit);
                p->sprite.setPosition(340, 650);
            }

            // PHASE 2
            if (enemiesHit == 16)
                level1->Phase2(beta);

            if (enemiesHit == 31)
            {
                for (int i = 0; i < 15; i++)
                    beta[i].bomb->shoot = false;

                phase2Cleared(pClearS, window, enemiesHit);
                p->sprite.setPosition(340, 650);
            }

            // PHASE 3
            if (enemiesHit == 32)
                level1->Phase3(gamma);

            if (enemiesHit == 47)
            {
                for (int i = 0; i < 15; i++)
                    gamma[i].bomb->shoot = false;

                phase3Cleared(pClearS, window, enemiesHit);
                p->sprite.setPosition(340, 650);
                dragonScreen(dragonIntroSE, window);
                dragon->sprite.setPosition(200, 0);
                enemiesHit = 48;
                second30 = 30;
                second5 = 0;
            }

            // DRAGON
            if (enemiesHit == 48)
            {
                window.draw(dIndiIMG);
                timeDisp.setString(to_string(int(second30)));
                window.draw(timeIndiIMG);
                window.draw(timeDisp);

                if (second5 > 4)
                {
                    dragon->fire(p->sprite.getPosition().x);
                    window.draw(dragon->dFire->sprite);
                    p->hitDragon(dragon->dFire->sprite.getPosition().x, lifeLostS, second5, Score);
                }

                if (second5 < 4)
                    dragon->dFire->sprite.setPosition(-500, -800);

                if (second30 < 0.1)
                {
                    enemiesHit = 49;
                    second30 = 30;
                    second5 = 0;
                    p->sprite.setPosition(340, 650);
                    monsterScreen(monsterSE, window);
                    monster->sprite.setPosition(200, 0);
                }

                window.draw(dragon->sprite);
            }

            // MONSTER
            if (enemiesHit == 49)
            {
                timeDisp.setString(to_string(int(second30)));
                window.draw(timeIndiIMG);
                window.draw(timeDisp);

                if (monster->moveMonster == true)
                    monster->move();

                if (second5 > 4)
                {
                    monster->fire(0);
                    window.draw(monster->lightning->sprite);
                }

                else
                    monster->moveMonster = true;

                if (second30 < 0.1)
                    gameFin(gameWonSE, window);

                p->hitMonster(monster->lightning->sprite.getPosition().x, lifeLostS, monster->moveMonster, second5, Score);
                window.draw(monster->sprite);
                window.draw(mIndiIMG);
            }

            // END BATTLE
            endGame(window, gameEndS);

            // SHOW LEVEL & PHASE
            if (enemiesHit < 16)
                window.draw(lp1IMG);

            if (enemiesHit > 15 && enemiesHit < 32)
                window.draw(lp2IMG);

            if (enemiesHit > 31 && enemiesHit < 48)
                window.draw(lp3IMG);

            // To constantly Update the Score on the Screen
            scoreDisp.setString(to_string(Score));

            // SCORE
            window.draw(scoreIndiIMG);
            window.draw(scoreDisp);

            // LIVES
            if (p->lives == 3)
                window.draw(life3IMG);

            if (p->lives == 2)
                window.draw(life2IMG);

            if (p->lives == 1)
                window.draw(life1IMG);

            window.display(); // Displying all the sprites
        }
    }

    ~Game()
    {
        delete p;

        delete[] alpha;
        delete[] beta;
        delete[] gamma;
        delete monster;

        delete life;
        delete danger;
        delete fire;
        delete upgrade;
    }
};
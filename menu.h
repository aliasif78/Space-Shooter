#include <SFML/Graphics.hpp>
#include "game.h"

class Menu
{

public:
    Texture texture, texture2;
    Sprite sprite, sprite2;

    Menu()
    {
        // MENU SCREEN
        texture.loadFromFile("img/menuScreen.png");
        sprite.setTexture(texture);
        sprite.setPosition(0, 0);

        // INSTRUCTIONS
        texture2.loadFromFile("img/instructions.png");
        sprite2.setTexture(texture2);
        sprite2.setPosition(0, 0);
    }

    void display_menu()

    {
        Game g;

        RenderWindow window(VideoMode(780, 780), title, Style::Close); // Prevent Window from being Resized
        window.setMouseCursorVisible(false);

        // --- MENU MUSIC --- //
        SoundBuffer musicB;
        musicB.loadFromFile("img/menuMusic.wav");
        Sound music;
        music.setBuffer(musicB);
        music.play();
        // ------------------------------------ //

        // --- MENU MUSIC --- //
        SoundBuffer startGameB;
        startGameB.loadFromFile("img/gameStart.wav");
        Sound startGame;
        startGame.setBuffer(startGameB);
        // ------------------------------------ //

        // --- BACKWARD SE --- //
        SoundBuffer backwardB;
        backwardB.loadFromFile("img/beep.wav");
        Sound backwardS;
        backwardS.setBuffer(backwardB);
        // ------------------------------------ //

        while (window.isOpen())
        {
            Event e;

            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed) // If cross/close is clicked/pressed
                    window.close();          // close the game
            }

            // START
            if (Keyboard::isKeyPressed(Keyboard::S))
            {
                music.stop();
                startGame.play();
                g.startGame(window);
            }

            // INSTRUCTIONS
            if (Keyboard::isKeyPressed(Keyboard::I))
            {
                backwardS.play();

                while (true)
                {
                    window.draw(sprite2);
                    window.display();

                    if (Keyboard::isKeyPressed(Keyboard::Enter))
                    {
                        backwardS.play();
                        break;
                    }
                }
            }

            // LEADERBOARD
            if (Keyboard::isKeyPressed(Keyboard::L))
                g.startGame(window);

            // QUIT
            if (Keyboard::isKeyPressed(Keyboard::X))
                window.close();

            window.clear();
            window.draw(sprite);
            window.display(); // Displying all the sprites
        }

        // display menu screen here
        // add functionality of all the menu options here
        // if Start game option is chosen
    }
};

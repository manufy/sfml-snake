

//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "FileLogger.hpp"

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"
#include "Game.hpp"

int main(int, char const**)
{
    
    printf("2111111");
    Game game;
        game.run();
    return EXIT_SUCCESS;
    
    
    
    
    
    
    
    // Create object
    ige::FileLogger myLog ("1.0.4.2", "testfile.txt");

    // Writing warnings or errors to file is very easy and C++ style
    myLog << ige::FileLogger::e_logType::LOG_WARNING << "Hey! ... This is a warning message!";
    myLog << ige::FileLogger::e_logType::LOG_ERROR << "WOW! Something really wrong is happening here!";
    myLog << "This is just a simple text";
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile(resourcePath() + "cute_image.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text text("Hello SFML", font, 50);
    text.setFillColor(sf::Color::Black);

    // Load a music to play
    sf::Music music;
    if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {
        return EXIT_FAILURE;
    }
    int x =0;
    int y =0;
    bool isMovingUp = false;
 
    
    //music.play();
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) {
                isMovingUp = true;
            }
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Left) {
                isMovingUp = false;
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
                y++;
                printf("up 1");
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            x--;
        }
        
        if (isMovingUp == true) y++;
        
        sprite.setPosition(x+10, y);
        
        // Clear screen
        window.clear();

        // Draw the sprite
        window.draw(sprite);

        // Draw the string
        window.draw(text);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}


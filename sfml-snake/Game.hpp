//
//  Game.hpp
//  sfml-snake
//
//  Created by Manu on 23/11/21.
//  Copyright © 2021 armaril. All rights reserved.
//

#ifndef Game_h
#define Game_h


#endif /* Game_h */

//
//  Game.hpp
//  demo1
//
//  Created by Manu on 22/11/21.
//  Copyright © 2021 Manu. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>

#endif /* Game_hpp */

#include <SFML/Graphics.hpp>
#include <iostream>

class Game
{
public:
    Game();
    void run();

private:
    void proccessEvent();
    void update(sf::Time deltaTime);
    void render();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
    const float playerSpeed = 100.f;
    const sf::Time TimePerFrame = sf::seconds(1.0f / 60.0f);

    sf::RenderWindow mWindow;
    sf::Keyboard::Key key;
    sf::Texture texture;
    sf::RectangleShape rect;
    bool isPressed;
    bool mIsMovingUp;
    bool mIsMovingDown;
    bool mIsMovingRight;
    bool mIsMovingLeft;
};

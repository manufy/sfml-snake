//
//  Game.cpp
//  sfml-snake
//
//  Created by Manu on 23/11/21.
//  Copyright © 2021 armaril. All rights reserved.
//

#include <stdio.h>

//
//  Game.cpp
//  demo1
//
//  Created by Manu on 22/11/21.
//  Copyright © 2021 Manu. All rights reserved.
//

#include "Game.hpp"


Game::Game()
    : //Make sure to initialize member variables.
     playerSpeed(100.f),
     TimePerFrame(sf::seconds(1.f / 60.f)),
     mWindow(sf::VideoMode(640, 480), "SFML Application"),
     key(sf::Keyboard::Unknown),
     isPressed(false),
     mIsMovingUp(false),
     mIsMovingDown(false),
     mIsMovingRight(false),
     mIsMovingLeft(false)
{
    //  rect.setTexture(texture);
    rect.setFillColor(sf::Color::Red);
    rect.setSize(sf::Vector2f(20.0f, 20.0f));
}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (mWindow.isOpen())
    {
        proccessEvent();
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            proccessEvent();
            update(TimePerFrame);
        }
        render();
    }
}


void Game::update(sf::Time deltaTime)
{

    sf::Vector2<float> movement(0.0f, 0.0f);
    if (mIsMovingUp)
    {
        movement.y -= playerSpeed;
    }
    else if (mIsMovingDown)
    {
        movement.y += playerSpeed;
    }
    if (mIsMovingRight)
    {
        // You were subtracting to move right, add instead.
        movement.x += playerSpeed;
    }
    else if (mIsMovingLeft)
    {
        movement.x -= playerSpeed;
    }
    rect.move(movement * deltaTime.asSeconds());

}

void Game::render()
{
    //if (!texture.loadFromFile("/Users/tahajalili/Desktop/Eagle.png"))
    //{
    //  std::cout << "Error occured" << std::endl;
    //}

    mWindow.clear();
    mWindow.draw(rect);
    mWindow.display();
}

void Game::proccessEvent()
{
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            mWindow.close();
            break;
        case sf::Event::KeyPressed:
            handlePlayerInput(event.key.code, true);
            break;
        case sf::Event::KeyReleased:
            handlePlayerInput(event.key.code, false);
            break;
        default:
            break;
        }
    }
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    if (key == sf::Keyboard::W)
    {
        mIsMovingUp = isPressed;
    }
    else if (key == sf::Keyboard::S)
    {
        mIsMovingDown = isPressed;
    }
    else if (key == sf::Keyboard::D)
    {
        mIsMovingRight = isPressed;
    }
    else if (key == sf::Keyboard::A)
    {
        mIsMovingLeft = isPressed;
    }
}

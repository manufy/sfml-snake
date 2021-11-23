//
//  Game.cpp
//  demo1
//
//  Created by Manu on 22/11/21.
//  Copyright © 2021 Manu. All rights reserved.
//

#include <stdio.h>
#include "Game.hpp"
#include "ResourcePath.hpp"

Game::Game()
    :
     playerSpeed(500.0f),
     TimePerFrame(sf::seconds(1.f / 60.f)),
     mWindow(sf::VideoMode(1024, 768), "SFML Snake"),
     key(sf::Keyboard::Unknown),
     isPressed(false),
     mIsMovingUp(false),
     mIsMovingDown(false),
     mIsMovingRight(false),
     mIsMovingLeft(false)
{
    rect.setFillColor(sf::Color::Red);
    rect.setSize(sf::Vector2f(20.0f, 20.0f));
}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile(resourcePath() + "background-sea-00.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite backgroundSprite(texture);
    while (mWindow.isOpen())
    {
        processEvent();
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            processEvent();
            update(TimePerFrame);
        }
        renderBackground(backgroundSprite);
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

void Game::renderBackground(sf::Sprite sprite)
{
    mWindow.clear();
    sprite.setPosition(0,0);
    mWindow.draw(sprite);
}

void Game::render()
{
    
    mWindow.draw(rect);
    mWindow.display();
}

void Game::processEvent()
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
    if (key == sf::Keyboard::Up)
    {
        mIsMovingUp = isPressed;
    }
    else if (key == sf::Keyboard::Down)
    {
        mIsMovingDown = isPressed;
    }
    else if (key == sf::Keyboard::Right)
    {
        mIsMovingRight = isPressed;
    }
    else if (key == sf::Keyboard::Left)
    {
        mIsMovingLeft = isPressed;
    }
}

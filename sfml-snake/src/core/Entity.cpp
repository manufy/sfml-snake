//
//  Entity.cpp
//  sfml-snake
//
//  Created by Manuel on 23/11/21.
//  Copyright © 2021 armaril. All rights reserved.
//

#include "Entity.hpp"

void MyEntity::draw(sf::RenderTarget& target, sf::RenderStates states)
{
        // apply the entity's transform -- combine it with the one that was passed by the caller
        states.transform *= getTransform(); // getTransform() is defined by sf::Transformable

        // apply the texture
        states.texture = &m_texture;

        // you may also override states.shader or states.blendMode if you want

        // draw the vertex array
        target.draw(m_vertices, states);
}

   


//
//  Entity.hpp
//  sfml-snake
//
//  Created by Manuel on 23/11/21.
//  Copyright © 2021 armaril. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp

#include <stdio.h>

#endif /* Entity_hpp */

#include <SFML/Graphics.hpp>

class MyEntity: public sf::Drawable, public sf::Transformable
{
public:

    // add functions to play with the entity's geometry / colors / texturing...

private:
    
    sf::VertexArray m_vertices;
    sf::Texture m_texture;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states);
  
};


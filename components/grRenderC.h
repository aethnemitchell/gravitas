// grRenderC.h
#ifndef GRRENDERC_H
#define GRRENDERC_H

#include <memory>
#include <SFML/Graphics.hpp>
#include "../math/grCvPoly2.h"

class grRenderC
{
    grCvPoly2 const&                        geometry;
    std::unique_ptr<sf::ConvexShape>        sf_poly;
    std::unique_ptr<sf::RectangleShape>     sf_aabb;
    std::unique_ptr<sf::CircleShape>        sf_centre;
    std::vector<sf::CircleShape>            sf_verts;

    r32 const centroid_size = 3.0;
    r32 const vert_size = 1.0;

public:
    grRenderC ( grCvPoly2 const& geometry_ );
    void update ( r32 dt );
    void draw ( sf::RenderWindow& window ) const;
};

#endif


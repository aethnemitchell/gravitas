// grRenderC.h
#ifndef GRRENDERC_H
#define GRRENDERC_H

#include <memory>
#include "../math/grCvPoly2.h"

class grRenderC
{
    grCvPoly2 const&                        entity_geometry;
    std::unique_ptr<sf::ConvexShape>        sf_poly;
    std::unique_ptr<sf::RectangleShape>     sf_aabb;
    std::unique_ptr<sf::CircleShape>        sf_centre;
    std::vector<sf::CircleShape>            sf_verts;

public:
    grRenderC ( grCvPoly const& geometry );
    update (r32 dt );
    draw ( sf::RenderWindow& window ) const;
};

#endif


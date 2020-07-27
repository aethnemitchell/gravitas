// grRenderC.cpp

#include "grRenderC.h"

grRenderC::grRenderC ( grCvPoly2 const& geometry )
    : entity_geometry ( geometry )
{
    // polygon
    sf_poly = std::unique_ptr<sf::ConvexShape>( new sf::ConvexShape );
    sf_poly->setPointCount( entity_geometry.vertices.size() );

    for ( size_t i = 0; i < geometry.vertices.size(); i++ )
    {
        sf_poly->setPoint( i, sf::Vector2f( geometry.vertices[i].x, geometry.vertices[i].y ) );
    }

    sf_poly->setFillColor( sf::Color( 80.0, 80.0, 80.0 ) );
    sf_poly->setPosition( geometry.pos.x, geometry.pos.y );

    // aabb
    sf_aabb = std::unique_ptr<sf::RectangleShape>( new sf::RectangleShape );
    sf_aabb->setPosition( geometry.aabb.first.x, geometry.aabb.first.y );
    r32 width = geometry.aabb.second.x - geometry.aabb.first.x;
    r32 height = geometry.aabb.second.y - geometry.aabb.first.y;
    sf_aabb->setSize( sf::Vector2f( width, height ) );
    sf_aabb->setOutlineColor( sf::Color::White );
    sf_aabb->setOutlineThickness( 1 );
    sf_aabb->setFillColor( sf::Color( 0, 0, 0, 0 ) );

    // centroid
    r32 centroid_size = 4.0;

    sf_centre = std::unique_ptr<sf::CircleShape>( new sf::CircleShape( centroid_size ) );
    sf_centre->setPosition( geometry.centroid.x - centroid_size / 2,
                            geometry.centroid.y - centroid_size / 2 );
    sf_centre->setFillColor( sf::Color::Blue );

    // verts
    r32 vert_size = 2.0;

    for ( size_t i = 0; i < geometry.vertices.size(); i++ )
    {
        sf::CircleShape vert_circ( vert_size );
        vert_circ.setPosition( geometry.vertices[i].x - vert_size / 2,
                               geometry.vertices[i].y - vert_size / 2 );
        vert_circ.setFillColor( sf::Color::Red );
        sf_verts.push_back(vert_circ);
    }
}

void grRenderC::update ( r32 dt )
{
    // @todo grRenderC::update
}

void grRenderC::draw ( sf::RenderWindow & window ) const
{
    window.draw( *sf_poly );
    window.draw( *sf_aabb );
    window.draw( *sf_centre );
    for ( sf::CircleShape sf_c : sf_verts )
    {
        window.draw( sf_c );
    }
}


// grRenderC.cpp

#include "grRenderC.h"

grRenderC::grRenderC ( grCvPoly const& geometry )
    : entity_geometry ( geometry )
{
    sf_poly = std::unique_ptr<sf::ConvexShape>( new sf::ConvexShape );
    sf_poly->setPointCount( entity_geometry.vertices.size() );
    sf_poly->setFillColor( sf::Color( 80.0, 80.0, 80.0 ) );
    sf_poly->setPosition( 0, 0 );


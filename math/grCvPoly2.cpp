// grCvPoly2.cpp

#include "grCvPoly2.h"

grCvPoly2::grCvPoly2 ( std::vector<grVec2> vertices_ )
{
    if ( vertices_.size() < 3 )
    {
        throw std::invalid_argument( "Empty or degenerate vertex list" );
    }

    vertices = convex_hull( vertices_ );
    centroid = compute_centroid ( vertices );
}

std::vector<grvec2> convex_hull ( std::vector<grVec2> const& vertices_ )
{
    // by gift wrap algorithm
    std::vector<grVec2> final_points;

    // @todo
}


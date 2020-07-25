// grCvPoly2.cpp

#include <tuple>
#include "grCvPoly2.h"

// constructors

grCvPoly2::grCvPoly2 ( std::vector<grVec2> const& vertices_ )
{
    if ( vertices_.size() < 3 )
    {
        throw std::invalid_argument( "Empty or degenerate vertex list" );
    }

    vertices = cv_hull_from_points ( vertices_ );
    centroid = compute_centroid ( vertices );
}

// static

std::vector<grVec2> grCvPoly2::cv_hull_from_points ( std::vector<grVec2> const& vertices_ )
{
    size_t leftmost_index = 0;

    for ( size_t i = 1; i < vertices_.size(); i++ )
    {
        if ( vertices_[i].x < vertices_[leftmost_index].x )
        {
            leftmost_index = i;
        }
    }

    std::vector<grVec2> output_set;
    output_set.push_back( grVec2( vertices_[leftmost_index] ) );

    size_t l = leftmost_index;

    while (true)
    {
        size_t q = (l + 1) % vertices_.size();
        for (size_t i = 0; i < vertices_.size(); i++ )
        {
            if (i == l) continue;

            int dir = grVec2::orientation( vertices_[l], vertices_[i], vertices_[q] );
            
            if ( dir > 0 ) q = i;

        }
        l = q;

        if ( q == leftmost_index ) break;

        output_set.push_back( grVec2( vertices_[q] ) );
    }

    return output_set;
}

grVec2 grCvPoly2::compute_centroid ( std::vector<grVec2> const& vertices_ )
{
    std::vector<std::tuple<size_t, size_t, size_t>> triangles;

    for ( size_t i = 1; i < vertices_.size() - 1; i++ )
    {
        triangles.push_back( std::make_tuple( 0, i, i + 1 ) );
    }

    std::vector<r32> areas;
    std::vector<grVec2> centroids;
    r32 total_area = 0.0;

    for ( size_t i = 0; i < triangles.size(); i++ )
    {
        auto tri = triangles[i];

        grVec2 p_a = vertices_[std::get<0>( tri )];
        grVec2 p_b = vertices_[std::get<1>( tri )];
        grVec2 p_c = vertices_[std::get<2>( tri )];

        centroids.push_back( ( p_a + p_b + p_c ) / 3.0 );

        r32 a = grVec2::distance( p_a, p_b );
        r32 b = grVec2::distance( p_b, p_c );
        r32 c = grVec2::distance( p_c, p_a );

        r32 s = ( a + b + c ) / 2.0; // semi-perimeter

        r32 area = std::sqrt( s * (s - a) * (s - b) * (s - c) );
        areas.push_back( area );
        total_area += area;
    }

    grVec2 final_centroid( 0.0, 0.0 );

    for ( size_t i = 0; i < triangles.size(); i++ )
    {
        final_centroid += centroids[i] * areas[i] / total_area;
    }

    return final_centroid;
}


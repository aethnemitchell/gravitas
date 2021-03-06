// grCvPoly2.h
#ifndef GRCVPOLY2_H
#define GRCVPOLY2_H

#include <algorithm>
#include <vector>
#include <stdexcept>
#include <utility>

#include "grVec2.h"

struct grCvPoly2
{
    std::vector<grVec2>         vertices;
    grVec2                      centroid;
    std::pair<grVec2, grVec2>   aabb;
    grVec2                      pos;
    r32                         rot;

    r32                     area;

    grCvPoly2 ( std::vector<grVec2> const& vertices_ );
    void update_aabb ( );

private:
    static std::vector<grVec2> cv_hull_from_points ( std::vector<grVec2> const& vertices_ );
    static grVec2 compute_centroid ( std::vector<grVec2> const& vertices_ ); // must only be called on vertices returned by cv_hull_from point
};


#endif


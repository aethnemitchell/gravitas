// grCvPoly2.h
#ifndef GRCVPOLY2_H
#define GRCVPOLY2_H

#include <algorithm>
#include <vector>
#include <stdexcept>

#include "grVec2.h"

struct grCvPoly2
{
    std::vector<grVec2>     vertices;
    grVec2                  centroid;

    grCvPoly2 ( std::vector<grVec2> const& vertices_ );
};

std::vector<grVec2> convex_hull ( std::vector<grVec2> vertices_ );
grVec2 compute_centroid ( std::vector<grVec2> vertices_ );

#endif


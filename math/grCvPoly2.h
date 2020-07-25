// grCvPoly2.h
#ifndef GRCVPOLY2_H
#define GRCVPOLY2_H

#include <algorithm>
#include <vector>

#include "grVec2.h"

struct grCvPoly2
{
    std::vector<grVec2> vertices;
    
    grCvPoly2 ( std::vector<grVec2> vertices_ );

    
};

#endif


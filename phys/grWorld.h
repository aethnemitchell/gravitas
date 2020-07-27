// grWorld.h
#ifndef GRWORLD_H
#define GRWORLD_H

#include <vector>
#include "../components/grColliderC.h"
#include "../math/grCvPoly2.h"
#include "../math/grVec2.h"

struct grField
{
    grVec2  position;
    r32     magnitude;
    bool    is_radial; // 0 orthogonal 1 radial
};

struct grWorld
{
    std::vector<grColliderC*>    colliders;
    std::vector<grField*>        fields;

    void update ( r32 dt );
};

#endif


// grColliderC.h
#ifndef GRCOLLIDERC_H
#define GRCOLLIDERC_H

#include "../math/grVec2.h"
#include "../math/grCvPoly2.h"

class grColliderC
{
    grCvPoly2 & geometry;

public:
    grVec2  vel;
    grVec2  angular_vel;
    r32     mass;
    r32     inertia; 

    grColliderC ( grCvPoly2 & geometry_ );
    grColliderC ( grCvPoly2 & geometry_, r32 mass_ );

    void update( r32 dt );
};
    
#endif


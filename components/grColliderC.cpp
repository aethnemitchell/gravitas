// grColliderC.cpp

#include "grColliderC.h"

grColliderC::grColliderC ( grCvPoly2 & geometry_ )
    : geometry ( geometry_ )
    , mass ( 1.0 )
    , inertia ( 0.0 )
{ }

grColliderC::grColliderC ( grCvPoly2 & geometry_, r32 mass_ )
    : geometry ( geometry_ )
    , mass ( mass_ )
    , inertia ( 0.0 )
{ }

void grColliderC::update ( r32 dt )
{
    // wew
}

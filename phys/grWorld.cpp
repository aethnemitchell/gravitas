// grWorld.cpp

#include "grWorld.h"

void grWorld::update ( r32 dt )
{
    for ( auto collc : colliders ) // @inprog
    {
        collc->vel.y += 10.0 * dt;
        collc->update( dt );
    }
}


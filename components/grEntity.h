// grEntity.h
#ifndef GRENTITY_H
#define GRENTITY_H

#include <memory>
#include "../math/grCvPoly2.h"
#include "grRenderC.h"
//#include "grColliderC.h"

struct grEntity
{
    grCvPoly2                       geometry;
    std::unique_ptr<grRenderC>      render_c;
    // std::unique_ptr<grColliderC>    collider_c;
    // std::unique_ptr<grFieldC>       field_c;
    // std::unique_ptr<grInputC>       input_c;

    grEntity ( grCvPoly2 const& geometry_ );
    void update ( r32 dt );
};

#endif


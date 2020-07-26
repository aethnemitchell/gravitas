// grEntity.cpp

#include "grEntity.h"

grEntity::grEntity ( grCvPoly2 geometry_ )
{
    geometry = grCvPoly2( geometry_ );
    render_c = std::unique_ptr<grRenderC>( geometry.get() );


}

void grEntity::update ( r32 dt )
{
    if ( render_c   != nullptr ) render_c->update( dt );
    if ( collider_c != nullptr ) collider_c->update( dt );
//    if ( input_c    != nullptr ) input_c->update( dt );
}


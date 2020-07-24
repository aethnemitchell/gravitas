// grVec2.cpp

#include "grVec2.h"
#include <cmath>

// constructors

grVec2::grVec2 ( )
{ }

grVec2::grVec2 ( r32 x_, r32 y_ )
    : x ( x_ ), y ( y_ )
{ }

// methods

void grVec2::zero ( )
{
    x = 0;
    y = 0;
}

void grVec2::assign ( r32 x_, r32 y_ )
{
    x = x_;
    y = y_;
}

// operators

grVec2 grVec2::operator- ( void ) const
{
    return grVec2( -x, -y );
}


r32& grVec2::operator[] ( int i )
{
    return vec[i];
}

r32 grVec2::operator[] ( int i ) const
{
    return vec[i];
}


grVec2 const grVec2::operator+ ( const grVec2& r_operand )
{
    return grVec2( x + r_operand.x, y + r_operand.y );
}

grVec2 const grVec2::operator- ( const grVec2& r_operand )
{
    return grVec2( x - r_operand.x, y - r_operand.y );
}

grVec2 const grVec2::operator* ( r32 r_operand )
{
    return grVec2( x * r_operand, y * r_operand );
}

grVec2 const grVec2::operator/ ( r32 r_operand )
{
    return grVec2( x / r_operand, y / r_operand );
}


grVec2& grVec2::operator+= ( const grVec2& r_operand )
{
    x += r_operand.x;
    y += r_operand.y;

    return *this;
}

grVec2& grVec2::operator-= ( const grVec2& r_operand )
{
    x -= r_operand.x;
    y -= r_operand.y;

    return *this;
}

r32 grVec2::operator*= ( r32 r_operand )
{
    x *= r_operand;
    y *= r_operand;
    
    return *this;
}

r32 grVec2::operator*= ( r32 r_operand )
{
    x /= r_operand;
    y /= r_operand;
    
    return *this;
}

// static


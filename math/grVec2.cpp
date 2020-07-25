// grVec2.cpp
#include "grVec2.h"

// constructors

grVec2::grVec2 ( )
    : x ( 0.0f )
    , y ( 0.0f )
{ }

grVec2::grVec2 ( r32 x_, r32 y_ )
    : x ( x_ )
    , y ( y_ )
{ }

grVec2::grVec2 ( r32 x_, r32 y_, r32 len )
    : x ( len * x_ / length( grVec2( x_, y_ ) ) )
    , y ( len * y_ / length( grVec2( x_, y_ ) ) )
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

void grVec2::rotate ( r32 angle )
{
    r32 old_x = x;
    x = std::cos( angle ) * x     - std::sin( angle ) * y;
    y = std::sin( angle ) * old_x + std::cos( angle ) * y;
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


grVec2 const grVec2::operator+ ( grVec2 const& r_operand ) const
{
    return grVec2( x + r_operand.x, y + r_operand.y );
}

grVec2 const grVec2::operator- ( grVec2 const& r_operand ) const
{
    return grVec2( x - r_operand.x, y - r_operand.y );
}

grVec2 const grVec2::operator* ( r32 r_operand ) const
{
    return grVec2( x * r_operand, y * r_operand );
}

grVec2 const grVec2::operator/ ( r32 r_operand ) const
{
    return grVec2( x / r_operand, y / r_operand );
}


grVec2& grVec2::operator+= ( grVec2 const& r_operand )
{
    x += r_operand.x;
    y += r_operand.y;

    return *this;
}

grVec2& grVec2::operator-= ( grVec2 const& r_operand )
{
    x -= r_operand.x;
    y -= r_operand.y;

    return *this;
}

grVec2& grVec2::operator*= ( r32 r_operand )
{
    x *= r_operand;
    y *= r_operand;
    
    return *this;
}

grVec2& grVec2::operator/= ( r32 r_operand )
{
    x /= r_operand;
    y /= r_operand;
    
    return *this;
}

// static

r32 grVec2::length ( grVec2 const& vec_a )
{
    return std::sqrt( vec_a.x * vec_a.x + vec_a.y * vec_a.y );
}

r32 grVec2::distance ( grVec2 const& vec_a, grVec2 const& vec_b )
{
    r32 d_x = vec_b.x - vec_a.x;
    r32 d_y = vec_b.y - vec_a.y;

    return std::sqrt( d_x * d_x + d_y * d_y );
}

r32 grVec2::dot ( grVec2 const& vec_a, grVec2 const& vec_b )
{
    return vec_a.x * vec_b.x + vec_a.y * vec_b.y;
}

r32 grVec2::angle ( grVec2 const& vec_a )
{
    return std::atan2( vec_a.y, vec_a.x );
}

r32 grVec2::angle ( grVec2 const& vec_a, grVec2 const& vec_b )
{
    return angle( vec_b - vec_a );
}

r32 grVec2::angle ( grVec2 const& vec_a, grVec2 const& vec_b, grVec2 const& vec_c )
{
    return angle( vec_a, vec_b ) - angle( vec_b, vec_c );
}

grVec2 grVec2::unit ( grVec2 const& vec_a )
{
    r32 vec_a_length = length( vec_a );
    return grVec2( vec_a.x / vec_a_length, vec_a.y / vec_a_length );
}

grVec2 grVec2::rotate ( grVec2 const& vec_a, r32 angle )
{
    grVec2 out( vec_a.x, vec_a.y );
    out.rotate( angle );
    return out;
}

grVec2 grVec2::rot_about ( grVec2 const& vec_a, grVec2 const& vec_b, r32 angle )
{
    return vec_b + rotate( vec_a - vec_b, angle );
}

grVec2 grVec2::perp ( grVec2 const& vec_a )
{
    return grVec2( -vec_a.y, vec_a.x );
}


std::ostream & operator<<(std::ostream& out, grVec2 const& vec)
{
    out << "{ " << std::to_string(vec.x) << ", " << std::to_string(vec.y) << " }";
    return out;
}


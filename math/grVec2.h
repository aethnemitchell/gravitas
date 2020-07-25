// grVec2.h
#ifndef GRVEC2_H
#define GRVEC2_H

#include <iostream>
#include "../common/grTypes.h"

struct grVec2
{
    union 
    {
		r32 vec[2];
		struct
		{
            r32 x;
            r32 y;
		};
	};

    // constructors

    grVec2 ( );
    grVec2 ( r32 x_, r32 y_ ); 
    grVec2 ( r32 x_, r32 y_, r32 len ); // vector in direction=[x,y] and of length=len

    // methods

    void zero   ( );
    void assign ( r32 x_, r32 y_ );
    void rotate ( r32 angle );

    // operators

    grVec2  operator-       ( void ) const;

    r32& operator[]      ( int i );
    r32  operator[]      ( int i ) const;

    grVec2 const operator+ ( grVec2 const& r_operand ) const;
    grVec2 const operator- ( grVec2 const& r_operand ) const;
    grVec2 const operator* ( r32 r_operand ) const;
    grVec2 const operator/ ( r32 r_operand ) const;

    grVec2& operator+=      ( grVec2 const& r_operand );
    grVec2& operator-=      ( grVec2 const& r_operand );
    grVec2& operator*=      ( r32 r_operand );
    grVec2& operator/=      ( r32 r_operand );

    static r32     length      ( grVec2 const& vec_a );
    static r32     distance    ( grVec2 const& vec_a, grVec2 const& vec_b );
    static r32     dot         ( grVec2 const& vec_a, grVec2 const& vec_b );
    static r32     angle       ( grVec2 const& vec_a ); // from +x
    static r32     angle       ( grVec2 const& vec_a, grVec2 const& vec_b );
    static r32     angle       ( grVec2 const& vec_a, grVec2 const& vec_b, grVec2 const& vec_c );
    static int     orientation ( grVec2 const& vec_a, grVec2 const& vec_b, grVec2 const& vec_c );

    static grVec2  unit        ( grVec2 const& vec_a );
    static grVec2  rotate      ( grVec2 const& vec_a, r32 angle );
    static grVec2  rot_about   ( grVec2 const& vec_a, grVec2 const& vec_b, r32 angle );
    static grVec2  perp        ( grVec2 const& vec_a );
};

std::ostream & operator<<(std::ostream& out, grVec2 const& vec);

#endif


// grVec2.h

#ifndef GRVEC2_H
#define GRVEC2_H

#include "../common/grTypes.h"

struct grVec2
{
    union 
    {
		r32 vec[2]; // might get rid of this
		struct
		{
			r32 x;
		    r32 y;
		};
	};

    // constructors

    grVec2 ( );
    grVec2 ( r32 x_, r32 y_ ); 
    // constructor for vector of arbitrary length from a direction @todo implement
    // grVec2 ( r32 x_, r32 y_, r32 len );

    // methods

    void zero   ( );
    void assign ( r32 x_, r32 y_ );

    // operators

    grVec2  operator-       ( void ) const;

    grVec2& operator[]      ( int i );
    grVec2  operator[]      ( int i ) const;
    
    const grVec2& operator+ ( const grVec2& r_operand ) const;
    const grVec2& operator- ( const grVec2& r_operand ) const;
    const grVec2& operator* ( r32 r_operand ) const;
    const grVec2& operator/ ( r32 r_operand ) const;

    grVec2& operator+=      ( const grVec2& r_operand );
    grVec2& operator-=      ( const grVec2& r_operand );
    grVec2& operator*=      ( r32 r_operand );
    grVec2& operator/=      ( r32 r_operand );
};

/*
r32     len     ( grVec2& const vec );
r32     dist    ( grVec2& const vec_a, grVec2& const vec_b );
r32     dot     ( grVec2& const vec_a, grVec2& const vec_b );

grVec2& cross   ( grVec2& const vec_a, grVec2& const vec_b );
grVec2& unit    ( grVec2& const vec );
*/

#endif

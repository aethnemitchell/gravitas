// main.cpp

#include "../math/grVec2.h"
#include "../math/grCvPoly2.h"
#include "../common/grTypes.h"
#include <iostream>

r32 random( r32 lower, r32 upper )
{
    return lower + static_cast <r32> (rand()) /( static_cast <r32> (RAND_MAX/(upper - lower)));
}


int main (void) {

    {
        grVec2 v1(1.0, 2.0);
        grVec2 v2(-3.0, -2.0);

        grVec2 v3(0.0, 0.0);
        grVec2 v4(0.5, 1.0);
        grVec2 v5(1.0, 2.5);

        v2 += v1;
        std::cout << v2 << std::endl;
        v2.rotate(M_PI / 2);
        std::cout << v2 << std::endl;
        v2.rotate(M_PI / 2);
        std::cout << v2 << std::endl;
        v2.rotate(M_PI / 2);
        std::cout << v2 << std::endl;
        std::cout << v1 << std::endl;
        std::cout << grVec2::distance(v2, v1) << std::endl;
        std::cout << std::endl;
        std::cout << (grVec2::angle( v3, v4, v5 ) * 180/M_PI) << std::endl;
    }

    {
        std::vector<grVec2> points;
        points.push_back( grVec2( 1.0, 1.0 ) );
        points.push_back( grVec2( 1.0, -1.0 ) );
        points.push_back( grVec2( -1.000, -1.0 ) );
        points.push_back( grVec2( -1.0, 1.0 ) );
        points.push_back( grVec2( 0.0, 0.0 ) );

        for (auto p : points)
            std::cout << p << std::endl;

        std::cout << "making convex set..." << std::endl;

        auto hull = grCvPoly2( points );

        for (auto p : hull.vertices)
            std::cout << p << std::endl;

        std::cout << "centroid: " << hull.centroid << std::endl;
        std::cout << std::endl;
    }

    {
        std::vector<grVec2> points;
        points.push_back( grVec2( -5.0, 0.0 ) );
        points.push_back( grVec2( 5.0, 0.0 ) );
        points.push_back( grVec2( 0.0, 5.0 ) );
        points.push_back( grVec2( 0.0, 0.0 ) );

        for (auto p : points)
            std::cout << p << std::endl;

        std::cout << "making convex set..." << std::endl;

        auto hull = grCvPoly2( points );

        for (auto p : hull.vertices)
            std::cout << p << std::endl;

        std::cout << "centroid: " << hull.centroid << std::endl;
        std::cout << std::endl;
    }

    {
        std::vector<grVec2> points;
        for (int i=0; i<10; i++)
        {
            points.push_back( grVec2( random(-5.0, 5.0), random(-5.0, 5.0) ) );
        }

        for (auto p : points)
            std::cout << p << std::endl;

        std::cout << "making convex set..." << std::endl;

        auto hull = grCvPoly2( points );

        for (auto p : hull.vertices)
            std::cout << p << std::endl;

        std::cout << "centroid: " << hull.centroid << std::endl;
        std::cout << std::endl;
    }

    return 0;
}


// main.cpp

#include "../math/grVec2.h"
#include <iostream>

int main (void) {

    grVec2 v1(1.0, 2.0);
    grVec2 v2(-3.0, -2.0);

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

    return 0;
}


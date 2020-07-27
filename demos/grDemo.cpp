#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "../math/grVec2.h"
#include "../math/grCvPoly2.h"
#include "../components/grEntity.h"


r32 random( r32 lower, r32 upper )
{
    return lower + static_cast <r32> (rand()) /( static_cast <r32> (RAND_MAX/(upper - lower)));
}

int main()
{
    time_t current_time;
    time(&current_time);

    srand(current_time);
    sf::RenderWindow window(sf::VideoMode(800, 600), "grDemo");


    std::vector<grVec2> points;
    std::vector<sf::CircleShape> sf_circs;
    for (size_t i=0; i<6; i++)
    {
        points.push_back( grVec2( random(150.0, 200.0), random(340.0, 400.0) ) );
        sf::CircleShape new_circ(2.0f);
        new_circ.setPosition( points.back().x - 1.0, points.back().y - 1.0 );
        new_circ.setFillColor(sf::Color::Red);
        sf_circs.push_back(new_circ);
    }

    auto hull = grCvPoly2( points );

    grEntity ent(hull);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        ent.render_c->draw(window);
        window.display();
    }

    return 0;
}


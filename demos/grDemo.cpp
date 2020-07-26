#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "../math/grVec2.h"
#include "../math/grCvPoly2.h"

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

    /*
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    */

    std::vector<grVec2> points;
    std::vector<sf::CircleShape> sf_circs;
    for (size_t i=0; i<10; i++)
    {
        points.push_back( grVec2( random(200.0, 600.0), random(100.0, 500.0) ) );
        sf::CircleShape new_circ(4.0f);
        new_circ.setPosition( points.back().x - 2.0, points.back().y - 2.0 );
        new_circ.setFillColor(sf::Color::Red);
        sf_circs.push_back(new_circ);
    }

    auto hull = grCvPoly2( points );
    
    sf::CircleShape centroid_circ(8.0f);
    centroid_circ.setPosition( hull.centroid.x - 4.0, hull.centroid.y - 4.0 );
    centroid_circ.setFillColor(sf::Color::Blue);


    sf::ConvexShape polygon;
    polygon.setPointCount(hull.vertices.size());
    for (size_t i=0; i<hull.vertices.size(); i++)
    {
        polygon.setPoint(i, sf::Vector2f(hull.vertices[i].x, hull.vertices[i].y));
    }

    polygon.setFillColor(sf::Color(80, 80, 80));
    polygon.setPosition(0, 0);
    
    window.draw(polygon);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(polygon);
        for (auto c : sf_circs)
            window.draw(c);
        window.draw(centroid_circ);
        window.display();
    }

    return 0;
}


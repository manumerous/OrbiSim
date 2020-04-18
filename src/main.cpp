#include <SFML/Graphics.hpp>
#include "celestial_body.hpp"
#include "Eigen/Dense"
#include <iostream>
#include <math.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace Eigen;
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 1200), "OrbiSim: Orbital Simulator!");

    CelestialBody all_bodies[2];

    CelestialBody fixed_body(50000000000.0f, 25.0f);
    Vector3d initialpos_fixed(600.0f, 600.0, 0);
    fixed_body.setPosition(initialpos_fixed);
    all_bodies[1] = fixed_body;

    CelestialBody moving_body(5.0f, 10.0f);
    Vector3d initialpos_moving(200.0f, 200.f, 0.0);
    moving_body.setPosition(initialpos_moving);
    all_bodies[2] = moving_body;

    Vector3d mouse_pos(0, 0, 0);
    float time_step = 0.1;

    while (window.isOpen())
    {
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                // std::cout << "New Window Size: " << evnt.size.width << ", " << evnt.size.height << std::endl;
                printf("New window size: %i, %i\n", evnt.size.width, evnt.size.height);
                break;
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            mouse_pos(0) = static_cast<double>(sf::Mouse::getPosition(window).x);
            mouse_pos(1) = static_cast<double>(sf::Mouse::getPosition(window).y);
            fixed_body.setPosition(mouse_pos);
        }

        moving_body.updateVelocity(all_bodies, time_step);
        moving_body.updatePosition(time_step);

        std::cout << "New Position of body: (" << moving_body.pos_[0] << ", " << moving_body.pos_[1] << ")" << std::endl;
        window.clear();
        window.draw(fixed_body.shape_);
        window.draw(moving_body.shape_);
        window.display();

        sleep(0.1);
    }

    return 0;
}
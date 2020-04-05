#include <SFML/Graphics.hpp>
#include "CelestialBody.hpp"
#include "MovingCelestialBody.hpp"
#include <iostream>
#include <math.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

// Gravitational Constant in N*m^2/kg^2
float G = 6.67430f * pow(10.0f, -11.0f);

float * calculate_force(MovingCelestialBody body1, CelestialBody body2)
{
    float r[dimensionality];
    float abs_r = 0;
    for (int i = 0; i < dimensionality; i++)
    {
        r[i] = body2.pos[i] - body1.pos[i];
        abs_r = r[i] * r[i];
    }
    abs_r = sqrt(abs_r);
    float force_magnitude = (G*body1.mass*body2.mass)/(abs_r*abs_r);
    float force_vector[dimensionality]; 
    for (int i = 0; i < dimensionality; i++)
    {
        force_vector[i] = r[i]*force_magnitude/abs_r;
    }
    return force_vector;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 1200), "OrbiSim: Orbital Simulator!");

    CelestialBody fixedBody(5000000.0f, 25.0f);
    float initialpos_fixed[] = {600.0f, 600.f};
    fixedBody.setPosition(initialpos_fixed);

    MovingCelestialBody movingBody(5.0f, 10.0f);
    float initialpos_moving[] = {200.0f, 600.f};
    movingBody.setPosition(initialpos_moving);

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
            float mousePos[dimensionality] = {static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)};
            fixedBody.setPosition(mousePos);
        }

        float *force;
        force = calculate_force(movingBody, fixedBody);
        movingBody.applyForce(force);

        window.clear();
        window.draw(fixedBody.shape);
        window.draw(movingBody.shape);
        window.display();

        sleep(0.01);
    }

    return 0;
}

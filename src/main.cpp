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

float euclidianDist(float pos1[dimensionality], float pos2[dimensionality])
{
    float absSum = 0;
    for (int i = 0; i < dimensionality; i++)
    {
        absSum += (pos1[i]-pos2[i]) * (pos1[i]-pos2[i]);
    }  
    float abs = sqrt(absSum);
    return abs;
}

void calculate_force(MovingCelestialBody body1, CelestialBody body2, float (&force)[dimensionality])
{
    float r[dimensionality];
    float abs = euclidianDist(body2.pos, body1.pos);
    for (int i = 0; i < dimensionality; i++)
    {
        r[i] = body2.pos[i] - body1.pos[i];
    }
    float force_magnitude = (G*body1.mass*body2.mass)/(abs*abs);
    for (int i = 0; i < dimensionality; i++)
    {
        force[i] = r[i]*force_magnitude/abs;
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 1200), "OrbiSim: Orbital Simulator!");

    CelestialBody fixedBody(50000000000.0f, 25.0f);
    float initialpos_fixed[] = {600.0f, 600.f};
    fixedBody.setPosition(initialpos_fixed);

    MovingCelestialBody movingBody(5.0f, 10.0f);
    float initialpos_moving[] = {200.0f, 200.f};
    movingBody.setPosition(initialpos_moving);

    float force[]={0.1,0.1};

    cout << G << std::endl;

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

        
        calculate_force(movingBody, fixedBody, force);
        movingBody.applyForce(force);

        std::cout << "Force applying on body: (" << force[0] << ", " << force[1] << ")" << std::endl;
        std::cout << "New Position of body: (" << movingBody.pos[0] << ", " << movingBody.pos[1] << ")" << std::endl;
        window.clear();
        window.draw(fixedBody.shape);
        window.draw(movingBody.shape);
        window.display();

        sleep(0.1);
    }

    return 0;
}
#include "CelestialBody.hpp"
#include <SFML/Graphics.hpp>

void CelestialBody::setPosition(float new_pos[dimensionality])
{
    for (int i = 0; i < dimensionality; i++)
    {
        pos[i] = new_pos[i];
    }
    if (dimensionality == 2)
        shape.setPosition(sf::Vector2f(new_pos[0], new_pos[1]));    
    else
    {
        printf("ERROR: Dimensionality of vector does not match");
    }
}

CelestialBody::CelestialBody(float bodyMass=50.0f, float bodyRadius=50.0f):
    mass(bodyMass),
    shape(bodyRadius),
    radius(bodyRadius),
    pos{100.f, 100.f},
    vel{0.f, 0.f},
    acc{0.f, 0.f}
{
    shape.setOrigin(radius, radius);
}
#include "celestial_body.hpp"
#include <SFML/Graphics.hpp>

void CelestialBody::setPosition(float new_pos[dimensionality])
{
    for (int i = 0; i < dimensionality; i++)
    {
        pos_[i] = new_pos[i];
    }
    if (dimensionality == 2)
        shape_.setPosition(sf::Vector2f(new_pos[0], new_pos[1]));    
    else
    {
        printf("ERROR: Dimensionality of vector does not match");
    }
}

CelestialBody::CelestialBody(float bodyMass, float bodyRadius):
    mass_(bodyMass),
    shape_(bodyRadius),
    radius_(bodyRadius),
    pos_{100.f, 100.f},
    vel_{0.f, 0.f},
    acc_{0.f, 0.f}
{
    shape_.setOrigin(radius_, radius_);
}
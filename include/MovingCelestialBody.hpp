#include "CelestialBody.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

#pragma once

class MovingCelestialBody : public CelestialBody
{
private:
    //Private Attributes:

    //Private Methods:

public:
    //Public Attributes:

    //Public Methods:
    void applyForce(float force[dimensionality]);

    //Constructor
    MovingCelestialBody(float bodyMass=50.0f, float bodyRadius=50.0f);
};
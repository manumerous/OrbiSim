#include <SFML/Graphics.hpp>

#pragma once

#define dimensionality 2

class CelestialBody
{
private:
    //Private Attributes:

    //Private Methods:
public:
    //Public Attributes:
    sf::CircleShape shape_;

    float pos_[dimensionality];
    float vel_[dimensionality];
    float acc_[dimensionality];

    float mass_;
    float radius_;

    //Public Methods:
    void setPosition(float new_pos[dimensionality]);

    //Constructor
    CelestialBody(float bodyMass=50.0f, float bodyRadius=50.0f);
};

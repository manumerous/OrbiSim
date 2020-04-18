#include <SFML/Graphics.hpp>
#include "Eigen/Dense"

#pragma once

using namespace Eigen;

class CelestialBody
{
private:
    //Private Attributes:

    //Private Methods:
public:
    //Public Attributes:
    sf::CircleShape shape_;

    Vector3d pos_;
    Vector3d vel_;
    Vector3d acc_;

    float mass_;
    float radius_;

    //Public Methods:
    void setPosition(const Vector3d new_pos);
    void updateVelocity(const CelestialBody all_bodies[], const float time_step);
    void updatePosition(const float time_step);

    //Constructor
    CelestialBody(float bodyMass=50.0f, float bodyRadius=50.0f);
};

#include <SFML/Graphics.hpp>
#include "Eigen/Dense"
#include <iostream>

#pragma once

class CelestialBody
{
private:
    //Private Attributes:

    //Private Methods:
public:
    //Public Attributes:
    sf::CircleShape shape_;

    Eigen::Vector3d pos_;
    Eigen::Vector3d vel_;
    Eigen::Vector3d acc_;

    float mass_;
    float radius_;

    //Public Methods:
    void setPosition(Eigen::Vector3d new_pos);
    void updateVelocity(const CelestialBody *all_bodies[], int body_count, float time_step);
    void updatePosition(float time_step);

    //Constructor
    CelestialBody(float bodyMass=50.0f, float bodyRadius=50.0f);
};

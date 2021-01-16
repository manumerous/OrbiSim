#include <SFML/Graphics.hpp>
#include <eigen3/Eigen/Dense>
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
    const static int horizon_length_ = 100;

    Eigen::Vector3d pos_;
    Eigen::Vector3d vel_;
    Eigen::Vector3d acc_;

    Eigen::Vector3d pos_predict_[horizon_length_];
    Eigen::Vector3d vel_predict_[horizon_length_];
    Eigen::Vector3d acc_predict_[horizon_length_];
    sf::Vector2f predicted_positions[horizon_length_];

    float mass_;
    float radius_;

    //Public Methods:
    void setPosition(Eigen::Vector3d new_pos);
    void updateVelocity(const CelestialBody *all_bodies[], int body_count, float time_step);
    void updatePosition(float time_step);
    void predictOrbit(const CelestialBody *all_bodies[], int body_count, float time_step);

    //Constructor
    CelestialBody(float bodyMass = 50.0f, float bodyRadius = 50.0f);
};

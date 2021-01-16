#include <SFML/Graphics.hpp>
#include <eigen3/Eigen/Dense>
#include <iostream>
#include "celestial_body.hpp"

// Gravitational Constant in N*m^2/kg^2
float G = 6.67430f * pow(10.0f, -11.0f);

void CelestialBody::setPosition(Eigen::Vector3d new_pos)
{
    pos_ = new_pos;
    shape_.setPosition(sf::Vector2f(pos_(0), pos_(1)));
}

void CelestialBody::updateVelocity(const CelestialBody *all_bodies[], int body_count, float time_step)
{
    Eigen::Vector3d force(0, 0, 0);
    for (int i = 0; i < body_count; i++)
    {

        CelestialBody other_body = *all_bodies[i];
        if (all_bodies[i] != this)
        {
            Eigen::Vector3d r = other_body.pos_ - pos_;
            Eigen::Vector3d r_unit = r / (r.norm());
            force = force + r_unit * (G * other_body.mass_ * mass_) / (r.norm() * r.norm());
        }
    }
    acc_ = force / mass_;
    vel_ = vel_ + acc_ * time_step;

    acc_predict_[0] = acc_;
    vel_predict_[0] = vel_;
}

void CelestialBody::updatePosition(float time_step)
{
    pos_ += vel_ * time_step;
    shape_.setPosition(sf::Vector2f(pos_(0), pos_(1)));
    pos_predict_[0] = pos_;
}

void CelestialBody::predictOrbit(const CelestialBody *all_bodies[], int body_count, float time_step)
{
    Eigen::Vector3d current_pos(pos_(0), pos_(1), 0.0);
    for (int k = 0; k <= (horizon_length_ - 1); k++)
    {
        Eigen::Vector3d force(0, 0, 0);
        CelestialBody other_body = *all_bodies[0];
        if (all_bodies[0] != this)
        {
            Eigen::Vector3d r = other_body.pos_ - current_pos;
            Eigen::Vector3d r_unit = r / (r.norm());
            force = force + r_unit * (G * other_body.mass_ * mass_) / (r.norm() * r.norm());
        }

        acc_predict_[k] = force / mass_;
        vel_predict_[k] = vel_predict_[k] + acc_predict_[k] * time_step;
        pos_predict_[k] = pos_predict_[k] + vel_predict_[k] * time_step;
        current_pos = pos_predict_[k];
        predicted_positions[k] = sf::Vector2f(current_pos(0), current_pos(1));
    }
}

CelestialBody::CelestialBody(float bodyMass, float bodyRadius) : mass_(bodyMass),
                                                                 shape_(bodyRadius),
                                                                 radius_(bodyRadius)
{
    shape_.setOrigin(radius_, radius_);
    pos_ << 100.0, 100.0, 0.0;
    vel_ << 0.0, 0.0, 0.0;
    acc_ << 0.0, 0.0, 0.0;
}
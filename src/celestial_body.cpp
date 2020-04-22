#include <SFML/Graphics.hpp>
#include "Eigen/Dense"
#include <iostream>

#include "celestial_body.hpp"

using namespace Eigen;
using namespace std;

// Gravitational Constant in N*m^2/kg^2
float G = 6.67430f * pow(10.0f, -11.0f);

void CelestialBody::setPosition(Vector3d new_pos)
{
    pos_ = new_pos;
    shape_.setPosition(sf::Vector2f(pos_(0), pos_(1)));
}

void CelestialBody::updateVelocity(CelestialBody all_bodies[], float time_step)
{
    //int body_count = sizeof(all_bodies) / sizeof(*all_bodies);
    int body_count = 2;
    Vector3d force(0, 0, 0);
    for (int i = 0; i < body_count; i++)
    {
        
        CelestialBody other_body = all_bodies[i];
        // if (&other_body != this)
        if (i != 1)
        {
            std::cout << i << endl;
            Vector3d r = other_body.pos_ - pos_;
            Vector3d r_unit = r / (r.norm());
            force = force + r_unit * (G * other_body.mass_ * mass_) / (r.norm() * r.norm());
        }
    }
    acc_ = force / mass_;
    vel_ = vel_ + acc_ * time_step;
}

void CelestialBody::updatePosition(float time_step)
{
    pos_ += vel_ * time_step;
    shape_.setPosition(sf::Vector2f(pos_(0), pos_(1)));
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
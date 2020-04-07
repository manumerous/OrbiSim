#include "moving_celestial_body.hpp"
#include <SFML/Graphics.hpp>

void MovingCelestialBody::applyForce(float force[dimensionality])
{
    for (int i = 0; i < dimensionality; i++)
    {
        acc_[i] = force[i]/mass_;;
        vel_[i] += acc_[i]*0.1;
        pos_[i] += vel_[i]*0.1;
    }
    setPosition(pos_);
    
}

MovingCelestialBody::MovingCelestialBody(float bodyMass, float bodyRadius):
CelestialBody{bodyMass, bodyRadius}
{

}
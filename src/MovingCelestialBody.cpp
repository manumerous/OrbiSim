#include "MovingCelestialBody.hpp"
#include <SFML/Graphics.hpp>

void MovingCelestialBody::applyForce(float force[dimensionality])
{
    for (int i = 0; i < dimensionality; i++)
    {
        acc[i] = force[i]/mass;;
        vel[i] += acc[i]*0.01;
        pos[i] += vel[i]*0.01;
    }
    setPosition(pos);
    
}

MovingCelestialBody::MovingCelestialBody(float bodyMass, float bodyRadius):
CelestialBody{bodyMass, bodyRadius}
{

}
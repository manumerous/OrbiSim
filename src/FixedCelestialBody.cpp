#include "FixedCelestialBody.hpp"
#include <SFML/Graphics.hpp>

FixedCelestialBody::FixedCelestialBody(double mass):
bodyMass(mass),
pos(sf::Vector2f(-100.f, -100.f)),
vel(sf::Vector2f(0.f, 0.f)),
acc(sf::Vector2f(0.f, 0.f))
{

}
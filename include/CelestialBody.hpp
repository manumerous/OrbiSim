#include <SFML/Graphics.hpp>

#define dimensionality 2

class CelestialBody
{
private:
    //Private Attributes:

    //Private Methods:
public:
    //Public Attributes:
    sf::CircleShape shape;

    float pos[dimensionality];
    float vel[dimensionality];
    float acc[dimensionality];

    float mass;
    float radius;

    //Public Methods:
    void setPosition(float new_pos[dimensionality]);

    //Constructor
    CelestialBody(float bodyMass, float bodyRadius);
};
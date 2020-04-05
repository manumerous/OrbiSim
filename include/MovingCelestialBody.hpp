#include "CelestialBody.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class MovingCelestialBody : public CelestialBody
{
    public:

        //Public Attributes:

        //Public Methods:
        void applyForce(float force)

        //Constructor
        MovingCelestialBody();

    private:

        //Private Attributes:

        float mass;
        float radius;

        //Private Methods:

}
#include <SFML/Graphics.hpp>

const int dimensionality = 2;

    class CelestialBody {
    public:

        //Public Attributes:
        sf::CircleShape shape;

        float pos[dimensionality];
        float vel[dimensionality];
        float acc[dimensionality];

        //Public Methods:
        void setPosition(float new_pos[dimensionality]);

        //Constructor
        CelestialBody(float bodyMass, float bodyRadius);

    private:

        //Private Attributes:
        float mass;
        float radius;

        //Private Methods:

};

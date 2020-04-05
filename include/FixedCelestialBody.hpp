#include <SFML/Graphics.hpp>


class FixedCelestialBody {
public:

    //Public Attributes:

    sf::CircleShape body();

    double bodyMass;

    sf::Vector2f pos;
    sf::Vector2f vel;
    sf::Vector2f acc;

    //Public Methods:

    //Constructor
    FixedCelestialBody(double mass);

private:

    //Private Attributes:



    //Private Methods:

};

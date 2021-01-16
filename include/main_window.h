#include <SFML/Graphics.hpp>

class MainWindow
{
private:
    //Private Attributes:
    sf::RenderWindow window(sf::VideoMode(1200, 1200), "OrbiSim: Orbital Simulator!");

    //Private Methods:
public:
    //Public Attributes:

    //Public Methods:
    drawDottedLine(sf::Vector2f *position_list, sf::RenderWindow window);

    //Constructor
    MainWindow(float bodyMass = 50.0f, float bodyRadius = 50.0f);
};
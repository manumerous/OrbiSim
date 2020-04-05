#include <SFML/Graphics.hpp>
#include "CelestialBody.hpp"
#include <iostream>

using namespace std;

sf::RenderWindow window(sf::VideoMode(1200, 1200), "OrbiSim: Orbital Simulator!");

void drawCO(CelestialBody body)
{

    window.draw(body.shape);
}

int main()
{
    CelestialBody testbody(50.0f, 25.0f);

    while (window.isOpen())
    {
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                // std::cout << "New Window Size: " << evnt.size.width << ", " << evnt.size.height << std::endl;
                printf("New window size: %i, %i\n", evnt.size.width, evnt.size.height);
                break;
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            float mousePos[dimensionality] = {static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)};
            testbody.setPosition(mousePos);
        }

        window.clear();
        drawCO(testbody);
        window.display();
    }

    return 0;
}

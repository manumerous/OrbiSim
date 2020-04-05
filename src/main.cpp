#include <SFML/Graphics.hpp>
#include "FixedCelestialBody.hpp"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "OrbiSim: Orbital Simulator!");  
    sf::CircleShape player(50.f);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::White);
    player.setOrigin(50.f,50.f);

    FixedCelestialBody testbody(50.0);

    while (window.isOpen())
    {
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            switch(evnt.type)
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

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            player.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
        }

        window.clear();
        window.draw(shape);
        window.draw(player);
        window.display();
    }

    return 0;
}

#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "OrbiSim: Orbital Simulator!");
    
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Black);

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
            case sf::Event::TextEntered:
                if(evnt.text.unicode < 128)
                {
                    printf("%c", evnt.text.unicode);
                }
                    
            }
        }

        window.clear(sf::Color::White);
        window.draw(shape);
        window.display();
    }

    return 0;
}

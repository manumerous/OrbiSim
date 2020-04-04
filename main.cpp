#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "OrbiSim: Orbital Simulator!");  
    sf::RectangleShape player(sf::Vector2f(100,100));
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::White);
    player.setOrigin(50.f,50.f);

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
            // case sf::Event::TextEntered:
                // if(evnt.text.unicode < 128)
                // {
                //     printf("%c", evnt.text.unicode);
                // }
                    
            }
        }

        // if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        // {
        //     player.move(-0.1f,0.0f);
        // }

        // if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        // {
        //     player.move(0.0f,0.1f);
        // }

        // if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        // {
        //     player.move(0.1f,0.0f);
        // }

        // if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        // {
        //     player.move(0.0f,-0.1f);
        // }

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


void MainWindow::drawDottedLine(sf::Vector2f *position_list, sf::RenderWindow window)
{
    sf::CircleShape dot;
    dot.setRadius(2);
    dot.setOutlineColor(sf::Color::Red);
    for (int i; i <= sizeof(position_list) / sizeof(position_list[0]); i++)
    {
        dot.setPosition(position_list[i]);
        window.draw(dot);
    }
}
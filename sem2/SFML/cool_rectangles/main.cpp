#include "CustomRectangleShape.h"
#include <iostream>
int main()
{
    int maxHeight = 600;
    int maxWidth = 800;
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(maxWidth, maxHeight), "Cool rectangles");
    sf::Clock clock;
    std::vector<CustomRectangleShape> rectangles;

    for (int i = 0; i < 10; i++)
    {
        sf::Vector2f size(120.0, 60.0);
        sf::Vector2f position(std::rand() % (window.getSize().x - 120), std::rand() % (window.getSize().y - 60));
        rectangles.emplace_back(CustomRectangleShape(size, position));
    }
    int velocity_r = 10;
    for (auto &rec : rectangles)
    {
        rec.setFillColor(sf::Color(124, 124, 124));
        rec.setBounds(0, window.getSize().x, 0, window.getSize().y);
        rec.setSpeed(200, 250, velocity_r += 5);

    }
    rectangles[0].unselect();
    while (window.isOpen())
    {
        sf::Event event;
        sf::Time elapsed = clock.restart();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            for (auto &rec : rectangles)
            {
                rec.selected_mouse(window, event);
            }
        }
        window.clear(sf::Color::Black);
        for (auto &rec : rectangles)
        {
            rec.animate(elapsed);
        }

        for (const auto &rec : rectangles)
        {
            window.draw(rec);
        }
        window.display();
    }

    return 0;
}

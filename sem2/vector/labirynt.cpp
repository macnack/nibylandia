#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
#include <cmath>
#include <time.h>

int main() {
    int maxHeight = 600;
    int maxWidth = 800;
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(maxWidth, maxHeight), "My window");
    // create some shapes
    sf::Clock clock;
    std::vector<std::unique_ptr<sf::Drawable>> shapes;
    sf::Texture grass_texture;

    if (!grass_texture.loadFromFile("/home/maciek/work/tekstury/teksturki/grass.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    grass_texture.setRepeated(true);
    sf::Sprite background;
    background.setTexture(grass_texture);
    background.setTextureRect(sf::IntRect(0, 0, 800, 600));

    sf::Texture wall_texture;
    if (!wall_texture.loadFromFile("/home/maciek/work/tekstury/teksturki/wall.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    wall_texture.setRepeated(true);
    std::unique_ptr<sf::Sprite> wall = std::make_unique<sf::Sprite>();
    wall->setTexture(wall_texture);
    wall->setPosition(100,150);
    wall->setTextureRect(sf::IntRect(0,0,50,300));
    shapes.emplace_back(std::move(wall));
    std::unique_ptr<sf::Sprite> wall2 = std::make_unique<sf::Sprite>();
    wall2->setTexture(wall_texture);
    wall2->setPosition(250,435);
    wall2->setTextureRect(sf::IntRect(0,0,300,50));
    shapes.emplace_back(std::move(wall2));
    std::unique_ptr<sf::Sprite> wall3 = std::make_unique<sf::Sprite>();
    wall3->setTexture(wall_texture);
    wall3->setPosition(250,150);
    wall3->setTextureRect(sf::IntRect(0,0,50,200));
    shapes.emplace_back(std::move(wall3));

    sf::Texture guy;
    if (!guy.loadFromFile("/home/maciek/work/tekstury/teksturki/guy.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    sf::Sprite player;
    player.setTexture(guy);
    player.setPosition(300,300);


    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        sf::Clock clock;
        //sf::Time elapsed = clock.restart();
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::Time elapsed = clock.restart();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {

            player.move(0, -10000 * elapsed.asSeconds());
            for(auto &s :shapes){
             sf::Sprite *wall_as_a_sprite = dynamic_cast<sf::Sprite *>(s.get());

            if (wall_as_a_sprite->getGlobalBounds().intersects(player.getGlobalBounds()))
            {
                player.move(0, 10000 * elapsed.asSeconds());
            }
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            player.move(0, 10000 * elapsed.asSeconds());
            for(auto &s :shapes){
             sf::Sprite *wall_as_a_sprite = dynamic_cast<sf::Sprite *>(s.get());
            if (wall_as_a_sprite->getGlobalBounds().intersects(player.getGlobalBounds()))
            {
                player.move(0, -10000 * elapsed.asSeconds());
            }
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            player.move(-10000 * elapsed.asSeconds(), 0 );
            for(auto &s :shapes){
             sf::Sprite *wall_as_a_sprite = dynamic_cast<sf::Sprite *>(s.get());
            if (wall_as_a_sprite->getGlobalBounds().intersects(player.getGlobalBounds()))
            {
                player.move(10000 * elapsed.asSeconds(),0);
            }
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            player.move(10000 * elapsed.asSeconds(), 0 );
            for(auto &s :shapes){
             sf::Sprite *wall_as_a_sprite = dynamic_cast<sf::Sprite *>(s.get());
            if (wall_as_a_sprite->getGlobalBounds().intersects(player.getGlobalBounds()))
            {
                player.move(-10000 * elapsed.asSeconds(), 0 );
            }
            }
        }
        window.clear(sf::Color::Black);

        window.draw(background);
        for(const auto &s : shapes) {
            window.draw(*s);
        }

        window.draw(player);
        // end the current frame
        window.display();
    }

    return 0;
}

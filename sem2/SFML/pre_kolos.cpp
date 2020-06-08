#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <memory>
#include <vector>
#include <string>

class Bohater : public sf::Sprite{
public:
    Bohater(const sf::Texture &texture) : sf::Sprite::Sprite(texture){
        this->setPosition(15,500);
        bound = this->getGlobalBounds();
        //        std::cerr << "Top: " << bound.top << " H: " << bound.height << " \n"
        //                  << "left: "<< bound.left << " W: " << bound.width << " \n";
    }
    virtual ~Bohater(){
        std::cout << "Game over" << std::endl;
    }
    void spawn(){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
            this->setPosition(15,500);
        }
    }
    void hero_move(const sf::Vector2i &mouse_pos){
        if( bound.top < mouse_pos.y && bound.top + bound.height > mouse_pos.y){
            if( bound.left+bound.width < mouse_pos.x){
                std::cerr << "prawo" << std::endl;
                dir = sf::Vector2f(1.f,0.f);//right
            }else {
                dir = sf::Vector2f(-1.f,0.f);//left
            }
        }
        if( bound.left < mouse_pos.x && bound.left + bound.width > mouse_pos.x){
            if( bound.top < mouse_pos.y){
                dir = sf::Vector2f(0.f,1.f);//down
            }else{
                dir = sf::Vector2f(0.f,-1.f); //up
            }
        }
        if( bound.left > mouse_pos.x && bound.top > mouse_pos.y){
            dir = sf::Vector2f(-1.f,-1.f); //std::cerr << " lewa gora tutaj " << std::endl;
        }
        if ( bound.left > mouse_pos.x && bound.top+bound.height < mouse_pos.y){
            dir = sf::Vector2f(-1.f,1.f); //std::cerr << " lewy dol tutaj" << std::endl;
        }
        if ( bound.left + bound.width < mouse_pos.x && bound.top > mouse_pos.y){
            dir = sf::Vector2f(1.f,-1.f); //std::cerr << " prawa gora tutaj" << std::endl;
        }
        if ( bound.left + bound.width < mouse_pos.x && bound.top + bound.height < mouse_pos.y){
            dir = sf::Vector2f(1.f,1.f); //std::cerr << " prawa dol tutaj" << std::endl;
        }
        this->setPosition(bound.left += (10 * dir.x), bound.top += (10 * dir.y));
    }
    void updateCollisions(std::map<std::string, std::vector<std::unique_ptr<sf::Sprite>>> &mapka){
        for( auto &m : mapka){
            for(auto it= m.second.begin() ; it < m.second.end() ; ++it){
                if( (*it)->getGlobalBounds().intersects(bound)){
                    m.second.erase(it);
                    point -= 30;
                    std::cerr << "Straciles 30 punktow!" << std::endl;
                }
            }
        }
        if(bound.left < OX || bound.left + bound.width > length_x || bound.top < OY || bound.top + bound.height > length_y ){
            bound.top = 500;
            bound.left = 15;
            this->setPosition(bound.left,bound.top);
        }
    }
    void time(const float &dt){
        if(!win){
            point -= dt;
        }
    }
    int getPoint(){
        return int(point);
    }
    void is_win(const sf::RectangleShape &rect, sf::RenderWindow &window){
        if(rect.getGlobalBounds().intersects(bound) || point <= 0){
            win = true;
            std::string msg = "\nKoniec gry!\nTwoj wynik: " + std::to_string(int(point));
            std::cerr << msg << std::endl;
            window.close();
        }
    }
private:
    bool win = false;
    sf::FloatRect bound;
    sf::Vector2f dir;
    int OX = 10;
    int OY = 10;
    int length_x = 780;
    int length_y = 580;
    double point = 100;
};
class Potwor : public sf::Sprite{
public:
    Potwor(const sf::Texture &texture) : sf::Sprite::Sprite(texture){
        this->setPosition(rand()%650 + 95, rand()%550);
        this->setScale(0.1,0.1);
        bound = this->getGlobalBounds();
    }
    virtual ~Potwor(){
        std::cerr << "Jestem w destruktorze Potwor" << std::endl;
    }
    bool collected(){
        is_collected = !is_collected;
        return is_collected;
    }
    virtual void Dzialaj(const float &dt){
        dir = sf::Vector2i(rand()%3 - 1, rand()%3 - 1);
        velocity.x += dir.x * (dt * 0.2f);
        velocity.y += dir.x * (dt * 0.2f);
        this->move(velocity.x , velocity.y);
    }
private:
    bool is_collected = false;
    sf::Vector2i dir;
    sf::FloatRect bound;
    sf::Vector2f velocity;
};
class Bagno : public sf::Sprite{
public:
    Bagno(const sf::Texture &texture) : sf::Sprite::Sprite(texture){
        this->setPosition(rand()%650 + 95, rand()%550);
        this->setScale(0.1,0.1);
        bound = this->getGlobalBounds();
        this->setOrigin(bound.width/2.0, bound.height/2.0);
    }
    virtual ~Bagno(){
        std::cerr << "Jestem w destruktorze Bagno" << std::endl;
    }
    bool collected(){
        is_collected = !is_collected;
        return is_collected;
    }
    virtual void Dzialaj(const float &dt){
        float x=1, y=1;
        x += 0.09 * dt;
        y += 0.09 * dt;
        this->scale(x,y);
    };
private:
    bool is_collected = false;
    sf::Vector2i dir;
    sf::FloatRect bound;
};

int main() {
    srand (time(NULL));
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    sf::Texture hero_texture;
    if (!hero_texture.loadFromFile("tekstury/hero.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    sf::Texture monster_texture;
    if (!monster_texture.loadFromFile("tekstury/monster.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    sf::Texture swamp_texture;
    if (!swamp_texture.loadFromFile("tekstury/swamp.jpg")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    std::map<std::string, std::vector<std::unique_ptr<sf::Sprite>>> mapka;
    for(int i = 0; i < 10; i++){
        std::unique_ptr<sf::Sprite> monster = std::make_unique<Potwor>(monster_texture);
        std::unique_ptr<sf::Sprite> swamp = std::make_unique<Bagno>(swamp_texture);
        mapka["potwory"].emplace_back(std::move(monster));
        mapka["bagno"].emplace_back(std::move(swamp));
    }
    sf::RectangleShape home(sf::Vector2f(100,100));
    home.setPosition(700,0);
    // create some shapes
    Bohater hero(hero_texture);
    // run the program as long as the window is open
    sf::Clock clock;
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        sf::Time elapsed = clock.restart();
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed){
                sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                hero.hero_move(mouse_pos);
            }
            //hero.updateCollisions(mapka);
        }
        //std::cout << hero.getPoint() << std::endl;
        hero.time(elapsed.asSeconds());
        hero.updateCollisions(mapka);
        hero.spawn();
        hero.is_win(home,window);
        for(auto &m : mapka){
            for(auto &obj : m.second){
                Potwor *as_potwor = dynamic_cast<Potwor *>(obj.get());
                if( as_potwor != nullptr){
                    as_potwor->Dzialaj(elapsed.asSeconds());
                }else {
                    Bagno *as_bagno = dynamic_cast<Bagno *>(obj.get());
                    as_bagno->Dzialaj(elapsed.asSeconds());
                }
            }
        }
        // clear the window with black color
        window.clear(sf::Color::Black);
        // draw everything here...
        window.draw(home);
        for(const auto &m :mapka){
            for(const auto &obj : m.second){
                window.draw(*obj);
            }
        }
        window.draw(hero);
        // end the current frame
        window.display();
    }

    return 0;
}

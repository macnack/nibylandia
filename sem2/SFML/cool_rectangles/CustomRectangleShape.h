#ifndef CUSTOMRECTANGLESHAPE_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <time.h>
class CustomRectangleShape : public sf::RectangleShape{
public:
    bool select();
    bool unselect();
    void setSpeed(int x, int y, int &r);
    void setBounds(int ox, int w_x, int oy, int w_y);
    void setBounds(const sf::IntRect &w_size);
    void move(const sf::Time &elapsed);
    void animate(const sf::Time &elapsed);
    void selected_mouse(const sf::RenderWindow &window, const sf::Event &event);
    CustomRectangleShape(const sf::Vector2f &size,const sf::Vector2f &pos): sf::RectangleShape(size){
        sf::RectangleShape::setPosition(pos);}
private:
    bool is_selected = false;
    int speed_x_ = 0;
    int speed_y_ = 0;
    int speed_r_ = 0;
    int ox_ = 0;
    int oy_ = 0;
    int w_x_ = 0;
    int w_y_ = 0;
    sf::Vector2f size_;
    sf::Vector2f pos_;
    void bounce();
};


#define CUSTOMRECTANGLESHAPE_H

#endif // CUSTOMRECTANGLESHAPE_H

#include "CustomRectangleShape.h"

bool CustomRectangleShape::select() { return is_selected = false; }
bool CustomRectangleShape::unselect() { return is_selected = true; }
void CustomRectangleShape::setSpeed(int x, int y, int &r)
{
    speed_x_ = x;
    speed_y_ = y;
    speed_r_ = r;
}
void CustomRectangleShape::setBounds(int ox, int w_x, int oy, int w_y)
{
    ox_ = ox;
    w_x_ = w_x;
    oy_ = oy;
    w_y_ = w_y;
}
void CustomRectangleShape::setBounds(const sf::IntRect &w_size)
{
    ox_ = w_size.left;
    w_x_ = w_size.width;
    oy_ = w_size.top;
    w_y_ = w_size.height;
}
void CustomRectangleShape::move(const sf::Time &elapsed)
{
    sf::FloatRect rectangle_bounds = sf::RectangleShape::getGlobalBounds();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (is_selected)
        {
            if (rectangle_bounds.top > oy_)
            {
                sf::RectangleShape::move(0, -500 * elapsed.asSeconds());
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (is_selected)
        {
            if (rectangle_bounds.top + rectangle_bounds.height < w_y_)
            {
                sf::RectangleShape::move(0, 500 * elapsed.asSeconds());
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if (is_selected)
        {
            if (rectangle_bounds.left > ox_)
            {
                sf::RectangleShape::move(-500 * elapsed.asSeconds(), 0);
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if (is_selected)
        {
            if (rectangle_bounds.left + rectangle_bounds.width < w_x_)
            {
                sf::RectangleShape::move(500 * elapsed.asSeconds(), 0);
            }
        }
    }
}
void CustomRectangleShape::animate(const sf::Time &elapsed)
{
    if (!is_selected)
    {
        bounce();
        sf::RectangleShape::move(elapsed.asSeconds() * speed_x_, elapsed.asSeconds() * speed_y_);
        sf::RectangleShape::rotate(elapsed.asSeconds() * speed_r_);
    }
    else
    {
        move(elapsed);
    }
}
void CustomRectangleShape::selected_mouse(const sf::RenderWindow &window, const sf::Event &event)
{
    if(event.type == sf::Event::MouseButtonPressed){
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
        if(sf::RectangleShape::getGlobalBounds().contains(mouse_pos.x,mouse_pos.y)){
            if(event.mouseButton.button == sf::Mouse::Left){
                if(!is_selected)
                    unselect();
                else
                    select();
            }
            if(event.mouseButton.button == sf::Mouse::Right){
                sf::RectangleShape::setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
            }
        }
    }
}

void CustomRectangleShape::bounce()
{
    sf::FloatRect rectangle_bounds = sf::RectangleShape::getGlobalBounds();
    if (rectangle_bounds.left < ox_)
    {
        speed_x_ = std::abs(speed_x_);
    }
    if (rectangle_bounds.top < oy_)
    {
        speed_y_ = std::abs(speed_x_);
    }
    if (rectangle_bounds.left + rectangle_bounds.width > w_x_ - 1)
    {
        speed_x_ = -std::abs(speed_x_);
    }
    if (rectangle_bounds.top + rectangle_bounds.height > w_y_ - 1)
    {
        speed_y_ = -std::abs(speed_y_);
    }
}

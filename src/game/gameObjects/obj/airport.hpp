#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include "base.hpp"
#include "flyable.hpp"

class Airport : public sf::Drawable, public sf::Transformable
{
public:
    Airport(sf::Vector2f pos);

    void update();

    /// @brief startuje samoloty do okreslonej pozycji 
    /// @param where funkcja ktora zwraca losowa pozycje lotniska
    void departReadyPlanes(std::function<sf::Vector2f()> where);

    sf::FloatRect getGlobalBounds() const {return sprite.getGlobalBounds();}

    bool requestLanding(IFlyable& obj);
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();
        target.draw(sprite, states);
    }
    sf::Sprite sprite;
    std::vector<IFlyable*> objects;
};
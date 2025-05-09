#pragma once
#include <functional>
#include "airportInterface.hpp"
#include "base.hpp"
#include "flyable.hpp"

class Airport : public IAirport
{
public:
    Airport(sf::Vector2f pos);

    void update();

    /// @brief startuje samoloty do okreslonej pozycji 
    /// @param where funkcja ktora zwraca losowa pozycje lotniska
    void departReadyPlanes(std::function<IAirport*()> where);

    sf::FloatRect getGlobalBounds() const override {return sprite.getGlobalBounds();}

    bool requestLanding(IFlyable* obj);
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();
        target.draw(sprite, states);
    }
    sf::Sprite sprite;
    std::vector<IFlyable*> objects;
};
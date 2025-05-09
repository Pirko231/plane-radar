#pragma once
#include <SFML/Graphics.hpp>

enum Status : char
{
    FLYING,
    DOCKED,
    CRASHED
};

class IFlyable : public sf::Drawable, public sf::Transformable
{
public:
    IFlyable(const sf::Texture& texture) : sprite{texture}
    {}
    virtual void update() = 0;
    virtual void setDestination() = 0;
    void refill() {fuel += refillSpeed;}
    virtual void depart(sf::Vector2f target) = 0;

    bool readyToDepart() const {return fuel >= fuelToDepart;}

    virtual sf::FloatRect getGlobalBounds() const {return sprite.getGlobalBounds();}
    Status getStatus() const {return status;}

protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(sprite,states);
    }
    sf::Sprite sprite;
    Status status;
    float fuel{100.f};
    float fuelToDepart{80.f};
    float refillSpeed{1.f};
};
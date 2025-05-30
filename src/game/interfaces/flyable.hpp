#pragma once
#include <SFML/Graphics.hpp>
#include "airportInterface.hpp"

/// @brief status samolotu (czy leci itd.)
enum Status : char
{
    FLYING,
    DOCKED,
    CRASHED,
    EMERGENCY
};

/// @brief abstrakcja dla wszystkich latajacych obiektow
class IFlyable : public sf::Drawable, public sf::Transformable
{
public:
    IFlyable(const sf::Texture& texture) : sprite{texture}
    {}
    virtual void update() = 0;
    virtual void depart(IAirport* target) = 0;
    virtual void setTarget(IAirport*) = 0;
    virtual IAirport* getTarget() const = 0;
    virtual void land() {status = Status::DOCKED;}
    void refill() {fuel += refillSpeed;}
    bool needsEmergencyLanding()
    {
        if (status == Status::FLYING && fuel < 30.f)
        {
            status = Status::EMERGENCY;
            return true;
        }
            
        return false;
    }

    bool readyToDepart() const {return fuel >= fuelToDepart;}

    virtual sf::FloatRect getGlobalBounds() const {return sf::FloatRect{getPosition(), sprite.getGlobalBounds().size};}
    Status getStatus() const {return status;}

#ifdef IMGUI
    float getFuel() const {return fuel;}
    void resetFuel() {fuel = 0.f;}
    void maxFuel() {fuel = 100.f;}
#endif

protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(sprite,states);
    }
    sf::Sprite sprite;
    Status status{Status::FLYING};
    float fuel{100.f};
    float fuelToDepart{100.f};
    float refillSpeed{0.2f};
    float fuelUsage{util::ConfigLoader::get().fuelUsage};
};
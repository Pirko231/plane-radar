#pragma once
#include "airportManagerInterface.hpp"
#include "map.hpp"
#include <vector>

class AirportManager : public IAirportManager
{
public:
    AirportManager(int amount, const Map* map);

    void update();

    void display(sf::RenderWindow* window);

    const Airport& getClosestAirport(sf::Vector2f pos) const override;

    bool requestLanding(IFlyable&, sf::Vector2f) override;

private:
    const Airport& getRandomAirport() const {return airports[std::rand() % airports.size()];}

    std::vector<Airport> airports;
};
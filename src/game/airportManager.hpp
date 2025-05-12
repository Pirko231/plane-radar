#pragma once
#include "airportManagerInterface.hpp"
#include "factories/airportFactory.hpp"
#include "map.hpp"
#include <vector>

class AirportManager : public IAirportManager
{
public:
    AirportManager(int amount, const Map* map);

    void update(bool paused = false);

    void display(sf::RenderWindow* window);

    Airport* getClosestAirport(sf::Vector2f pos) override;

    bool requestLanding(IFlyable*, IAirport*) override;

    Airport* getRandomAirport() override 
    {
        std::uniform_int_distribution<int> dist(0, airports.size() - 1);
        return &airports[dist(util::engine)];
    }

private:
    std::vector<Airport> airports;
};
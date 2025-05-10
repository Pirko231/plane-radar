#pragma once
#include "airportManagerInterface.hpp"
#include "map.hpp"
#include <vector>

class AirportManager : public IAirportManager
{
public:
    AirportManager(int amount, const Map* map);

    void update(bool paused = false);

    void display(sf::RenderWindow* window);

    const Airport& getClosestAirport(sf::Vector2f pos) const override;

    bool requestLanding(IFlyable*, sf::FloatRect) override;

    Airport* getRandomAirport() override {return &airports[std::rand() % airports.size()];}

private:
    std::vector<Airport> airports;
};
#include "flightControl.hpp"

FlightControl::FlightControl(sf::Vector2u mapSize, int startingPlanes, IAirportManager& airportManager)
{
    FlyableFactory factory;
    for (int i = 0; i < startingPlanes; i++)
    {
        auto getRandomPos = [&]() -> sf::Vector2f {return sf::Vector2f{std::rand() % mapSize.x + 1.f, std::rand() % mapSize.y + 1.f};};
        objects.push_back(factory.createPlane(getRandomPos()));
        airportManager.requestLanding(*objects[i].get(), airportManager.getClosestAirport(objects[i]->getGlobalBounds().position).getPosition());
    }
}

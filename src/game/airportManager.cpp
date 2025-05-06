#include "airportManager.hpp"

AirportManager::AirportManager(int amount, const Map* map)
{
    AirportFactory factory;
    for (int i = 0; i < amount; i++)
    {
        airports.push_back(factory.create(map->getRandomPoint()));
    }
}

void AirportManager::update()
{
    for (auto& port : airports)
        port.update();
}

void AirportManager::display(sf::RenderWindow* window)
{
    for (auto& port : airports)
        window->draw(port);
}

const Airport &AirportManager::getClosestAirport(sf::Vector2f pos) const
{
    if (!airports.empty())
        return airports[0];
    else
        throw std::out_of_range{"lotniska sa puste"};

}

bool AirportManager::requestLanding(IFlyable& obj, sf::Vector2f pos)
{
    Airport* requestedAirport{};
    for (auto& airport : airports)
        if (airport.getGlobalBounds().contains(pos))
            requestedAirport = &airport;

    if (requestedAirport)
        return requestedAirport->requestLanding(obj);

    return false;
}

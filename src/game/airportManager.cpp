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
    {
        port.update();
        port.departReadyPlanes([&](){return airports[std::rand() % airports.size()].getPosition();});
    }
}

void AirportManager::display(sf::RenderWindow* window)
{
    for (auto& port : airports)
        window->draw(port);
}

const Airport &AirportManager::getClosestAirport(sf::Vector2f pos) const
{
    sf::Vector2f minOffset{1.f,1.f};
    const Airport* currentAirport{};

    for (auto& airport : airports)
    {
        sf::Vector2f offset{};
        offset = pos -airport.getGlobalBounds().position;
        if (offset.length() > minOffset.length())
        {
            minOffset = offset;
            currentAirport = &airport;
        }
    }
    return *currentAirport;
}

bool AirportManager::requestLanding(IFlyable& obj, sf::Vector2f pos)
{
    Airport* requestedAirport{};
    for (auto& airport : airports)
        if (airport.getGlobalBounds().contains(pos))
        {
            requestedAirport = &airport;
            break;
        }

    if (requestedAirport)
        return requestedAirport->requestLanding(obj);

    return false;
}

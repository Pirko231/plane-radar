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
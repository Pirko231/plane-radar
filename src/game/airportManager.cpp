#include "airportManager.hpp"

AirportManager::AirportManager(int amount)
{
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
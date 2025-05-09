#include "flightControl.hpp"

FlightControl::FlightControl(sf::Vector2u mapSize, int startingPlanes, IAirportManager& airportManager)
{
    FlyableFactory factory;
    for (int i = 0; i < startingPlanes; i++)
    {
        auto getRandomPos = [&]() -> sf::Vector2f {return sf::Vector2f{std::rand() % mapSize.x + 1.f, std::rand() % mapSize.y + 1.f};};
        objects.push_back(factory.createPlane(getRandomPos()));
        objects[i]->setPosition(airportManager.getClosestAirport(objects[i]->getPosition()).getPosition());
        airportManager.requestLanding(*objects[i].get(), objects[i]->getPosition());
    }
}

void FlightControl::update()
{
    for (auto& plane : objects)
        plane->update();
}

void FlightControl::display(sf::RenderWindow* window)
{
    for (auto& plane : objects)
    {
        if (plane->getStatus() == Status::FLYING)
            window->draw(*plane);
    }
}

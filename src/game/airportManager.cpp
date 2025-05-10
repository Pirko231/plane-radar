#include "airportManager.hpp"

AirportManager::AirportManager(int amount, const Map* map)
{
    AirportFactory factory;
    for (int i = 0; i < amount; i++)
    {
        airports.push_back(factory.create(map->getRandomPoint()));
    }
}

void AirportManager::update(bool paused)
{
    if (!paused)
    {
        for (auto &port : airports)
        {
            port.update();
            port.departReadyPlanes([this](){ return getRandomAirport(); });
        }
    }

#ifdef IMGUI
    ImGui::Begin("AirportManager");
    for (std::size_t i = 0; i < airports.size(); i++)
        if (ImGui::CollapsingHeader(std::string("Airport " + std::to_string(i)).c_str()))
        {
            ImGui::Text("%s" ,std::string(std::to_string(airports[i].getPosition().x) + ',' + std::to_string(airports[i].getPosition().y)).c_str());
            int objNumber{};
            for (auto& plane : airports[i].getObjects())
            {
                if (ImGui::CollapsingHeader(std::string("Plane " + std::to_string(objNumber)).c_str()))
                {
                    ImGui::Text("%s",std::string( std::to_string(plane->getPosition().x) + ',' + std::to_string(plane->getPosition().y)).c_str());
                    ImGui::Text("%s", std::string("Fuel " + std::to_string(plane->getFuel())).c_str());
                }
                objNumber++;
            }
            if (ImGui::Button("Depart all planes"))
            {
                for (auto& i : airports[i].getObjects())
                    i->maxFuel();
                airports[i].departReadyPlanes([&](){return &airports[std::rand() % airports.size()];});
            }
                
        }
    ImGui::End();
#endif
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

bool AirportManager::requestLanding(IFlyable* obj, IAirport* where)
{
    Airport* requestedAirport{};
    if (where->getGlobalBounds().findIntersection(where->getGlobalBounds()))
        requestedAirport = dynamic_cast<Airport*>(where);

    if (requestedAirport)
        return requestedAirport->requestLanding(obj);

    return false;
}

#include "flightControl.hpp"

FlightControl::FlightControl(sf::Vector2u mapSize, int startingPlanes, IAirportManager& airportManager)
: airportManager{airportManager}
{
    FlyableFactory factory;
    for (int i = 0; i < startingPlanes; i++)
    {
        objects.push_back(factory.createPlane(airportManager.getRandomAirport()));
        airportManager.requestLanding(objects[i].get(), objects[i]->getTarget());
    }
}

void FlightControl::update(bool paused)
{
    if (!paused)
    {
        for (auto &plane : objects)
        {
            if (plane->getStatus() == Status::FLYING)
                if (plane->getGlobalBounds().findIntersection(plane->getTarget()->getGlobalBounds()))
                    airportManager.requestLanding(plane.get(), plane->getTarget());
            plane->update();
            if (plane->needsEmergencyLanding())
                plane->depart(airportManager.getClosestAirport(plane->getPosition()));
        }
    }

#ifdef IMGUI
    ImGui::Begin("FlightControl");
    if (ImGui::Button("Create new plane"))
    {
        FlyableFactory factory;
        objects.push_back(factory.createPlane(airportManager.getRandomAirport()));
        airportManager.requestLanding((objects.end() - 1)->operator->(), (objects.end() - 1)->operator->()->getTarget());
    }
    for (std::size_t i = 0; i < objects.size(); i++)
    {
        bool changedColor{};
        if (objects[i]->getStatus() == Status::DOCKED)
        {
            ImGui::PushStyleColor(ImGuiCol_Header, ImVec4(0.2f, 0.7f, 0.2f, 1.0f));
            changedColor = true;
        }
        else if (objects[i]->getStatus() == Status::CRASHED)
        {
            ImGui::PushStyleColor(ImGuiCol_Header, ImVec4(1.0f, 0.0f, 0.0f, 1.0f));
            changedColor = true;
        }

        if (ImGui::CollapsingHeader(std::string("Plane " + std::to_string(i)).c_str()))
        {
            ImGui::Text("%s" ,std::string("Position " + std::to_string(objects[i]->getPosition().x) + ',' + std::to_string(objects[i]->getPosition().y)).c_str());
            if (Plane* plane = dynamic_cast<Plane*>(objects[i].get()))
                ImGui::Text("%s", std::string("Destination " + std::to_string(plane->getDestination().x) + ',' + std::to_string(plane->getDestination().y)).c_str());
            ImGui::Text("%s", std::string("Fuel " + std::to_string(objects[i]->getFuel())).c_str());
            
            
            if (ImGui::Button("Find new target"))
                objects[i]->depart(airportManager.getRandomAirport());
            if (ImGui::Button("Crash plane"))
                objects[i]->resetFuel();
        }
        if (changedColor)
            ImGui::PopStyleColor(1);
    }
    ImGui::End();
#endif
}

void FlightControl::display(sf::RenderWindow* window)
{
    for (auto& plane : objects)
    {
        if (plane->getStatus() == Status::FLYING || plane->getStatus() == Status::CRASHED)
            window->draw(*plane);
    }
}

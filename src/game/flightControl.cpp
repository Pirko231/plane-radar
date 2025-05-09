#include "flightControl.hpp"

FlightControl::FlightControl(sf::Vector2u mapSize, int startingPlanes, IAirportManager& airportManager)
: airportManager{airportManager}
{
    FlyableFactory factory;
    for (int i = 0; i < startingPlanes; i++)
    {
        auto getRandomPos = [&]() -> sf::Vector2f {return sf::Vector2f{std::rand() % mapSize.x + 1.f, std::rand() % mapSize.y + 1.f};};
        objects.push_back(factory.createPlane(getRandomPos()));
        objects[i]->setPosition(airportManager.getClosestAirport(objects[i]->getPosition()).getPosition());
        airportManager.requestLanding(objects[i].get(), objects[i]->getPosition());
    }
}

void FlightControl::update()
{
    for (auto& plane : objects)
    {
        plane->update();
        if (plane->isNearTarget())
            airportManager.requestLanding(plane.get(), plane->getPosition());
    }

#ifdef IMGUI
    ImGui::Begin("FlightControl");
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
        if (plane->getStatus() == Status::FLYING)
            window->draw(*plane);
    }
}

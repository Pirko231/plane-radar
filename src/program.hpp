#pragma once
#include <SFML/Graphics.hpp>
#include <optional>
#include "game/airportManager.hpp"
#include <map>

/// @brief tutaj znajduje sie cala logika gry
class Program
{
public:
    Program();
    ~Program();
    bool running() const {return window->isOpen();}
    void handleEvents();
    void update();
    void display();
private:
    void manageView();

    sf::RenderWindow* window;
    std::unordered_map<sf::Keyboard::Scan, util::KeyStatus> keys;
    std::unordered_map<sf::Mouse::Button, util::MouseStatus> mButtons;
    float scrolled{};

    sf::Vector2u mapSize{1280u,720u};
    sf::View view;
    float moveViewSpeed{100.f};
    float zoomViewSpeed{1.f};

    Map map;
    AirportManager airportManager;
};
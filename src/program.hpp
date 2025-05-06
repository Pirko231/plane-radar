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
    std::unordered_map<sf::Keyboard::Scan, bool> keyPressed;
    std::unordered_map<sf::Keyboard::Scan, bool> keyReleased;
    std::unordered_map<sf::Mouse::Button, bool> mButtonPressed;
    std::unordered_map<sf::Mouse::Button, bool> mButtonReleased;
    float scrolled{};

    sf::Vector2u mapSize{1280u,720u};
    sf::View view;
    float moveViewSpeed{100.f};
    float zoomViewSpeed{1.f};

    Map map;
    AirportManager airportManager;
};
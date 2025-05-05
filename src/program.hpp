#pragma once
#include <SFML/Graphics.hpp>
#include <optional>
#include "game/airportManager.hpp"

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
    sf::RenderWindow* window;

    Map map;
    AirportManager airportManager;
};
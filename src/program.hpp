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
    std::map<sf::Keyboard::Key, bool> keyPressed;
    std::map<sf::Keyboard::Key, bool> keyReleased;

    sf::Vector2u mapSize{1280u,720u};
    sf::View view;
    float moveViewSpeed{10.f};

    
    Map map;
    AirportManager airportManager;
};
#pragma once
#include <SFML/Graphics.hpp>
#include <optional>

/// @brief tutaj znajduje sie cala logika gry
class Program
{
public:
    Program();
    ~Program();
    bool running() const {return window->isOpen();}
    void handleEvents();
    void display();
    void update();
private:
    sf::RenderWindow* window;
};
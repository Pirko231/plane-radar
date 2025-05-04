#pragma once
#include <SFML/Graphics.hpp>
#include <optional>

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
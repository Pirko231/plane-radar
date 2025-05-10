#pragma once
#include <fstream>
#include <SFML/Graphics.hpp>

namespace util
{

class ConfigLoader
{
public:
    static ConfigLoader& get()
    {
        static ConfigLoader confLoader;
        return confLoader;
    }

    sf::Vector2u mapSize{1280u,720u};
    int airportAmount{4};

    ~ConfigLoader()
    {
        std::fstream file;
        file.open("settings.conf", std::ios::trunc | std::ios::out | std::ios::in);
        if (file.is_open())
        {
            file << "Modify your configuration here, in case something stops working, delete this file.\n"
                << "------------------SETTINGS------------------\n";
            file << "Map size: " << mapSize.x << ',' << mapSize.y << ";\n"
                << "Airport amount: " << airportAmount << ";\n";
        }
        file.close();
    }
private:
    ConfigLoader();
};

};

inline util::ConfigLoader::ConfigLoader()
{
    std::fstream file;
    file.open("settings.conf", std::ios::in);
    if (file.is_open())
    {
        std::string dump;
        std::string data;
        std::getline(file, dump, ':');
        std::getline(file, data, ',');
        try
        {
            mapSize.x = std::stoi(data);
        }
        catch(const std::exception& e)
        {}
        std::getline(file, data, ';');
        try
        {
            mapSize.y = std::stoi(data);
        }
        catch(const std::exception& e)
        {}
        std::getline(file, dump, ':');
        std::getline(file, data, ';');
        try
        {
            airportAmount = std::stoi(data);
        }
        catch(const std::exception& e)
        {}
        
        
    }
    file.close();
}
#pragma once
#include <fstream>
#include <SFML/Graphics.hpp>
#include <charconv>

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

    sf::Vector2u mapSize{2000u,2000u};
    int airportAmount{8};
    float fuelUsage{0.05f};

    ~ConfigLoader()
    {
        std::fstream file;
        file.open("settings.conf", std::ios::trunc | std::ios::out | std::ios::in);
        if (file.is_open())
        {
            file << "Modify your configuration here, in case something stops working, delete this file.\n"
                << "------------------SETTINGS------------------\n";
            file << "Map size: " << mapSize.x << ',' << mapSize.y << ";\n"
                << "Airport amount: " << airportAmount << ";\n"
                << "Plane fuel usage: " << fuelUsage << ";\n";
        }
        file.close();
    }
private:
    ConfigLoader();


    template<typename T>
    T read(std::fstream& file, T defaultValue, char character = ';')
    {
        T result{};
        std::string data;
        std::getline(file, data, character);
        if (data[0] == ' ')
            data.erase(data.begin());

        if (std::from_chars(data.data(), data.data() + data.size(), result).ec == std::errc{})
            return result;
        else
            return defaultValue;
    }
};

};

inline util::ConfigLoader::ConfigLoader()
{
    std::fstream file;
    file.open("settings.conf", std::ios::in);
    if (file.is_open())
    {
        std::string dump;
        std::getline(file, dump, ':');
        mapSize.x = read<int>(file, mapSize.x, ',');
        mapSize.y = read<int>(file, mapSize.y);
        std::getline(file, dump, ':');
        airportAmount = read<int>(file, airportAmount);
        std::getline(file, dump, ':');
        fuelUsage = read<float>(file, fuelUsage);
        
    }
    file.close();
}
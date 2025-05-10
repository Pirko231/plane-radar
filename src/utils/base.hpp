#pragma once
#include <random>
#include "assetLoader.hpp"
#include "configLoader.hpp"

/// @brief utilities, wystarczy includowac base.hpp
namespace util
{
    inline std::random_device device{};
    inline std::default_random_engine engine(device());

    /// @brief aktualizowana w main.cpp
    inline float dt{};

    /// @brief informacje o nacisnieciu / puszceniu klawisza
    struct DefaultStatus
    {
        bool pressed{}, released{};
    };
    
    struct KeyStatus : public DefaultStatus
    {
        
    };

    struct MouseStatus : public DefaultStatus
    {

    };

};
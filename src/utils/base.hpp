#pragma once
#include "assetLoader.hpp"

/// @brief utilities, wystarczy includowac base.hpp
namespace util
{

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
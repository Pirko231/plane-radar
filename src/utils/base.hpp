#pragma once
#include "assetLoader.hpp"

/// @brief utilities, wystarczy includowac base.hpp
namespace util
{

    /// @brief aktualizowana w main.cpp
    inline float dt{};

    struct KeyStatus
    {
        bool pressed{}, released{};
    };
};
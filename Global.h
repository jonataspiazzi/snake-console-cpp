#pragma once

#include <string>

using FText = std::string;
using int32 = int;

#define null NULL

enum class EObjectType
{
    Empty = 0,
    SnakeBody = 1,
    Food = 2
};

enum class EDirection
{
    None = 0,
    Left = 1,
    Up = 2,
    Right = 3,
    Down = 4
};
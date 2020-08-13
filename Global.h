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

enum class EKeyboardInput
{
    None = 0,
    MoveLeft = 1,
    MoveUp = 2,
    MoveRight = 3,
    MoveDown = 4,
    Exit = 5
};

enum class EGameStatus
{
    Stopped = 0x00,
    Running = 0x01,
    Playing = 0x02 | 0x01,
    Won = 0x04 | 0x00,
    Lost = 0x08 | 0x00
};

EGameStatus operator&(EGameStatus left, EGameStatus right);
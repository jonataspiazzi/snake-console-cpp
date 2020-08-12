#pragma once

#include <iostream>
#include "Snake.h"

FSnake::FSnake(int32 x, int32 y, int32 tailSize)
{
    this->x = x;
    this->y = y;

    if (tailSize >= 0)
    {
        this->tail = new FSnake(x + 1, y, tailSize - 1);
    }

    std::cout << "FSnake created\n";
}

FSnake* FSnake::GetTail()
{
    return this->tail;
}

int32 FSnake::GetX()
{
    return this->x;
}

int32 FSnake::GetY()
{
    return this->y;
}
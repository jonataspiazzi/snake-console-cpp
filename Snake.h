#pragma once

#include <string>

using FText = std::string;
using int32 = int;
#define null NULL

class FSnake
{
public:
    FSnake(int32 x, int32 y, int32 tailSize);
    FSnake* GetTail();
    int32 GetX();
    int32 GetY();

private:
    int32 x;
    int32 y;
    FSnake* tail;
};
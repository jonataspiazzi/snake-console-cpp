#pragma once

#include "Unreal.h"

class FSnake
{
public:
    FSnake(int32 x, int32 y, int32 tailSize, FSnake *head = null);
    ~FSnake();
    FSnake *GetHead();
    FSnake *GetTail();
    FSnake *GetLastTail();
    int32 X;
    int32 Y;

private:
    FSnake *tail;
    FSnake *head;
};
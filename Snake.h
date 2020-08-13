#pragma once

#include "Global.h"

class FSnake
{
public:
    FSnake(int32 x, int32 y, FSnake *tail);
    FSnake(int32 x, int32 y, int32 tailSize, FSnake *head = null);
    ~FSnake();
    FSnake *GetHead() const;
    FSnake *GetTail() const;
    FSnake *GetLastTail();
    int32 X;
    int32 Y;

private:
    FSnake *tail;
    FSnake *head;
};
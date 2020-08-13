#pragma once

#include "Snake.h"

FSnake::FSnake(int32 x, int32 y, int32 tailSize, FSnake *head)
{
    this->X = x;
    this->Y = y;

    this->head = head;

    if (tailSize >= 0)
    {
        this->tail = new FSnake(x + 1, y, tailSize - 1);
        this->tail->head = this;
    }
}

FSnake::~FSnake()
{
    if (this->tail != null)
    {
        delete this->tail;
    }
}

FSnake *FSnake::GetHead()
{
    return this->head;
}

FSnake *FSnake::GetTail()
{
    return this->tail;
}

FSnake *FSnake::GetLastTail()
{
    return this->tail == null ? this : this->tail->GetLastTail();
}
#pragma once

#include "Snake.h"

FSnake::FSnake(int32 x, int32 y, FSnake *tail)
{
    this->X = x;
    this->Y = y;
    this->head = null;
    this->tail = tail;
    tail->head = this;
}

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

FSnake *FSnake::GetHead() const
{
    return this->head;
}

FSnake *FSnake::GetTail() const
{
    return this->tail;
}

int32 FSnake::GetSize() const
{
    int32 size = 1;

    if (this->tail != null)
    {
        size += this->tail->GetSize();
    }

    return size;
}

FSnake *FSnake::GetLastTail()
{
    FSnake *last = tail == (FSnake *)null ? this : tail->GetLastTail();

    return this->tail == null ? this : this->tail->GetLastTail();
}
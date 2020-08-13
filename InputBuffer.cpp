#pragma once

#include <iostream>
#include "conio.h"
#include "InputBuffer.h"

constexpr int PRE_ARROW = 0xE0;
constexpr int ARROW_LEFT = 0x4B;
constexpr int ARROW_UP = 0x48;
constexpr int ARROW_RIGHT = 0x4D;
constexpr int ARROW_DOWN = 0x50;

using namespace std;

void InternalThread(FInputBuffer *root)
{
    while (root->IsEnabled())
    {
        root->NotifyChar(getch());
    }
}

void FInputBuffer::Start()
{
    this->enabled = true;

    this->backgroundWorker = thread(InternalThread, this);
}

void FInputBuffer::Disable()
{
    this->enabled = false;
}

EDirection FInputBuffer::GetCurrent()
{
    EDirection c = this->current;

    this->current = EDirection::None;

    return c;
}

void FInputBuffer::NotifyChar(int32 value)
{
    if (value == PRE_ARROW)
    {
        this->hasPreArrow = true;
        return;
    }

    if (!this->hasPreArrow)
    {
        return;
    }

    this->hasPreArrow = false;

    switch (value)
    {
    case ARROW_LEFT:
        this->current = EDirection::Left;
        break;
    case ARROW_UP:
        this->current = EDirection::Up;
        break;
    case ARROW_RIGHT:
        this->current = EDirection::Right;
        break;
    case ARROW_DOWN:
        this->current = EDirection::Down;
        break;
    default:
        break;
    }
}

bool FInputBuffer::IsEnabled() const
{
    return this->enabled;
}
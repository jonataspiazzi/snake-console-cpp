#pragma once

#include <iostream>
#include "conio.h"
#include "KeyboardController.h"

constexpr int32 KEY_PRE_ARROW = 0xE0;
constexpr int32 KEY_ARROW_LEFT = 0x4B;
constexpr int32 KEY_ARROW_UP = 0x48;
constexpr int32 KEY_ARROW_RIGHT = 0x4D;
constexpr int32 KEY_ARROW_DOWN = 0x50;
constexpr int32 KEY_ESCAPE = 0x1B;

using namespace std;

void InternalThread(FKeyboardController *root)
{
    while (root->IsEnabled())
    {
        root->OnKeydown(getch());
    }
}

void FKeyboardController::Listen()
{
    this->enabled = true;

    this->backgroundWorker = thread(InternalThread, this);
}

void FKeyboardController::Disable()
{
    this->enabled = false;
}

EKeyboardInput FKeyboardController::GetInput()
{
    EKeyboardInput c = this->input;

    this->input = EKeyboardInput::None;

    return c;
}

void FKeyboardController::OnKeydown(int32 key)
{
    if (key == KEY_ESCAPE)
    {
        this->input = EKeyboardInput::Exit;
        return;
    }

    if (key == KEY_PRE_ARROW)
    {
        this->hasPreArrow = true;
        return;
    }

    if (!this->hasPreArrow)
    {
        return;
    }

    this->hasPreArrow = false;

    switch (key)
    {
    case KEY_ARROW_LEFT:
        this->input = EKeyboardInput::MoveLeft;
        break;
    case KEY_ARROW_UP:
        this->input = EKeyboardInput::MoveUp;
        break;
    case KEY_ARROW_RIGHT:
        this->input = EKeyboardInput::MoveRight;
        break;
    case KEY_ARROW_DOWN:
        this->input = EKeyboardInput::MoveDown;
        break;
    default:
        break;
    }
}

bool FKeyboardController::IsEnabled() const
{
    return this->enabled;
}
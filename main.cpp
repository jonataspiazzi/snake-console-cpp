// started at 11:20
// cl /std:c++17 /Fo"./obj/" /EHsc *.cpp /Fe:"./bin/snake.exe" && cls && bin\snake.exe

#pragma once

#include <iostream>
#include "Console.h"
#include "SnakeGame.h"

using namespace std;

constexpr int PIXEL_WIDTH = 3;
constexpr EConsoleColor GROUND_COLOR = EConsoleColor::Blue;
constexpr EConsoleColor FOOD_COLOR = EConsoleColor::Gray;
constexpr EConsoleColor SNAKE_COLOR = EConsoleColor::White;

FSnakeGame game;
FConsole Console;

void PrintBuffer();
EConsoleColor GetColor(EObjectType type);

int main()
{
    game.Render();
    for (int i = 0; i < 1000; i++)
    {
        PrintBuffer();
    }
    return 0;
}

void PrintBuffer()
{
    Console.SetCursorVisible(false);

    for (int32 y = 0; y < game.Height; y++)
    {
        Console.SetCursorPosition(0, y);

        for (int32 x = 0; x < game.Width; x++)
        {
            EConsoleColor color = GetColor(game.GetBufferPixel(x, y));
            Console.SetColor(color, color);

            for (int32 c = 0; c < PIXEL_WIDTH; c++)
            {
                cout << EBlockChar::Block0;
            }
        }
    }

    Console.ResetColor();
}

EConsoleColor GetColor(EObjectType type)
{
    switch (type)
    {
    case EObjectType::Food:
        return EConsoleColor::BrightWhite;
    case EObjectType::SnakeBody:
        return EConsoleColor::BrightWhite;
    case EObjectType::Empty:
    default:
        return EConsoleColor::Blue;
    }
}
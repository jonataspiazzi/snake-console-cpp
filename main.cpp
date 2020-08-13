// started at 11:20
// cl /std:c++17 /Fo"./obj/" /EHsc *.cpp /Fe:"./bin/snake.exe" && cls && bin\snake.exe

#pragma once

#include <iostream>
#include <chrono>
#include "Console.h"
#include "InputBuffer.h"
#include "SnakeGame.h"

using namespace std;

constexpr int PIXEL_WIDTH = 3;
constexpr EConsoleColor GROUND_COLOR = EConsoleColor::Blue;
constexpr EConsoleColor FOOD_COLOR = EConsoleColor::Gray;
constexpr EConsoleColor SNAKE_COLOR = EConsoleColor::White;

FSnakeGame game;
FConsole Console;
FInputBuffer iBuffer;

void ChangeSnakeHead();
void PrintBuffer();
EConsoleColor GetColor(EObjectType type);
void FrameRateEnforcer(int32 frameRate);

int main()
{
    iBuffer.Start();
    Console.Clear();

    while (true)
    {
        game.Update(iBuffer.GetCurrent());

        if (game.IsGameEnded())
        {
            break;
        }

        game.Render();
        PrintBuffer();
        FrameRateEnforcer(10);
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

std::chrono::steady_clock::time_point lastFrame = std::chrono::steady_clock::now();

void FrameRateEnforcer(int32 frameRate)
{
    int32 minInterval = 1000 / frameRate;

    std::chrono::steady_clock::time_point currentFrame = std::chrono::steady_clock::now();
    int32 elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(currentFrame - lastFrame).count();

    if (elapsed >= minInterval)
    {
        lastFrame = std::chrono::steady_clock::now();
        return;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(minInterval - elapsed));
    lastFrame = std::chrono::steady_clock::now();
}
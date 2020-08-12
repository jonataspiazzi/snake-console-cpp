// started at 11:20
// cl /std:c++17 /Fo"./obj/" /EHsc *.cpp /Fe:"./bin/snake.exe" && cls && bin\snake.exe

#pragma once

#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>
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
void FrameRateEnforcer(int32 frameRate);

int buff1 = '0';
int buff2 = '0';

void first()
{
    cout << "Hello From First!\n";

    while (buff2 == '0')
    {
        buff1 = getch();
        cout << "Readed First!\n";
    }

    cout << "First Ended\n";
}

void second()
{
    cout << "Hello From Second!\n";

    while (buff1 == '0')
    {
        buff2 = getch();
        cout << "Readed Second!\n";
    }

    cout << "Second Ended\n";
}

int main()
{
    std::thread t1(first);
    std::thread t2(second);

    cout << "Hello From Main!\n";

    for (int i = 0; i < 0; i++)
    {
        cout << ".";
        Sleep(100);
    }

    t1.detach();
    t1.join();
    t2.join();

    cout << "end";

    return 0;

    Console.Clear();

    for (int i = 0; i < 8; i++)
    {
        game.Update();
        game.Render();
        PrintBuffer();
        FrameRateEnforcer(2);
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

    Sleep(minInterval - elapsed);
    lastFrame = std::chrono::steady_clock::now();
}
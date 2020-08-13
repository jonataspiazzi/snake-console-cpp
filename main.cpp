// started at 11:20

#pragma once

#include <iostream>
#include <chrono>
#include "Console.h"
#include "KeyboardController.h"
#include "SnakeGame.h"

using namespace std;

constexpr int PIXEL_WIDTH = 3;
constexpr EConsoleColor GROUND_COLOR = EConsoleColor::Blue;
constexpr EConsoleColor FOOD_COLOR = EConsoleColor::Gray;
constexpr EConsoleColor SNAKE_COLOR = EConsoleColor::White;

FSnakeGame game;
FConsole Console;
FKeyboardController keyboard;

void ChangeSnakeHead();
void RenderGame();
EConsoleColor GetColor(EObjectType type);
EConsoleColor GetLostColor(EObjectType type);
void FrameRateEnforcer(int32 frameRate);

int main()
{
    keyboard.Listen();
    Console.Clear();

    while (true)
    {
        game.Update(keyboard.GetInput());
        game.Render();
        RenderGame();

        if (game.IsGameEnded())
        {
            break;
        }

        FrameRateEnforcer(10);
    }

    return 0;
}

void RenderGame()
{
    Console.SetCursorVisible(false);

    EConsoleColor (*getColor)(EObjectType) = game.GetGameStatus() != EGameStatus::Lost ? &GetColor : &GetLostColor;

    for (int32 y = 0; y < game.Height; y++)
    {
        Console.SetCursorPosition(0, y);

        for (int32 x = 0; x < game.Width; x++)
        {
            EConsoleColor color = getColor(game.GetBufferPixel(x, y));
            Console.SetColor(color, color);

            for (int32 c = 0; c < PIXEL_WIDTH; c++)
            {
                cout << EBlockChar::Block0;
            }
        }
    }

    Console.ResetColor();

    Console.SetCursorPosition(0, game.Height);

    cout << "Esc = Exit (Loose), Points = " << game.GetScore() << endl;
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

EConsoleColor GetLostColor(EObjectType type)
{
    switch (type)
    {
    case EObjectType::Food:
        return EConsoleColor::LightRed;
    case EObjectType::SnakeBody:
        return EConsoleColor::Red;
    case EObjectType::Empty:
    default:
        return EConsoleColor::BrightWhite;
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
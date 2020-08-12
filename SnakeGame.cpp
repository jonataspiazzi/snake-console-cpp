#pragma once

#include <iostream>
#include "Snake.h"
#include "SnakeGame.h"

constexpr int index2d(int x, int y)
{
    return y * GAME_HEIGHT + x;
}

FSnakeGame::FSnakeGame()
{
    this->snake = new FSnake(GAME_WIDTH / 2, GAME_HEIGHT / 2, GAME_SNAKE_START_SIZE - 1);

    Reset();
}

void FSnakeGame::Reset()
{
    ClearBuffer();
}

void FSnakeGame::Render()
{
    ClearBuffer();
    RenderSnake();
    RenderFood();
}

EObjectType FSnakeGame::GetBufferPixel(int x, int y)
{
    return this->buffer[index2d(x, y)];
}

void FSnakeGame::ClearBuffer()
{
    for (int32 y = 0; y < GAME_HEIGHT; y++)
    {
        for (int32 x = 0; x < GAME_WIDTH; x++)
        {
            this->buffer[index2d(x, y)] = EObjectType::Empty;
        }
    }
}

void FSnakeGame::RenderSnake()
{
    FSnake *snake = this->snake;

    while (snake != null)
    {
        this->buffer[index2d(snake->GetX(), snake->GetY())] = EObjectType::SnakeBody;

        snake = snake->GetTail();
    }
}

void FSnakeGame::RenderFood()
{
    this->buffer[index2d(this->foodX, this->foodY)] = EObjectType::Food;
}
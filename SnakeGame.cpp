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
    Reset();
}

void FSnakeGame::Reset()
{
    if (this->snake != null)
    {
        delete this->snake;
    }

    this->snake = new FSnake(GAME_WIDTH / 2, GAME_HEIGHT / 2, GAME_SNAKE_START_SIZE - 1);
    this->snakeXDir = -1;
    this->snakeYDir = 0;

    ClearBuffer();
}

void FSnakeGame::Update()
{
    FSnake *snake = this->snake->GetLastTail();
    FSnake *head = snake->GetHead();

    while (head != null)
    {
        snake->X = head->X;
        snake->Y = head->Y;

        snake = head;
        head = head->GetHead();
    }

    snake->X += this->snakeXDir;
    snake->Y += this->snakeYDir;
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
        this->buffer[index2d(snake->X, snake->Y)] = EObjectType::SnakeBody;

        snake = snake->GetTail();
    }
}

void FSnakeGame::RenderFood()
{
    this->buffer[index2d(this->foodX, this->foodY)] = EObjectType::Food;
}
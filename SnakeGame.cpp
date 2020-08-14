#pragma once

#include <stdlib.h>
#include <time.h>
#include "SnakeGame.h"

constexpr int32 index2d(int32 x, int32 y) { return y * GAME_WIDTH + x; }
constexpr int32 xFromIndex(int32 index) { return index % GAME_WIDTH; }
constexpr int32 yFromIndex(int32 index) { return index / GAME_WIDTH; }

FSnakeGame::FSnakeGame()
{
    srand(time(null));
    Reset();
}

void FSnakeGame::Reset()
{
    this->status = EGameStatus::Playing;
    this->score = 0;
    this->foodX = 7; //GAME_WIDTH * 25 / 100;
    this->foodY = GAME_HEIGHT * 50 / 100;

    if (this->snake != null)
    {
        delete this->snake;
    }

    this->snake = new FSnake(GAME_WIDTH / 2, GAME_HEIGHT / 2, GAME_SNAKE_START_SIZE - 1);
    this->velocityX = -1;
    this->velocityY = 0;

    ClearBuffer();
}

void FSnakeGame::Update(EKeyboardInput dir)
{
    SetCommand(dir);

    if (this->IsGameEnded())
        return;

    UpdateSnake();
}

bool FSnakeGame::ShouldSnakeMove()
{
    int32 nextX = this->snake->X + this->velocityX;
    int32 nextY = this->snake->Y + this->velocityY;

    // Is hitting the border.
    if (nextX < 0 || nextX >= GAME_WIDTH || nextY < 0 || nextY >= GAME_HEIGHT)
    {
        this->status = EGameStatus::Lost;

        return false;
    }

    // Is hitting it's own body.
    for (FSnake *snake = this->snake->GetTail(); snake != null; snake = snake->GetTail())
    {
        if (snake->X == nextX && snake->Y == nextY)
        {
            this->status = EGameStatus::Lost;

            return false;
        }
    }

    // Is eating
    if (this->foodX == nextX && this->foodY == nextY)
    {
        this->snake = new FSnake(this->foodX, this->foodY, this->snake);

        UpdateFood();

        return false;
    }

    return true;
}

void FSnakeGame::UpdateSnake()
{
    if (!ShouldSnakeMove())
    {
        return;
    }

    FSnake *snake = this->snake->GetLastTail();
    FSnake *head = snake->GetHead();

    while (head != null)
    {
        snake->X = head->X;
        snake->Y = head->Y;

        snake = head;
        head = head->GetHead();
    }

    snake->X += this->velocityX;
    snake->Y += this->velocityY;
}

void FSnakeGame::UpdateFood()
{
    this->score++;

    int32 index = rand() % (GAME_WIDTH * GAME_HEIGHT - this->snake->GetSize());

    for (int32 i = 0, empty = 0; i < this->buffer.size(); i++)
    {
        if (this->buffer[i] == EObjectType::SnakeBody)
            continue;

        if (index == empty)
        {
            this->foodX = xFromIndex(i);
            this->foodY = yFromIndex(i);

            return;
        }

        empty++;
    }
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

bool FSnakeGame::IsGameEnded() const
{
    return (this->status & EGameStatus::Running) != EGameStatus::Running;
}

EGameStatus FSnakeGame::GetGameStatus() const { return this->status; }

int32 FSnakeGame::GetScore() const { return this->score; }

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

void FSnakeGame::SetCommand(EKeyboardInput key)
{
    int32 newVX = 0;
    int32 newVY = 0;

    switch (key)
    {
    case EKeyboardInput::MoveLeft:
        newVX = -1;
        newVY = 0;
        break;
    case EKeyboardInput::MoveUp:
        newVX = 0;
        newVY = -1;
        break;
    case EKeyboardInput::MoveRight:
        newVX = 1;
        newVY = 0;
        break;
    case EKeyboardInput::MoveDown:
        newVX = 0;
        newVY = 1;
        break;
    case EKeyboardInput::Exit:
        this->status = EGameStatus::Lost;
        return;
    case EKeyboardInput::None:
    default:
        return;
    }

    if (Is180Degrees(this->velocityX, newVX) || Is180Degrees(this->velocityY, newVY))
    {
        // can't turn 180 degress on x.
        return;
    }

    this->velocityX = newVX;
    this->velocityY = newVY;
}

bool FSnakeGame::Is180Degrees(int32 velocityA, int32 velocityB)
{
    return velocityA != velocityB && velocityA + velocityB == 0;
}
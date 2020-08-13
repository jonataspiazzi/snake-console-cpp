#pragma once

#include "SnakeGame.h"

constexpr int index2d(int x, int y) { return y * GAME_HEIGHT + x; }

FSnakeGame::FSnakeGame() { Reset(); }

void FSnakeGame::Reset()
{
    this->status = EGameStatus::Playing;
    this->score = 0;

    if (this->snake != null)
    {
        delete this->snake;
    }

    this->snake = new FSnake(GAME_WIDTH / 2, GAME_HEIGHT / 2, GAME_SNAKE_START_SIZE - 1);
    this->snakeXDir = -1;
    this->snakeYDir = 0;

    ClearBuffer();
}

void FSnakeGame::Update(EKeyboardInput dir)
{
    SetCommand(dir);

    if (this->IsGameEnded())
        return;

    UpdateSnake();

    if (this->status == EGameStatus::Running)
        return;

    UpdateFood();
}

void FSnakeGame::UpdateSnake()
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

void FSnakeGame::UpdateFood() {}

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
    switch (key)
    {
    case EKeyboardInput::MoveLeft:
        this->snakeXDir = -1;
        this->snakeYDir = 0;
        break;
    case EKeyboardInput::MoveUp:
        this->snakeXDir = 0;
        this->snakeYDir = -1;
        break;
    case EKeyboardInput::MoveRight:
        this->snakeXDir = 1;
        this->snakeYDir = 0;
        break;
    case EKeyboardInput::MoveDown:
        this->snakeXDir = 0;
        this->snakeYDir = 1;
        break;
    case EKeyboardInput::Exit:
        this->status = EGameStatus::Lost;
        break;
    case EKeyboardInput::None:
    default:
        break;
    }
}
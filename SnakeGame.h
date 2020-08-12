#pragma once

#include <string>
#include <array>
#include "Snake.h"

constexpr int GAME_WIDTH = 20;
constexpr int GAME_HEIGHT = 20;
constexpr int GAME_SNAKE_START_SIZE = 5;
constexpr int index2d(int x, int y);

using namespace std;

enum class EObjectType
{
    Empty = 0,
    SnakeBody = 1,
    Food = 2
};

class FSnakeGame
{
public:
    FSnakeGame();
    void Reset();
    void Update();
    void Render();
    EObjectType GetBufferPixel(int x, int y);
    const int Width = GAME_WIDTH;
    const int Height = GAME_HEIGHT;

private:
    void ClearBuffer();
    void RenderSnake();
    void RenderFood();
    FSnake *snake;
    int32 foodX;
    int32 foodY;
    int32 snakeXDir;
    int32 snakeYDir;
    array<EObjectType, GAME_WIDTH * GAME_HEIGHT> buffer;
};
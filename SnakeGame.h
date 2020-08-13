#pragma once

#include <string>
#include <array>
#include "Snake.h"
#include "Global.h"

constexpr int GAME_WIDTH = 20;
constexpr int GAME_HEIGHT = 20;
constexpr int GAME_SNAKE_START_SIZE = 5;
constexpr int index2d(int x, int y);

using namespace std;

class FSnakeGame
{
public:
    FSnakeGame();
    void Reset();
    void Update(EKeyboardInput dir);
    void Render();
    EObjectType GetBufferPixel(int x, int y);
    bool IsGameEnded() const;
    EGameStatus GetGameStatus() const;
    int32 GetScore() const;
    const int Width = GAME_WIDTH;
    const int Height = GAME_HEIGHT;

private:
    void ClearBuffer();
    void RenderSnake();
    void RenderFood();
    void UpdateSnake();
    void UpdateFood();
    void SetCommand(EKeyboardInput dir);
    FSnake *snake;
    int32 foodX;
    int32 foodY;
    int32 snakeXDir;
    int32 snakeYDir;
    EGameStatus status;
    int32 score;
    array<EObjectType, GAME_WIDTH * GAME_HEIGHT> buffer;
};
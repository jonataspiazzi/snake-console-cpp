#pragma once

#include <array>
#include "Snake.h"
#include "Global.h"

constexpr int GAME_WIDTH = 20;
constexpr int GAME_HEIGHT = 20;
constexpr int GAME_SNAKE_START_SIZE = 5;

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
    bool ShouldSnakeMove();
    void UpdateSnake();
    void UpdateFood();
    void SetCommand(EKeyboardInput dir);
    bool Is180Degrees(int32 source, int32 dest);
    FSnake *snake;
    int32 foodX;
    int32 foodY;
    int32 velocityX;
    int32 velocityY;
    EGameStatus status;
    int32 score;
    array<EObjectType, GAME_WIDTH * GAME_HEIGHT> buffer;
};
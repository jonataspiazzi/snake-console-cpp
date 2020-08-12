#pragma once

#include <string>
#include <windows.h>

using namespace std;

enum class EConsoleColor
{
    Black = 0x0,
    Blue = 0x1,
    Green = 0x2,
    Aqua = 0x3,
    Red = 0x4,
    Purple = 0x5,
    Yellow = 0x6,
    White = 0x7,
    Gray = 0x8,
    LightBlue = 0x9,
    LightGreen = 0xA,
    LightAqua = 0xB,
    LightRed = 0xC,
    LightPurple = 0xD,
    LightYellow = 0xE,
    BrightWhite = 0xF
};

class EBlockChar
{
public:
    inline static const string Block100 = "\xDB";
    inline static const string Block75 = "\xB2";
    inline static const string Block50 = "\xB1";
    inline static const string Block25 = "\xB0";
    inline static const string Block0 = "\x20";
};

class FConsole
{
public:
    FConsole();
    void SetForegroundColor(EConsoleColor color);
    void SetBackgroundColor(EConsoleColor color);
    void SetColor(EConsoleColor background, EConsoleColor foreground);
    void ResetColor();
    void SetCursorPosition(int left, int top);
    void SetCursorVisible(bool value);
    void PrintAskTable();

private:
    void SetCurrentColor();
    EConsoleColor background;
    EConsoleColor foreground;
    HANDLE hConsole;
};
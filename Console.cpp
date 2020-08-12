#pragma once

#include <iostream>
#include "Console.h"
#include "Windows.h"

using namespace std;

const CONSOLE_CURSOR_INFO *info = new CONSOLE_CURSOR_INFO();

FConsole::FConsole()
{
    this->background = EConsoleColor::Black;
    this->foreground = EConsoleColor::White;
    this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

void FConsole::SetForegroundColor(EConsoleColor color)
{
    SetColor(this->background, color);
}

void FConsole::SetBackgroundColor(EConsoleColor color)
{
    SetColor(color, this->foreground);
}

void FConsole::SetColor(EConsoleColor background, EConsoleColor foreground)
{
    this->background = background;
    this->foreground = foreground;
    SetCurrentColor();
}

void FConsole::ResetColor()
{
    this->background = EConsoleColor::Black;
    this->foreground = EConsoleColor::White;
    SetCurrentColor();
}

void FConsole::SetCursorPosition(int left, int top)
{
    COORD pos;
    pos.X = left;
    pos.Y = top;
    SetConsoleCursorPosition(this->hConsole, pos);
}

void FConsole::SetCursorVisible(bool value)
{
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(this->hConsole, &cursorInfo);
    cursorInfo.bVisible = value;
    SetConsoleCursorInfo(this->hConsole, &cursorInfo);
}

void FConsole::SetCurrentColor()
{
    int colorCode = (int)this->foreground | (int)this->background << 4;
    SetConsoleTextAttribute(this->hConsole, colorCode);
}

void FConsole::PrintAskTable()
{
    cout << "0 = \x0" << endl;
    cout << "1 = \x1" << endl;
    cout << "2 = \x2" << endl;
    cout << "3 = \x3" << endl;
    cout << "4 = \x4" << endl;
    cout << "5 = \x5" << endl;
    cout << "6 = \x6" << endl;
    cout << "7 = \x7" << endl;
    cout << "8 = \x8" << endl;
    cout << "9 = \x9" << endl;
    cout << "a = \xa" << endl;
    cout << "b = \xb" << endl;
    cout << "c = \xc" << endl;
    cout << "d = \xd" << endl;
    cout << "e = \xe" << endl;
    cout << "f = \xf" << endl;
    cout << "10 = \x10" << endl;
    cout << "11 = \x11" << endl;
    cout << "12 = \x12" << endl;
    cout << "13 = \x13" << endl;
    cout << "14 = \x14" << endl;
    cout << "15 = \x15" << endl;
    cout << "16 = \x16" << endl;
    cout << "17 = \x17" << endl;
    cout << "18 = \x18" << endl;
    cout << "19 = \x19" << endl;
    cout << "1a = \x1a" << endl;
    cout << "1b = \x1b" << endl;
    cout << "1c = \x1c" << endl;
    cout << "1d = \x1d" << endl;
    cout << "1e = \x1e" << endl;
    cout << "1f = \x1f" << endl;
    cout << "20 = \x20" << endl;
    cout << "21 = \x21" << endl;
    cout << "22 = \x22" << endl;
    cout << "23 = \x23" << endl;
    cout << "24 = \x24" << endl;
    cout << "25 = \x25" << endl;
    cout << "26 = \x26" << endl;
    cout << "27 = \x27" << endl;
    cout << "28 = \x28" << endl;
    cout << "29 = \x29" << endl;
    cout << "2a = \x2a" << endl;
    cout << "2b = \x2b" << endl;
    cout << "2c = \x2c" << endl;
    cout << "2d = \x2d" << endl;
    cout << "2e = \x2e" << endl;
    cout << "2f = \x2f" << endl;
    cout << "30 = \x30" << endl;
    cout << "31 = \x31" << endl;
    cout << "32 = \x32" << endl;
    cout << "33 = \x33" << endl;
    cout << "34 = \x34" << endl;
    cout << "35 = \x35" << endl;
    cout << "36 = \x36" << endl;
    cout << "37 = \x37" << endl;
    cout << "38 = \x38" << endl;
    cout << "39 = \x39" << endl;
    cout << "3a = \x3a" << endl;
    cout << "3b = \x3b" << endl;
    cout << "3c = \x3c" << endl;
    cout << "3d = \x3d" << endl;
    cout << "3e = \x3e" << endl;
    cout << "3f = \x3f" << endl;
    cout << "40 = \x40" << endl;
    cout << "41 = \x41" << endl;
    cout << "42 = \x42" << endl;
    cout << "43 = \x43" << endl;
    cout << "44 = \x44" << endl;
    cout << "45 = \x45" << endl;
    cout << "46 = \x46" << endl;
    cout << "47 = \x47" << endl;
    cout << "48 = \x48" << endl;
    cout << "49 = \x49" << endl;
    cout << "4a = \x4a" << endl;
    cout << "4b = \x4b" << endl;
    cout << "4c = \x4c" << endl;
    cout << "4d = \x4d" << endl;
    cout << "4e = \x4e" << endl;
    cout << "4f = \x4f" << endl;
    cout << "50 = \x50" << endl;
    cout << "51 = \x51" << endl;
    cout << "52 = \x52" << endl;
    cout << "53 = \x53" << endl;
    cout << "54 = \x54" << endl;
    cout << "55 = \x55" << endl;
    cout << "56 = \x56" << endl;
    cout << "57 = \x57" << endl;
    cout << "58 = \x58" << endl;
    cout << "59 = \x59" << endl;
    cout << "5a = \x5a" << endl;
    cout << "5b = \x5b" << endl;
    cout << "5c = \x5c" << endl;
    cout << "5d = \x5d" << endl;
    cout << "5e = \x5e" << endl;
    cout << "5f = \x5f" << endl;
    cout << "60 = \x60" << endl;
    cout << "61 = \x61" << endl;
    cout << "62 = \x62" << endl;
    cout << "63 = \x63" << endl;
    cout << "64 = \x64" << endl;
    cout << "65 = \x65" << endl;
    cout << "66 = \x66" << endl;
    cout << "67 = \x67" << endl;
    cout << "68 = \x68" << endl;
    cout << "69 = \x69" << endl;
    cout << "6a = \x6a" << endl;
    cout << "6b = \x6b" << endl;
    cout << "6c = \x6c" << endl;
    cout << "6d = \x6d" << endl;
    cout << "6e = \x6e" << endl;
    cout << "6f = \x6f" << endl;
    cout << "70 = \x70" << endl;
    cout << "71 = \x71" << endl;
    cout << "72 = \x72" << endl;
    cout << "73 = \x73" << endl;
    cout << "74 = \x74" << endl;
    cout << "75 = \x75" << endl;
    cout << "76 = \x76" << endl;
    cout << "77 = \x77" << endl;
    cout << "78 = \x78" << endl;
    cout << "79 = \x79" << endl;
    cout << "7a = \x7a" << endl;
    cout << "7b = \x7b" << endl;
    cout << "7c = \x7c" << endl;
    cout << "7d = \x7d" << endl;
    cout << "7e = \x7e" << endl;
    cout << "7f = \x7f" << endl;
    cout << "80 = \x80" << endl;
    cout << "81 = \x81" << endl;
    cout << "82 = \x82" << endl;
    cout << "83 = \x83" << endl;
    cout << "84 = \x84" << endl;
    cout << "85 = \x85" << endl;
    cout << "86 = \x86" << endl;
    cout << "87 = \x87" << endl;
    cout << "88 = \x88" << endl;
    cout << "89 = \x89" << endl;
    cout << "8a = \x8a" << endl;
    cout << "8b = \x8b" << endl;
    cout << "8c = \x8c" << endl;
    cout << "8d = \x8d" << endl;
    cout << "8e = \x8e" << endl;
    cout << "8f = \x8f" << endl;
    cout << "90 = \x90" << endl;
    cout << "91 = \x91" << endl;
    cout << "92 = \x92" << endl;
    cout << "93 = \x93" << endl;
    cout << "94 = \x94" << endl;
    cout << "95 = \x95" << endl;
    cout << "96 = \x96" << endl;
    cout << "97 = \x97" << endl;
    cout << "98 = \x98" << endl;
    cout << "99 = \x99" << endl;
    cout << "9a = \x9a" << endl;
    cout << "9b = \x9b" << endl;
    cout << "9c = \x9c" << endl;
    cout << "9d = \x9d" << endl;
    cout << "9e = \x9e" << endl;
    cout << "9f = \x9f" << endl;
    cout << "a0 = \xa0" << endl;
    cout << "a1 = \xa1" << endl;
    cout << "a2 = \xa2" << endl;
    cout << "a3 = \xa3" << endl;
    cout << "a4 = \xa4" << endl;
    cout << "a5 = \xa5" << endl;
    cout << "a6 = \xa6" << endl;
    cout << "a7 = \xa7" << endl;
    cout << "a8 = \xa8" << endl;
    cout << "a9 = \xa9" << endl;
    cout << "aa = \xaa" << endl;
    cout << "ab = \xab" << endl;
    cout << "ac = \xac" << endl;
    cout << "ad = \xad" << endl;
    cout << "ae = \xae" << endl;
    cout << "af = \xaf" << endl;
    cout << "b0 = \xb0" << endl;
    cout << "b1 = \xb1" << endl;
    cout << "b2 = \xb2" << endl;
    cout << "b3 = \xb3" << endl;
    cout << "b4 = \xb4" << endl;
    cout << "b5 = \xb5" << endl;
    cout << "b6 = \xb6" << endl;
    cout << "b7 = \xb7" << endl;
    cout << "b8 = \xb8" << endl;
    cout << "b9 = \xb9" << endl;
    cout << "ba = \xba" << endl;
    cout << "bb = \xbb" << endl;
    cout << "bc = \xbc" << endl;
    cout << "bd = \xbd" << endl;
    cout << "be = \xbe" << endl;
    cout << "bf = \xbf" << endl;
    cout << "c0 = \xc0" << endl;
    cout << "c1 = \xc1" << endl;
    cout << "c2 = \xc2" << endl;
    cout << "c3 = \xc3" << endl;
    cout << "c4 = \xc4" << endl;
    cout << "c5 = \xc5" << endl;
    cout << "c6 = \xc6" << endl;
    cout << "c7 = \xc7" << endl;
    cout << "c8 = \xc8" << endl;
    cout << "c9 = \xc9" << endl;
    cout << "ca = \xca" << endl;
    cout << "cb = \xcb" << endl;
    cout << "cc = \xcc" << endl;
    cout << "cd = \xcd" << endl;
    cout << "ce = \xce" << endl;
    cout << "cf = \xcf" << endl;
    cout << "d0 = \xd0" << endl;
    cout << "d1 = \xd1" << endl;
    cout << "d2 = \xd2" << endl;
    cout << "d3 = \xd3" << endl;
    cout << "d4 = \xd4" << endl;
    cout << "d5 = \xd5" << endl;
    cout << "d6 = \xd6" << endl;
    cout << "d7 = \xd7" << endl;
    cout << "d8 = \xd8" << endl;
    cout << "d9 = \xd9" << endl;
    cout << "da = \xda" << endl;
    cout << "db = \xdb" << endl;
    cout << "dc = \xdc" << endl;
    cout << "dd = \xdd" << endl;
    cout << "de = \xde" << endl;
    cout << "df = \xdf" << endl;
    cout << "e0 = \xe0" << endl;
    cout << "e1 = \xe1" << endl;
    cout << "e2 = \xe2" << endl;
    cout << "e3 = \xe3" << endl;
    cout << "e4 = \xe4" << endl;
    cout << "e5 = \xe5" << endl;
    cout << "e6 = \xe6" << endl;
    cout << "e7 = \xe7" << endl;
    cout << "e8 = \xe8" << endl;
    cout << "e9 = \xe9" << endl;
    cout << "ea = \xea" << endl;
    cout << "eb = \xeb" << endl;
    cout << "ec = \xec" << endl;
    cout << "ed = \xed" << endl;
    cout << "ee = \xee" << endl;
    cout << "ef = \xef" << endl;
    cout << "f0 = \xf0" << endl;
    cout << "f1 = \xf1" << endl;
    cout << "f2 = \xf2" << endl;
    cout << "f3 = \xf3" << endl;
    cout << "f4 = \xf4" << endl;
    cout << "f5 = \xf5" << endl;
    cout << "f6 = \xf6" << endl;
    cout << "f7 = \xf7" << endl;
    cout << "f8 = \xf8" << endl;
    cout << "f9 = \xf9" << endl;
    cout << "fa = \xfa" << endl;
    cout << "fb = \xfb" << endl;
    cout << "fc = \xfc" << endl;
    cout << "fd = \xfd" << endl;
    cout << "fe = \xfe" << endl;
    cout << "ff = \xff" << endl;
}
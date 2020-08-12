#pragma onde

#include <thread>
#include <conio.h>
#include "Unreal.h"

using namespace std;

enum class EDirection
{
    None,
    Left,
    Top,
    Right,
    Botton
};

class FInputBuffer
{
public:
    void Start();
    void Disable();
    EDirection GetCurrent();

private:
    bool enabled;
    EDirection buffer;
};
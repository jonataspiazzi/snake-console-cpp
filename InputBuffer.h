#pragma once

#include <thread>
#include "Global.h"

using namespace std;

class FInputBuffer
{
public:
    void Start();
    void Disable();
    EDirection GetCurrent();
    void NotifyChar(int32 value);
    bool IsEnabled() const;

private:
    bool hasPreArrow;
    bool enabled;
    EDirection current;
    thread backgroundWorker;
};
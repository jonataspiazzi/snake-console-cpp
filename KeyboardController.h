#pragma once

#include <thread>
#include "Global.h"

using namespace std;

class FKeyboardController
{
public:
    void Listen();
    void Disable();
    EKeyboardInput GetInput();
    void OnKeydown(int32 key);
    bool IsEnabled() const;

private:
    bool hasPreArrow;
    bool enabled;
    EKeyboardInput input;
    thread backgroundWorker;
};
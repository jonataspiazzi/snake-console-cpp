#pragma onde

#include <thread>
#include "InputBuffer.h"

using namespace std;

void InternalThread(FInputBuffer *value)
{
}

void FInputBuffer::Start()
{
    thread t(InternalThread, *this);
}

EDirection FInputBuffer::GetCurrent()
{
    EDirection c = this->buffer;

    this->buffer = EDirection::None;

    return c;
}
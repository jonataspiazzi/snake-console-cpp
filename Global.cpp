#pragma once

#include "Global.h"

EGameStatus operator&(EGameStatus left, EGameStatus right)
{
    return (EGameStatus)((int32)left & (int32)right);
}
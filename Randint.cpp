#include"Randint.h"
#pragma once

int randint(int a, int b) {
    return a + rand() % (b - a + 1);
}
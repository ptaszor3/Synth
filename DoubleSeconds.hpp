#pragma once

#include <chrono>

using DoubleSeconds = std::chrono::duration<double>;

DoubleSeconds operator"" _ds(long double duration);
DoubleSeconds operator"" _ds(unsigned long long int duration);

#pragma once

#include <chrono>

using double_seconds = std::chrono::duration<double>;

double_seconds operator"" _ds(long double duration);
double_seconds operator"" _ds(unsigned long long int duration);

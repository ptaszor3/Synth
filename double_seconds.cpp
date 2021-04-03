#include "double_seconds.hpp"

double_seconds operator"" _ds(long double duration) {
	return double_seconds{duration};
}

double_seconds operator"" _ds(unsigned long long int duration) {
	return double_seconds{duration};
}

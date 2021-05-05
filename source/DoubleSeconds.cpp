#include "../include/DoubleSeconds.hpp"

DoubleSeconds operator"" _ds(long double duration) {
	return DoubleSeconds{duration};
}

DoubleSeconds operator"" _ds(unsigned long long int duration) {
	return DoubleSeconds{duration};
}

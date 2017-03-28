#pragma once

#include <math.h>

bool is_pentagonal(int number) {
	int tmp = 24 * number + 1;

	int sr = (int)sqrt((double)tmp);
	if (sr*sr == tmp) {
		return (1 + sr) % 6 == 0;
	}

	return false;
}


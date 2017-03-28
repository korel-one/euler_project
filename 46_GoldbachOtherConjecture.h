#pragma once

#include <math.h>
#include <iostream>

bool _is_prime(int number) {

	for (int i = 2; i*i <= number; ++i) {
		if (number%i == 0)
			return false;
	}

	return true;
}

bool check_curr(int number, int prime) {
	if ((number - prime) % 2 == 0) {
		int k = (int)sqrt(double(number - prime)/2);
		if (k*k == (number - prime)/2)
			return true;
	}
	return false;
}

bool check_composite(int number) {

	for (int i = number - 2; i > 2; i-=2) {
		if (_is_prime(i)) {
			if (!check_curr(number, i))
				continue;
			else
				return true;
		}
	}
	return false;
}

unsigned long next_odd_composite(unsigned long number) {
	
	auto i = number + 2;
	while (_is_prime(i)) {
		i += 2;
	}

	return i;
}

void execute_46() {

	unsigned long number = 35;

	while (check_composite(number)) {
		number = next_odd_composite(number);
	}

	std::cout << number << std::endl;
	
}
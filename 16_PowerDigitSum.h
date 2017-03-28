#pragma once

#include <iostream>

/*2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
What is the sum of the digits of the number 2^1000?*/

int digits_sum_of(int i_power) {
	int A[1000] = { 0 };
	A[0] = 1;
	int number_len = 1;

	for (int i = 0; i < i_power; i++) {
		for (int j = 0; j < number_len; j++) A[j] *= 2;
		for (int j = 0; j < number_len; j++) if (A[j] >= 10) { A[j] -= 10; A[j + 1]++; }
		if (A[number_len] != 0) number_len++;
	}

	int k = 0;
	for (int j = 0; j < number_len; j++) k += A[j];
	std::cout << k << std::endl;

	return 0;
}
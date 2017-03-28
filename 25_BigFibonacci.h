#pragma once

/*
The Fibonacci sequence is defined by the recurrence relation:

Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
Hence the first 12 terms will be:

F1 = 1
F2 = 1
F3 = 2
F4 = 3
F5 = 5
F6 = 8
F7 = 13
F8 = 21
F9 = 34
F10 = 55
F11 = 89
F12 = 144
The 12th term, F12, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
*/

#include <array>
#include <algorithm>

void fibonacci_of_1000_digits() {

	std::array<int, 1000> n_1 = { 0 }, n_2 = { 0 }, n = {0};

	n_1[0] = 1;
	n_2[0] = 1;

	int index = 2;
	while (n.back() == 0) {
		std::fill(n.begin(), n.end(), 0);
		++index;
		for (int i = 0; i < 1000; ++i) {
			n[i] += n_2[i] + n_1[i];
			if (n[i] >= 10) {
				++n[i + 1];
				n[i] -= 10;
			}
		}
		n_2 = n_1;
		n_1 = n;
	}
	std::cout << index << std::endl;
}

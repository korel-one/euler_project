#pragma once

/*The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, 
are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?*/

#include <algorithm>
#include <array>
#include <vector>
#include <iostream>


bool next_rotate_is_prime(int number, std::array<bool, 1000000>& is_prime) {
	int r = 1, tmp = number;
	while (tmp != 0) {
		r *= 10;
		tmp /= 10;
	}

	if (r > 0)
		r /= 10;

	int curr_number = number;
	
	while (is_prime[curr_number]) {
		curr_number = (curr_number % 10)*r + ((curr_number - curr_number % 10) / 10);
		if (curr_number == number)
			return true;
	}

	return false;
}

void execute_35() {
	std::array<bool, 1000000> is_prime;
	std::fill(is_prime.begin(), is_prime.end(), true);
	
	for (int i = 2; i < 1000000; ++i) {
		for (int factor = 2; factor*factor <= i; ++factor) {
			if (i%factor == 0) {
				is_prime[i] = false;
				break;
			}
		}
	}

	int circular_primes = 0;
	for (int i = 2; i < 1000000; ++i){
		if (is_prime[i] && next_rotate_is_prime(i, is_prime)) {
			std::cout << i << std::endl;
			++circular_primes;
		}
	}

	std::cout << "circular_primes = " << circular_primes << std::endl;
}
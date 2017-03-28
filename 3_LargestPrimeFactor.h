#pragma once

#include <algorithm>

/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

void largest_prime_factor()
{
	long long number = 600851475143;

	long long max_factor = number;
	
	long long min_factor = 2;

	while (max_factor != 1) {

		while (max_factor%min_factor != 0)
			++min_factor;

		max_factor /= min_factor;
		std::cout << "min_factor = " << min_factor << "\n"
			<< "max_factor = " << max_factor << std::endl;
}

	std::cout << "longest prime factor of 600851475143 = " << min_factor << std::endl;

}
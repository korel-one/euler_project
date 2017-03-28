#pragma once

#include "Primes.h"

#include <limits>
#include <iostream>

/*By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?*/

void prime_10001(){
	int primes_number = 6;
	int curr_prime = 13;
	while (primes_number < 10001)
	{
		curr_prime += 1;
		if (is_prime(curr_prime)){
			++primes_number;
		}
	}

	std::cout << "prime 10001 = " << curr_prime << std::endl;
}
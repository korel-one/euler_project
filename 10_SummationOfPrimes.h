#pragma once

#include "Primes.h"

#include <iostream>

/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.*/

bool _is_prime(int N) {
	int i = 5;
	while (i*i <= N && N%i != 0)
		i+=2;

	return N%i != 0;
}

//VERY SLOW!!!!!!!!!!!!!!!!!
void sum_of_primes()
{
	unsigned long long sum = 17;
	for (int i = 11; i < 2000000; i+=2) {
		if (i % 3 == 0)
			continue;
		if (_is_prime(i))
			sum += i;
	}

	std::cout << "sum_of_primes below 2000000 = " << sum << std::endl;
}
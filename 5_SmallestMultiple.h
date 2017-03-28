#pragma once
#include <iostream>

/*2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20 ?*/

void smallest_divisible_by_1_to_20()
{
	
	bool evenly_divisible = false;

	long long smallest_candidate = 2520;
	int divisor = 19; 

	// N % i = 0 for each i = 1..40
	//32 * 27 * 25 * 7 * 11 * 13 * 17 * 19 * 23 * 29 * 31 * 37;

	while (divisor != 10) {
		divisor = 19;
		smallest_candidate += 2520;
		while (smallest_candidate%divisor == 0 && divisor > 10)
			--divisor;
	}

	std::cout << "smallest divisible by 1 to 20 = " << smallest_candidate << std::endl;
}
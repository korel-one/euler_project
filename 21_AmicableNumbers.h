#pragma once


/*Let d(n) be defined as the sum of proper divisors of n(numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. 
The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.*/

#include <vector>
#include <iostream>

void amicable_numbers_sum() {

	std::array <int, 10000> sum_divisors_of = { 0 };
	for (int i = 2; i < 10000; ++i) {
		//int sum = 0;
		for (int j = 1; j < i; ++j) {
			if (i % j == 0){
				sum_divisors_of[i] += j;
				//std::cout << j << " ";
			}
		}
		//std::cout << "\n" << "sum["<<i<<"] = " << sum_divisors_of[i] << std::endl;
	}

	unsigned int sum = 0;
	for (int i = 2; i < 10000; ++i) {
		if (sum_divisors_of[i] < 10000 && 
			i == sum_divisors_of[sum_divisors_of[i]] &&
			sum_divisors_of[i] != sum_divisors_of[sum_divisors_of[i]]) {
			std::cout << "\n" << "i =" << i << "; sum[sum[i]] = " << sum_divisors_of[sum_divisors_of[i]]
				<< "; sum[i] = " << sum_divisors_of[i] << std::endl;
			sum += sum_divisors_of[i];
		}
	}

	std::cout << "amicable_numbers_sum = " << sum << std::endl;
}
#pragma once

/*An irrational decimal fraction is created by concatenating the positive integers:

0.12345678910 1 112131415161718192021...

It can be seen that the 12th digit of the fractional part is 1.

If d_n represents the n_th digit of the fractional part, find the value of the following expression.

d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000
*/

#include <numeric>
#include <iostream>

void execute_40() {
	int all_digits = 9; int mul = 1;

	int lower_bound = 10, upper_bound = 100; int r = 2;

	int next_num = 100;
	
	while (all_digits <= 1000000) {
		for (int i = lower_bound; i < upper_bound; ++i) {

			int curr_number = i;

			if (all_digits + r >= next_num) { //digit is in next curr_number  
				 int shift = std::abs(next_num - all_digits);

				 int tmp = curr_number;
				 int k = 0;
				 while (tmp > 0) {
					 tmp /= 10;
					 ++k;
				 }

				 tmp = curr_number;
				 int curr_k = 0;
				 while (curr_k < (k - shift)) {
					 tmp /= 10;
					 ++curr_k;
				 }

				 std::cout << "digit index = " << all_digits << " ;  value = " << tmp % 10<< std::endl;
				 mul *= tmp % 10;
				 next_num *= 10;
			}
			all_digits += r;
		}
		++r;

		lower_bound = lower_bound * 10; 
		upper_bound *= 10;
	}

	std::cout << "mul = " << mul << std::endl;
	
}
#pragma once

/*A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with 
denominators 2 to 10 are given:

	1/2	= 	0.5
	1/3	= 	0.(3)
	1/4	= 	0.25
	1/5	= 	0.2
	1/6	= 	0.1(6)
	1/7	= 	0.(142857)
	1/8	= 	0.125
	1/9	= 	0.(1)
	1/10	= 	0.1

Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit 
recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.*/

#include <algorithm>
#include <vector>
#include <set>

void execute_26() {
	int max_d = 1; int longest_cycle_len = 0;

	for (int d = 2; d < 1000; ++d) {
		int numerator = 1;
		std::set<int> curr_numerators;

		std::string tmp;

		while (numerator%d != 0) {
			while (numerator < d) {
				numerator *= 10;
			}

			if (curr_numerators.count(numerator) != 0) {
				if (curr_numerators.size() > longest_cycle_len) {
					longest_cycle_len = curr_numerators.size();
					max_d = d;
				}

				//std::cout << "1/" << d << " = 0.";
				//std::cout << tmp
				//	<< "; " << "longest_cycle_len = " << longest_cycle_len
				//	<< std::endl;
				break;
			}
			else {
				curr_numerators.insert(numerator);
				tmp += std::to_string(numerator/d);
				numerator = numerator %d;
			}

		}
	}

	std::cout << "max_d = " << max_d << "; len = " << longest_cycle_len << std::endl;
}


#pragma once

/*It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, 
but in a different order.

Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.*/

#include <algorithm>

// неповтор€ющиес€ цифры?
void execute_52() {

//	int curr_range = 10;
	for (int i = 1;; ++i) {

//		if (i >= curr_range)
//			curr_range *= 10;

		int curr_mul = 6;
		std::string i_str = std::to_string(i);
		std::sort(i_str.begin(), i_str.end());

		while (/*i*curr_mul < curr_range &&*/ curr_mul > 1) {
			std::string curr = std::to_string(i*curr_mul);
			std::sort(curr.begin(), curr.end());
			if (curr == i_str)
				--curr_mul;
			else
				break;
		}

		if (curr_mul == 1) {
			std::cout << i << std::endl;
			break;
		}
	}
}
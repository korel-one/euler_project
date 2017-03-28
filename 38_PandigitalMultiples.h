#pragma once

/* Take the number 192 and multiply it by each of 1, 2, and 3:

	192 × 1 = 192
	192 × 2 = 384
	192 × 3 = 576

By concatenating each product we get the 1 to 9 pandigital, 192384576. 
We will call 192384576 the concatenated product of 192 and (1,2,3)

The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, 
giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).

What is the largest 1 to 9 pandigital 9-digit number that can be formed as the 
concatenated product of an integer with (1,2, ... , n) where n > 1?*/

#include <algorithm>
#include <string>
#include <iostream>

void execute_38() {
	int largest_pandigital = 0;
	//for (int i = 123456789; i <= 987654321; ++i) {
		for (int j = 1; j < 9999; ++j) { //9999*1 + 9999*2 = 9999 19998

			std::string check_pandigital;
			int digits = 0; int k = 0;
			while (check_pandigital.size() < 9) {
				check_pandigital += std::to_string(j*(++k));
			}

			if (check_pandigital.size() > 9)
				continue;

			auto tmp = check_pandigital;
			std::sort(check_pandigital.begin(), check_pandigital.end());

			if (check_pandigital == "123456789") {
				int res = std::stoi(tmp);
				if (res > largest_pandigital)
					largest_pandigital = res;

				std::cout << j << ": k = 1 to " << k << "; pandigital = " << tmp << std::endl;
			}
		}
	//}
}
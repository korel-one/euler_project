#pragma once

#include <algorithm>
#include <iostream>
#include <string>

/* 012 021 102 120 201 210


   0123 0132 0213 0231 0312 0321
   1023 1032 1203 1230 1302 1320
   2013 2031 2103 2130 2301 2310
   3012 3021 3102 3120 3201 3210 */

#include <algorithm>

void execute_24() {

	std::string str = "0123456789";

	int i = 0;
	while ((i < 1000000 - 1) && std::next_permutation(str.begin(), str.end())) {
		++i;
	}
	std::cout << str << std::endl;


	str = "0123456789";
	str = "0123479865";
	i = 0;

//	while (i < 1000000-1) {
	{
		int k = -1;
		for (int i = str.size() - 1; i > 0; --i) {
			if (str[i] > str[i - 1]) {
				k = i - 1;
				break;
			}
		}

		int _i = -1;
		if (k != -1) {

			for (int j = k + 1; j < str.size(); ++j) {
				if (str[k] < str[j]) {
					_i = j;
				}
			}
		}

		std::swap(str[_i], str[k]);
		std::reverse(str.begin() + k + 1, str.end());
		++i;
	}

	std::cout << str << std::endl;
}
#pragma once

/*
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?


NOTE: Do not count spaces or hyphens. 
For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. 
The use of "and" when writing out numbers is in compliance with British usage.
*/

#include <array>

int letters_number() {
	int one_to_nine = 36;
	int ten_to_nineteen = 112;

	std::array<std::string, 8> twenty_to_ninety = 
		{ "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety" };

	int twenty_to_ninety_nine = 0;
	for (int i = 0; i < twenty_to_ninety.size(); ++i) {
		twenty_to_ninety_nine += one_to_nine + 10*twenty_to_ninety[i].size();
	}

	int sum_by_hundred = one_to_nine + ten_to_nineteen + twenty_to_ninety_nine;

	int hundred_and = std::string("hundred and").size() - 1;

	int one_to_nine_hundreds_and_len = 899 * ( one_to_nine + hundred_and);

	int sum_one_hundred_by_one_thousand = one_to_nine_hundreds_and_len + sum_by_hundred * 10;
	
	int one_thousand = std::string("one thousand").size() - 1;
	int one_hundred = std::string("one hundred").size() - 1;

	return sum_by_hundred + sum_one_hundred_by_one_thousand + one_thousand + one_hundred;
}
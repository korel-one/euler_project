#pragma once

/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

bool is_palindrome(int number)
{
	int q = 0, w = number;
	while (number != 0) {
		q = q * 10 + (number % 10);
		number /= 10;
	}
	return (q == w);

	int min_order = 10000
		, max_order = 100000;

	int order = number%max_order == number ? min_order : max_order;

	int tmp_number = number, reversed_number = 0;
	while (order >= 1) {
		reversed_number += order * (number % 10);
		order /= 10;
		number = (number - number%10) / 10;
	}

	return tmp_number == reversed_number;
}


#include <algorithm>
#include <iostream>

void largest_palindrome_product() {
	int lower_bound = 100, upper_bound = 999;

	int largest_palindrome = 0;

	for (int i = lower_bound; i <= upper_bound; ++i) {
		for (int j = i; j <= upper_bound; ++j) {
			int product = i*j;
			if (is_palindrome(product)) {
				largest_palindrome = std::max(largest_palindrome, product);
			}
		}
	}

	std::cout << "largest palindrome - the product of two 3-digit numbers: " << largest_palindrome << std::endl;
}
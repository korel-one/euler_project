#pragma once

#include <iostream>

/*
The sum of the squares of the first ten natural numbers is,
1^2 + 2^2 + ... + 10^2 = 385

The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)2 = 55^2 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

int sum_of_squares(int upper_bound) {
	int sum = 0;
	for (int i = 1; i <= upper_bound; ++i)
		sum += i*i;

	return sum;
}

int square_of_sum(int upper_bound) {
	int sum = (upper_bound + 1)* upper_bound / 2;

	return sum*sum;
}

void diff(){
	std::cout << "diff the sum of the squares and the square of the sum of 100: "
		<< square_of_sum(100) - sum_of_squares(100)<< std::endl;
}
#pragma once

/*A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. 
For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 
is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant 
if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as 
the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater 
than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced 
any further by analysis even though it is known that the greatest number that cannot be expressed as the 
sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.*/

#include <array>
#include <iostream>
#include <vector>


//slow!!!
void execute_23() {
	std::vector<int> abundant;

	//find propper divisors for number
	for (int i = 1; i < 28500; ++i) {
		int sum_proper_divisors = 0;
		for (int j = 1; j < i; ++j) {
			if (i%j == 0) {
				sum_proper_divisors += j;
			}
		}

		if (sum_proper_divisors > i)
			abundant.push_back(i);
	}

	std::array<int, 30000>  A;
	A.fill(0);
	
	for (auto& ab1 : abundant) {
		for (auto& ab2 : abundant) {
			if (ab1 + ab2 < A.size())
				A[ab1 + ab2] = 1;
		}
	}

	int sum = 0;
	for (int i = 0; i < 30000; ++i) {
		sum += (1 - A[i])*i;//if(A[i] == 0) sum += A[i];
	}

	std::cout << sum << std::endl;
}
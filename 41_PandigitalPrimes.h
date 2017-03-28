#pragma once

/* We shall say that an n-digit number is pandigital if it makes use of all 
the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists?*/

#include <algorithm>
#include <iostream>
#include <string>

bool is_prime(int n) {
	for (int i = 2; i*i <= n; ++i) {
		if (n%i == 0)
			return false;
	}

	return true;
}

void execute_41() {
	std::string pandigital = "987654321";
	std::string curr_pandigital = pandigital;

	int max_prime_pandigital = 0;
	int i = 0;
	std::string prev_pandigital = pandigital;
	while (!is_prime(std::stoi(curr_pandigital))) {
		++i;
		if (!std::prev_permutation(curr_pandigital.begin(), curr_pandigital.end())) {
			std::cout << "i: " << i << "; next permutation false: " << curr_pandigital << std::endl;

			i = 0;
			curr_pandigital = std::string(prev_pandigital.begin()+1, prev_pandigital.end());
			prev_pandigital = curr_pandigital;
		}
	}

	std::cout << "prime = " << curr_pandigital << std::endl;
}
#pragma once

/*we shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once;
for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39*186 = 7254, containing multiplicand, multiplier, and product
is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

HINT: some products can be obtained in more than one way so be sure to only include  it once in your sum*/

#include <algorithm>
#include <iostream>
#include <string>
#include <numeric>

void execute_32() {
	std::set<int> products;

	for (int i = 1; i < 10000; ++i) {
		for (int j = i + 1; j < 10000; ++j) {
			std::string curr = std::to_string(i) + std::to_string(j) + std::to_string(i*j);
			if (curr.size() > 9)
				continue;

			std::sort(curr.begin(), curr.end());
			if (curr == "123456789") {
				std::cout << i << "*"<< j  << "=" << i*j << std::endl;
				products.insert(i*j);
			}
		}
	}

	std::cout << std::accumulate(products.begin(), products.end(), 0) << std::endl;
}
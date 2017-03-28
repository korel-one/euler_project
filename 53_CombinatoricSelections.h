#pragma once

/*
There are exactly ten ways of selecting three from five, 12345:

123, 124, 125, 134, 135, 145, 234, 235, 245, and 345

In combinatorics, we use the notation, 5C3 = 10.

In general, nCr = n! / r!(n−r)! ,where r ≤ n, n! = n×(n−1)×...×3×2×1, and 0! = 1.

It is not until n = 23, that a value exceeds one-million: 23C10 = 1144066.
How many, not necessarily distinct, values of  nCr, for 1 ≤ n ≤ 100, are greater than one-million?*/

#include <vector>
#include <iostream>

void execute_53() {

	std::vector<std::vector<int>> pascal_triangle(101, std::vector<int>(101, 0));
	for (int i = 0; i < 101; ++i)
		pascal_triangle[i][0] = 1;

	int res = 0;

	for (int n = 1; n <= 100; ++n) { //rows
		for (int r = 1; r <= n; ++r) { //columns
			pascal_triangle[n][r] = pascal_triangle[n - 1][r - 1] + pascal_triangle[n - 1][r];

			if (pascal_triangle[n][r] > 1000000) {
				pascal_triangle[n][r] = 1000000; //otherwise int overflows
				++res;
			}
		}

		int i = 0;
		while (i < 101 && pascal_triangle[n][i]) {
			std::cout << pascal_triangle[n][i++] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << res << std::endl;
}
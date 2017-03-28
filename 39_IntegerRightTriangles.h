#pragma once

/*If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, 
there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p ≤ 1000, is the number of solutions maximised? */

#include <iostream>

void execute_39() {
	int max_triangles = 0, p_max = 0;

	for (int p = 1; p <= 1000; ++p) {
		int triangles = 0;

		for (int a = 1; a < 1000; ++a) {
			for (int b = a; b < 1000; ++b) {
				int c = p - a - b;
				if ((c > 0) && (c*c == a*a + b*b)) {// right triangle
					++triangles;
				}
			}
		}

		if (triangles > max_triangles) {
			max_triangles = triangles;
			p_max = p;
		}
	}

	std::cout << "p_max = " << p_max << std::endl;
}
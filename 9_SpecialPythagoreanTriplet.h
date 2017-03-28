#pragma once

#include <iostream>

/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

void pythagorean_triplet_product()
{
	for (int i = 3; i < 1000; ++i){
		for (int j = i + 1; j < 1000; ++j){
			int k = 1000 - i - j;
			if (k > 0 && (i*i + j*j) == k*k) {
				std::cout << "pythagorean_triplet_product = " << i * j * k << std::endl;
				return;
			}
		}
	}
}


	//for (int i = 3; i < 1000; ++i){
	//	for (int j = i + 1; j < 1000; ++j){
	//		for (int k = j + 1; k < 1000; ++k){
	//			if ((i*i + j*j) == k*k && (i + j + k) == 1000){
	//				std::cout << "pythagorean_triplet_product = " << i * j * k << std::endl;
	//				return;
	//			}
	//		}
	//	}
	//}
//}
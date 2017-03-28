#pragma once

#include <vector>
#include <numeric>
#include <iostream>

/*2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
What is the sum of the digits of the number 2^1000?*/

//int digits_sum_of(int i_power) {
//	int A[1000] = { 0 };
//	A[0] = 1;
//	int la = 1;
//
//	for (int i = 0; i < i_power; i++) {
//		for (int j = 0; j < la; j++) 
//			A[j] *= 2;
//		for (int j = 0; j < la; j++) {
//			if (A[j] >= 10) { 
//				A[j] -= 10; A[j + 1]++; 
//			}
//		}
//		if (A[la] != 0) 
//			la++;
//	}
//
//	int k = 0;
//	for (int j = 0; j < la; j++) k += A[j];
//	std::cout << k << std::endl;
//
//	return 0;
//}



/* n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100! */

void digits_sum_of_factorial(int i_power) { //N <= 100
	int A[1000] = { 0 };
	A[0] = 1;
	int number_len = 1;

	for (int i = 1; i <= 100; ++i) {
		for (int j = 0; j < number_len; ++j) {
			A[j] *= i;
		}
		number_len += 3;//max new length
		for (int j = 0; j < number_len; ++j) {
			if (A[j] >= 10){
				A[j + 1] += A[j] / 10;
				A[j] = A[j] % 10;
			}

			/*while (A[j] >= 10) {
				A[j] -= 10;
				++A[j + 1];
			}*/
		}

		while (A[number_len-1] == 0)
			--number_len;
	}

	int sum = 0;
	for (int i = 0; i < number_len; ++i)
		sum += A[i];


	//15 51 12 1004 33 309 85 98 4000000: 6+6 +3+5 +6+12 +13+17 +4: 12+8+18+30+4: 20+48+4 = 72
	std::cout <<"sum = "<< sum << "\n" <<"len = " <<number_len<< std::endl;
}
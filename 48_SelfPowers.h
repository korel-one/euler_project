#pragma once

#include <string>

//std::string self_power_of(int number) {
//
//}

//std::vector<int>& operator*(std::vector<int>& number, int n) {
//	int i = 0;
//	while (n > 0) {
//		number[i] * (n % 10);
//
//	}
//}

//std::vector<int> binpow(int a, int n) {
//	std::vector<int> res;
//
//	while (n) {
//		if (n & 1) { //odd 16^7 = (res*16)^6
//			res *= a;
//			--n;
//		}
//		else {// 16^8 -> (16*16)^4
//			a *= a; 
//			n /= 2;
//		}
//	}
//}

//unsigned long long binpow(int a, int n) {
//	if (n == 0)
//		return 1;
//	if (n % 2 == 1) {
//		return binpow(a, n - 1) * a;
//	}
//	else {
//		unsigned long long b = binpow(a, n / 2);
//		return b*b;
//	}
//}

#include <iostream>

void execute_48() {
	// 285 311 670 611

	//unsigned long long 18,446,744,073,709,551,615
	//                      437,893,890,380,859,375 (15*15)
	//                   18,446,744,073,709,551,616 (16*16 -> 2^64)

	//for (int i = 1; i < 1001; ++i){
//	int i = 16;
//	std::cout << i << "*" << i << " = " << binpow(i, i) << std::endl;
	//}

	long long sum = 0;
	for (int i = 1; i <= 1000; i++) {
		long long k = i % 10000000000LL;
		for (int j = 0; j < i - 1; j++) { k = (k*i) % 10000000000LL; }
		sum = (sum + k) % 10000000000LL;
	}
	std::cout << sum << std::endl;
}
#pragma once

/*The decimal number, 585 = 1001001001 (binary), is palindromic in both bases.
Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
(Please note that the palindromic number, in either base, may not include leading zeros.)*/

#include <array>
#include <iostream>

bool is_dec_palindrome(const std::array<int, 6>& number, int r) {
	int fi = 0, li = r - 1;
	while (fi <= li && number[fi] == number[li]) {
		++fi; --li;
	}

	return fi >= li;
}

bool is_base2_palindrome(int number) {

	//999999 (10) = 11110100001000111111 (2)
	int mask_left = 524288; //10000000000000000000
	int mask_right = 1;

	while (!(mask_left & number)) {
		mask_left >>= 1;
	}

//	while (!(mask_right & number)) {
//		mask_right <<= 1;
//	}
	if (mask_left == mask_right)
		return true;

	while ((mask_left >= mask_right) && ((number&mask_left) && (number&mask_right)) || (!(number&mask_left) && !(number&mask_right))) {
		mask_right <<= 1;
		mask_left >>= 1;
	}

	return mask_left <= mask_right;
}

bool is_palindrome(int num_, int base) {
	std::vector<int> num, rev;
	while (num_ > 0) {
		num.push_back(num_%base);
		num_ /= base;
	}
	rev = num;
	std::reverse(rev.begin(), rev.end());
	for (int i = 0; i < num.size(); i++) if (num[i] != rev[i]) return false;
	return true;
}

void execute_36() {

	std::array<int, 6> number;
	number.fill(0);

	unsigned long long sum = 0;

	for (int i = 1; i < 1000000; ++i){
		int curr_number = i, j = 0;
		while (curr_number > 0) {
			number[j++] = curr_number % 10;
			curr_number = (curr_number - curr_number % 10) / 10;
		}

		if (is_dec_palindrome(number, j) && is_base2_palindrome(i)) {
			//std::cout << i << "\n";
			sum += i;
			//todo: check binary palindrome
		}
	}

	std::cout << "sum = " << sum << std::endl;
}
#pragma once

//TODO: find the greatest common divisor

#include <vector>
#include <numeric>
#include <iostream>

int greatest_common_divisor(int val1, int val2) { //val1 > 0 && val2 > 0
	if (val1 < val2)
		return greatest_common_divisor(val2, val1);
	else if (val2 == 0)
		return val1;
	else if (val1%val2 == 0) {
		return val2;
	}
	else
		return greatest_common_divisor(val2, val1%val2);
}

void remove_equal_digit(int& num, int& denom) {
	int tmp_num = num, tmp_denom = denom;

	int n_d1 = tmp_num % 10
		, n_d2 = tmp_num / 10;

	int d_d1 = tmp_denom % 10
		, d_d2 = (tmp_denom - tmp_denom % 10) / 10;

	if (n_d1 == d_d1) {
		num = n_d2;
		denom = d_d2;
	}
	if (n_d1 == d_d2) {
		num = n_d2;
		denom = d_d1;
	}

	if (n_d2 == d_d1) {
		num = n_d1;
		denom = d_d2;
	}

	if (n_d2 == d_d2) {
		num = n_d1;
		denom = d_d1;
	}
}

void execute_33() {
	std::vector<int> numerators(98-10), denominators(99-11);

	std::iota(numerators.begin(), numerators.end(), 10);
	std::iota(denominators.begin(), denominators.end(), 11);

	for (auto& num : numerators) {
		for (auto& denom : denominators) {
			if (num % 10 == 0 && denom % 10 == 0)
				continue;

			if (num >= denom)
				continue;

			int gcd = greatest_common_divisor(num, denom);

			int lowest_num = num / gcd;
			int lowest_denom = denom / gcd;

			int ln2 = num, ld2 = denom;

			remove_equal_digit(ln2, ld2);

			if (ln2 == num && ld2 == denom)
				continue;

			gcd = greatest_common_divisor(ln2, ld2);
			ln2 /= gcd;
			ld2 /= gcd;

			if (lowest_num == ln2 && lowest_denom == ld2) {
				if (!(ln2 == 1 && ld2 == 1))
					std::cout << num << "/" << denom << " = " << ln2 << "/" << ld2 << std::endl;
			}
		}
	}

}
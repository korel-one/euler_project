#pragma once

#include <vector>
#include <string>
#include <iostream>

bool is_palindrome(unsigned long long number) {
	if (number % 10 == 0)
		return false;

	std::string n_str = std::to_string(number);
	std::string reverse_str;

	for (int i = n_str.length() - 1; i >= 0; --i)
		reverse_str.push_back(n_str[i]);

	return n_str == reverse_str;
}

unsigned long long reverse(unsigned long long number) {
	std::string n_str = std::to_string(number);
	std::string reverse_str;

	for (int i = n_str.length() - 1; i >= 0; --i)
		reverse_str.push_back(n_str[i]);

	return std::stoull(reverse_str);
}

bool produce_palindrome(unsigned long long number, int iterations = 1) {
	if (iterations < 50) {
		if (is_palindrome(number)) {
			std::cout << "palindrome = " << number;
			return true;
		}
		else
			return produce_palindrome(number + reverse(number), ++iterations);
	}
	else
		return false;
}

void execute_55() {

	//all are Lychrel until proven otherwise
	std::vector<bool> is_lychrel(10000, true);

	int lynchrel_numbers = 0;

	for (unsigned long long i = 1; i < 10000; ++i) {
		if (!produce_palindrome(i + reverse(i))) {
			++lynchrel_numbers;
			std::cout <<": for number = " << i << std::endl;
		}
	}

	std::cout << lynchrel_numbers << std::endl;

}

bool is_palindrome_(std::string number) {
	std::string reverse_str = number;

	std::reverse(reverse_str.begin(), reverse_str.end());

	return number == reverse_str;
}

bool produce_palindrome_(std::string number, int iterations = 0) {
	if (iterations < 50) {
		if (iterations > 0 && is_palindrome_(number)) {
//			std::cout << "palindrome = " << number << std::endl;
			return true;
		}
		else {
			std::string rev = number;
			std::reverse(rev.begin(), rev.end());
			int j = 0;
			for (int i = rev.size() - 1; i >= 0; i--) {
				number[i] += (j + rev[i] - '0');
				if (number[i] > '9') { j = 1; number[i] -= 10; }
				else j = 0;
			}
			if (j == 1) number = "1" + number;
//			std::cout << "   " << number << std::endl;
			return produce_palindrome_(number, ++iterations);
		}
	}
	else
		return false;
}

void execute_55_() {

	//all are Lychrel until proven otherwise
	std::vector<bool> is_lychrel(10000, true);

	int lynchrel_numbers = 0;

	for (unsigned long long i = 4900; i < 5000; ++i) {
		if (!produce_palindrome_(std::to_string(i))) {
			++lynchrel_numbers;
			std::cout << ": for number = " << i << std::endl;
		}
	}

	std::cout << lynchrel_numbers << std::endl;

}

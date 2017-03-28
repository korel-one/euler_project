#pragma once

/*The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

By converting each letter in a word to a number corresponding to its alphabetical position 
and adding these values we form a word value. 
For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle 
number then we shall call the word a triangle word.

Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly 
two-thousand common English words, how many are triangle words? */

#include <fstream>
#include <vector>
#include <string>
#include <numeric>

#include <unordered_map>

bool check_triangle(int number) {
	int i = 1;
	while (number > 0) {
		number -= i++;
	}
	return number == 0;
}

void execute_42() {

	int max_word = 0;

	std::ifstream ifs("p042_words.txt");
	std::vector<std::string> names;
	if (ifs.is_open()) {
		std::string line;
		while (std::getline(ifs, line, ',')) {
			if (max_word < line.size() - 2)
				max_word = line.size() - 2;

			names.push_back(line.substr(1, line.size() - 2));
		}
	}

	std::array<int, 'Z' - 'A' + 1> number_of;
	std::iota(number_of.begin(), number_of.end(), 1);


	std::unordered_map<int, bool> number_to_triangle;

	int max_number = 'Z' - 'A' + 1;
	int triangle_upper_bound = max_number*max_word;

	int N = 0;

	for (auto& word : names) {
		int number = 0;
		for (int i = 0; i < word.size(); ++i) {
			number += number_of[word[i] - 'A'];
		}
		if (!number_to_triangle.count(number)) {
			number_to_triangle[number] = check_triangle(number);
		}

		N += number_to_triangle[number];
	}
}
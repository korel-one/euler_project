#pragma once

/* Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, 
begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value 
by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, 
is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file? */

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

void total_names_scores_in_the_file()
{
	std::ifstream ifs("p022_names.txt");
	std::vector<std::string> names;
	if (ifs.is_open()) {
		std::string line;
		while (std::getline(ifs, line, ',')) {
			names.push_back(line.substr(1, line.size() - 2));
			/*std::istringstream iss(line);
			names = std::vector<std::string>(std::istream_iterator<std::string>(iss,)
			, std::istream_iterator<std::string>());			*/
		}
	}

	std::sort(names.begin(), names.end());

	// long long total
	std::vector<int> scores(names.size());
	for (int i = 0; i < names.size(); ++i) {
		// int q;
		for (int j = 0; j < names[i].size(); ++j) {
			// q += -||-
			scores[i] += (names[i][j] - 'A' + 1);
		}
		// total += q*(i+1)
		scores[i] *= (i+1);
	}

	unsigned long long total = 0, max = std::numeric_limits<unsigned long long>::max();
	int i = 0;
	for (auto& val : scores) {
		if (total + val < max) {
			total += val;
			++i;
		}
		else
			break;
	}
	
	
	std::cout << "total = " << total << std::endl;
}
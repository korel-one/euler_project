#pragma once

/*The following iterative sequence is defined for the set of positive integers :

n → n / 2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence :

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence(starting at 13 and finishing at 1) contains 10 terms.Although it has not been proved yet(Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain ?

NOTE : Once the chain starts the terms are allowed to go above one million.*/

#include <algorithm>
#include <iostream>

const int NN = 10000000;
int FF[NN];
int CL(long long q) {
	if (q < NN) {
		if (FF[q] == -1) {
			FF[q] = 1 + CL(q % 2 ? 3 * q + 1 : q / 2);
		}
		return FF[q];
	}
	return 1 + CL(q % 2 ? 3 * q + 1 : q / 2);
}

void collatz_longest_chain_number(int n) {
	memset(FF, 0xFF, sizeof(FF));
	FF[1] = 1;
	int j = 1;
	for (int i = 1; i <= n; i++) j = std::max(j, CL(i));
	std::cout << j << std::endl;
	return;

	//int max_chain_len = 1, max_num = 1;

	//std::vector<int> len;
	//len.reserve(n+1);
	//len.push_back(0);

	//for (int i = 1; i <= n; ++i) {
	//	long long curr = i, next = curr, chain_len = 1;

	//	while (next != 1) {
	//		if (curr % 2)
	//			next = curr * 3 + 1;
	//		else
	//			next = curr / 2;

	//		//if (next < i) {
	//		//	chain_len += 1 + len[next];
	//		//	break;
	//		//}

	//		curr = next;


	//		++chain_len;
	//	}
	//	len.push_back(chain_len);

	//	if (chain_len > max_chain_len) {
	//		max_chain_len = chain_len;
	//		max_num = i;
	//	}
	//}

	//std::cout << "max_num = " << max_num
	//	<< " max_chain = " << max_chain_len << std::endl;
}
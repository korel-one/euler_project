#pragma once

/*In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:

1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
It is possible to make £2 in the following way:

1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
How many different ways can £2 be made using any number of coins?*/


#include <array>
#include <iostream>

int FF[210][10];

int ways_to_made_200(int balance, int major_coin_index, const std::array<int, 8>& i_nominal) {
	if (balance == 0)
		return 1;//only possible coin = major_coin_index
	if (balance < 0) return 0;
	if (FF[balance][major_coin_index] == -1) {
		int ans = 0;
		for (int q = 0; q <= major_coin_index; q++)
			ans += ways_to_made_200(balance - i_nominal[q], q, i_nominal);
		FF[balance][major_coin_index] = ans;
	}
	return FF[balance][major_coin_index];
}

void execute_31() {
	std::array<int, 8> nominal = {1, 2, 5, 10, 20, 50, 100, 200};

	memset(FF, 0xFF, sizeof(FF));

	//each item of FF whould be set to 4294967295 value
	//                                 4294967295
	int a = 4294967295;
	std::cout <<"sizeof(int FF[210][10]) = " <<sizeof(FF) << std::endl;

	std::cout << ways_to_made_200(200, 7, nominal) << std::endl;
}
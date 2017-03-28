#pragma once

/*The number 3797 has an interesting property. Being prime itself, it is possible to continuously 
remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly 
we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.*/

#include <array>
#include <iostream>

void execute_37() {
	std::vector<bool> is_prime(1000000, true);
//	std::array<bool, 2000000> is_prime;

//	is_prime.fill(true);

	is_prime[1] = false;
	for (int i = 2; i < is_prime.size(); ++i) if (is_prime[i]) {
//		std::cout << i << std::endl;
		for (long long factor = i; factor*i < is_prime.size(); ++factor) {
			is_prime[i*factor] = false;
		}
	}

	int sum_truncatable = 0, n = 11;

	for (int i = 11; i < is_prime.size(); ++i) {
		if (is_prime[i]) {
			int tmp = i;
			while (tmp > 0 && is_prime[tmp/10]) {
				tmp = (tmp - tmp % 10) / 10;
			}

			if (tmp > 0)
				continue;
			
			int rank = 1;
			tmp = i;
			while (tmp > 0) {
				tmp /= 10;
				rank *= 10;
			}

			tmp = i;
			while (rank > 10 && is_prime[tmp % (rank/10)]) {
				tmp = tmp % (rank / 10);
				rank /= 10;
			}

			if (rank == 10 && n > 0) {
				--n;
				sum_truncatable += i;
				std::cout << i << "\n";
				if (n == 0) break;
			}
		}
	}

	std::cout << "n = " << n << std::endl;
	std::cout << "sum = " << sum_truncatable << std::endl;
}
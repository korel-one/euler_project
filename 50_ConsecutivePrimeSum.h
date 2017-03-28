#pragma once

#include <vector>

std::vector<bool> sieve_eratothenes(int N, std::vector<int>& primes) {
	std::vector<bool> is_prime(N, true);

	primes.clear();

	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i < N; ++i) {
		if (is_prime[i]) {
			primes.push_back(i);
			for (int j = 2 * i; j < N; j += i) {
				is_prime[j] = false;
			}
		}
	}

	return is_prime;
}

#include <iostream>

void execute_50() {

	std::vector<int> primes;
	auto is_prime = sieve_eratothenes(1000000, primes);

	std::vector<unsigned long long> sum(primes.size());

	for (int i = 0; i < primes.size(); ++i) {
		sum[i + 1] = sum[i] + primes[i];
	}

	unsigned long long curr_sum = 0;
	for (auto p : primes) {

		if (curr_sum + p < 1000000){
			sum.push_back(curr_sum + p);
			curr_sum += p;
		}
		else
			break;
	}

	std::cout << sum.back() << std::endl;

}
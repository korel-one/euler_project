#pragma once

/* The primes 3, 7, 109, and 673, are quite remarkable. By taking any two primes and concatenating them 
in any order the result will always be prime. For example, taking 7 and 109, both 7109 and 1097 are prime. 
The sum of these four primes, 792, represents the lowest sum for a set of four primes with this property.

Find the lowest sum for a set of five primes for which any two primes concatenate to produce another prime.*/

#include <vector>
#include <string>
#include <map>
#include <iostream>

void create_primes_by(int upper_bound_number, std::vector<bool>& is_prime, std::vector<int>& primes) {
	primes.clear();

	is_prime[0] = is_prime[1] = false;

	for (int i = 2; i < upper_bound_number; ++i) {
		if (is_prime[i]) {
			primes.push_back(i);
			for (int j = i * 2; j < upper_bound_number; j += i) {
				is_prime[j] = false;
			}
		}
	}

}

void execute_60() {
	std::vector<bool> is_prime(1000000, true); std::vector<int> primes;
	create_primes_by(1000000, is_prime, primes);

	std::map<int, std::vector<int>> compatibles;

	for (int i = 0; primes[i] < 10000; ++i) {
		std::vector<int> compatible_primes;

		for (int j = i + 1; primes[j] < 10000; ++j) {

			int curr_forward = std::stoi(std::to_string(primes[i]) + std::to_string(primes[j]));
			int curr_backward = std::stoi(std::to_string(primes[j]) + std::to_string(primes[i]));

			if (curr_forward >= 1000000 || curr_backward >= 1000000)
				break;
			else if (is_prime[curr_forward] && is_prime[curr_backward])
				compatible_primes.push_back(primes[j]);
		}
		if (compatible_primes.size() >= 5)
			compatibles[primes[i]] = compatible_primes;
	}

	std::unordered_map<int, int> min_indices;
	for (auto& c : compatibles) {
		min_indices[c.first] = 0;
	}

	for (auto& item : compatibles) {
		std::vector<int> prime_sequence;
		prime_sequence.push_back(item.first);

		while (min_indices[item.first] < item.second.size() && prime_sequence.size() <= 5) {
			if (compatibles.count(compatibles[item.first][min_indices[item.first]]) != 0) {
				prime_sequence.push_back(compatibles[item.first][min_indices[item.first]]);
			}
				++min_indices[item.first];
		}

		if (prime_sequence.size() == 5) {
			std::cout << prime_sequence[0] << " "
				<< prime_sequence[1] << " "
				<< prime_sequence[2] << " "
				<< prime_sequence[3] << " "
				<< prime_sequence[4] << " ";
			return;
		}
	}
}
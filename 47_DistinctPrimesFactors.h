#pragma once

#include <iostream>
#include <vector>
#include <set>

namespace {
    //TODO: precalculate primes
    std::vector<bool> is_prime(1000000, true);
}

bool has_n_distinct_prime_factors(int number, int n) {
    int factor = 2; 
    std::set<int> distinct_factors;

    while (factor*factor <= number) {
        if (number%factor == 0) {
            distinct_factors.insert(factor);
            //std::cout << factor << ", ";
            number /= factor;
        }
        else
            ++factor;
    }

    if (number > 1) {
        //std::cout << number;
        distinct_factors.insert(number);
    }
        
    //std::cout << std::endl;
    return distinct_factors.size() == n;
}

void execute_47() {
    //is_prime[1] = false;

    bool four_distinct = false;
    for (int i = 1; i < 10000000; i++) {
		four_distinct = has_n_distinct_prime_factors(i, 4);
        if (!four_distinct)
            continue;
        
        for (int j = i + 1; j < i + 4; ++j) {
            //std::cout << j << std::endl;
            four_distinct &= has_n_distinct_prime_factors(j, 4);
        }
        if (four_distinct) {
            std::cout << i << std::endl;
            return;
        }
    }
}

void execute_47_() {
	int i = 1; 
	int k = 0;
	while (i < 1000000000) {
		if (!has_n_distinct_prime_factors(i++, 4)) {
			k = 0;
			continue;
		}
		k++;
		if (k == 4) {
			std::cout << i - 4 << std::endl;
			return;
		}
	}
}


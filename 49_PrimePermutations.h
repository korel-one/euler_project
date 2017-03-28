#pragma once

/* The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, 
is unusual in two ways: 
(i) each of the three terms are prime, and, 
(ii) each of the 4-digit numbers are permutations of one another.

There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, 
exhibiting this property, but there is one other 4-digit increasing sequence.

What 12-digit number do you form by concatenating the three terms in this sequence? */

#include <algorithm>
#include <array>
#include <string>
#include <vector>

void execute_49() {
    std::vector<bool> is_prime(9000, true);

    for (int i = 0; i < is_prime.size(); ++i) {
        int curr = 1000 + i;
        for (int factor = 2; factor*factor <= curr; ++factor) {
            if (curr%factor == 0)
                is_prime[i] = false;
        }
    }

    std::vector<int> sequential_primes;
    for (int i = 0; i < is_prime.size(); ++i) {
        if (is_prime[i]) {
            auto curr = std::to_string(1000 + i);
            int curr_prime = std::stoi(curr);

            std::sort(curr.begin(), curr.end());
          
            while (std::next_permutation(curr.begin(), curr.end())) {
                auto curr_permut = std::stoi(curr);

                if (curr_permut < 1000)
                    continue;

                if (is_prime[curr_permut - 1000] && curr_prime < curr_permut && (curr_permut-curr_prime)%3330 == 0) {
                    sequential_primes.push_back(curr_permut);
                }
            }
            if (sequential_primes.size() == 2) {
                std::cout << curr_prime << " ";
                if (sequential_primes[0] < sequential_primes[1])
                    std::cout << sequential_primes[0] << " " << sequential_primes[1] <<std::endl;
                else
                    std::cout << sequential_primes[1] << " " << sequential_primes[0] << std::endl;
            }
            sequential_primes.clear();
        }
    }

}
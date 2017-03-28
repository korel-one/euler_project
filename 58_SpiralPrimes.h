#pragma once

/* Starting with 1 and spiralling anticlockwise in the following way, a square spiral 
with side length 7 is formed.

    37* 36  35 34 33 32  31*
    38  17* 16 15 14 13* 30
    39  18  5* 4  3* 12  29
    40  19  6  1  2  11  28
    41  20  7* 8  9  10  27
    42  21  22 23 24 25  26
    43* 44  45 46 47 48  49

It is interesting to note that the odd squares lie along the bottom right diagonal, 
but what is more interesting is that 8 out of the 13 numbers lying along both diagonals are prime; 
that is, a ratio of 8/13 ≈ 62%

If one complete new layer is wrapped around the spiral above, a square spiral with side 
length 9 will be formed. If this process is continued, what is the side length of the 
square spiral for which the ratio of primes along both diagonals first falls below 10%? */

#include <iostream>

namespace _58 {

	bool _is_prime(int number) {
		for (int factor = 2; factor*factor <= number; ++factor) {
			if (number%factor == 0)
				return false;
		}
		return true;
	}

}

void execute_58() {
    int curr_step = 0;
    int curr_ratio = 100;
    int curr_number = 1;
    int side_len = 1;

    int diagonal_numbers = 0;
    int diagonal_primes = 0;
    while (curr_ratio >= 10) {
        diagonal_numbers += 4;
        side_len += 2;
        curr_step += 2;

        for (int i = 0; i < 4; ++i) {
            curr_number += curr_step;
            if (_58::_is_prime(curr_number)) {
                ++diagonal_primes;
            }
        }

        curr_ratio = (int)(diagonal_primes* 1.0/(diagonal_numbers + 1) * 100);
    }

    std::cout << side_len << std::endl;
}
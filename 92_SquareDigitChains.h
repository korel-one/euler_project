#pragma on


/* A number chain is created by continuously adding the square of the digits in a number 
to form a new number until it has been seen before.

For example,

44 → 32 → 13 → 10 → 1 → 1
85 → 89 → 145 → 42 → 20 → 4 → 16 → 37 → 58 → 89

Therefore any chain that arrives at 1 or 89 will become stuck in an endless loop. 
What is most amazing is that EVERY starting number will eventually arrive at 1 or 89.

How many starting numbers below ten million will arrive at 89? */

#include <iostream>

bool arrive_at_89(int number) {
    while (number != 1 && number != 89) {
        int curr_sum = 0;
        while (number > 0) {
            int d = number % 10;
            curr_sum += d*d;
            number /= 10;
        }
        number = curr_sum;
    }

    return number == 89;
}

void execute_92() {
    int count = 0;
    for (int i = -10000000; i > 1; --i) {
        count += arrive_at_89(i);
    }

	for (int i = 2; i < 100; i++) {
		if (!arrive_at_89(i)) printf("%3d\n", i);
	}

    std::cout << count << std::endl;
}
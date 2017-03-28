#pragma once

/* Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

(21) 22  23  24 (25)
 20  (7)  8  (9) 10
 19   6  (1)  2  11
 18  (5)  4  (3) 12
(17) 16   15  14 (13)

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way? */
#include <vector>
#include <iostream>

void spiral_diagonals_sum(int size) {
//	size = 5;
	long long q = 1;
	long long step = 1;
	long long sum = 0;
	for (int i = 0; i < size / 2; i++) {
		q += step;
		sum += q - 1;
		q += step;
		sum += q;
		step++;
		q += step;
		sum += q;
		q += step;
		sum += q;
		step++;
	}
	q += step;
	sum += q - 1;
	std::cout << sum << std::endl;
}

void _spiral_diagonals_sum(int size) {
	std::vector<std::vector<int>> matrix(size, std::vector<int>(size));

	int start_i = size / 2, start_j = size / 2;
	matrix[start_i][start_j] = 1;

	int diagonals_rd[] = { start_i, start_j }
		, diagonals_ld[] = { start_i, start_j }
		, diagonals_lu[] = { start_i, start_j }
		, diagonals_ru[] = { start_i, start_j };

	int diagonals_dx[] = {1, -1, -1, 1}, diagonals_dy[] = {1, 1, -1, -1};


	int move_dx[] = {0, -1, 0, 1}, move_dy[] = {1, 0, -1, 0};


	int curr_i = start_i, curr_j = start_j;
	unsigned int sum = 0;
	for (int i = 0; i < size/2; ++i) {
		int prev = matrix[curr_i][curr_j];
		matrix[curr_i][++curr_j] = prev + 1;

		//down
		diagonals_rd[0] += diagonals_dy[0];
		diagonals_rd[1] += diagonals_dx[0];
		while (curr_i < diagonals_rd[0]){ //y
			prev = matrix[curr_i][curr_j];
			curr_i += move_dy[0];
			curr_j += move_dx[0];
			matrix[curr_i][curr_j] = prev + 1;
		}
		sum += matrix[diagonals_rd[0]][diagonals_rd[1]];

		//left
		diagonals_ld[0] += diagonals_dy[1];
		diagonals_ld[1] += diagonals_dx[1];
		while (curr_j > diagonals_ld[1]) { //x
			prev = matrix[curr_i][curr_j];
			curr_i += move_dy[1];
			curr_j += move_dx[1];
			matrix[curr_i][curr_j] = prev + 1;
		}
		sum += matrix[diagonals_ld[0]][diagonals_ld[1]];

		//up
		diagonals_lu[0] += diagonals_dy[2];
		diagonals_lu[1] += diagonals_dx[2];

		while (curr_i > diagonals_lu[0]) {
			prev = matrix[curr_i][curr_j];
			curr_i += move_dy[2];
			curr_j += move_dx[2];
			matrix[curr_i][curr_j] = prev + 1;
		}
		sum += matrix[diagonals_lu[0]][diagonals_lu[1]];

		//right
		diagonals_ru[0] += diagonals_dy[3];
		diagonals_ru[1] += diagonals_dx[3];

		while (curr_j < diagonals_ru[1]) {
			prev = matrix[curr_i][curr_j];
			curr_i += move_dy[3];
			curr_j += move_dx[3];
			matrix[curr_i][curr_j] = prev + 1;
		}
		sum += matrix[diagonals_ru[0]][diagonals_ru[1]];
	}

	std::cout << "spiral diagonals' numbers sum = " << sum + matrix[start_i][start_j] << std::endl;
}
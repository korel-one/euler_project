#pragma once

#include <array>
#include <vector>

/*Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, 
there are exactly 6 routes to the bottom right corner.
How many such routes are there through a 20×20 grid ?*/

std::array<int, 2> dx = { 0, 1 }, dy = { 1, 0 };


//very slow!!!!!!!!!!
unsigned long long routes_number(int rows, int columns, int curr_row, int curr_column
	, std::vector<std::vector<int>>& grid) {

	if (curr_row == rows && curr_column == columns)
		return 1;
	else if (curr_row > rows || curr_column > columns)
		return 0;		

	if (grid[curr_row][curr_column] == 0) {
		grid[curr_row][curr_column] = routes_number(rows, columns, curr_row + dy[0], curr_column + dx[0]) + //down
			routes_number(rows, columns, curr_row + dy[1], curr_column + dx[1]); // or right
	}
	return grid[curr_row][curr_column];
}

unsigned long long routes_number(int rows, int columns, int curr_row, int curr_column) {
	std::vector<std::vector<int>> grid(rows, std::vector<int>(columns));
	for (int i = rows-1; i >= 0; i--) for (int j = columns - 1; j >= 0; j--) {
		grid[i][j] = (i < rows - 1) ? grid[i + 1][j] : 0 + (j < columns - 1) ? grid[i][j + 1] : 0;
		if (i == rows - 1 && j == columns - 1) grid[i][j] = 1;
	}
	return grid[0][0];
}
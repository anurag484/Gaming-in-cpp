#include <iostream>
#include <vector>
#include <random>
using namespace std;
// Size of the Sudoku grid
const int S = 9;

// Function to print the Sudoku grid
void printSudoku(const std::vector<std::vector<int>>& grid) {
    for (int i = 0; i < S; ++i) {
        for (int j = 0; j < S; ++j) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Checks whether it will be
// legal to assign num to the
// given row, col
bool isSafeview(const std::vector<std::vector<int>>& grid, int row,int col, int num)
{
	
	// Check if we find the same num
	// in the similar row , we
	// return false
	for (int x = 0; x <= 8; x++)
		if (grid[row][x] == num)
			return false;

	// Check if we find the same num in
	// the similar column , we
	// return false
	for (int x = 0; x <= 8; x++)
		if (grid[x][col] == num)
			return false;

	// Check if we find the same num in
	// the particular 3*3 matrix,
	// we return false
	int startRow = row - row % 3,
			startCol = col - col % 3;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (grid[i + startRow][j +
							startCol] == num)
				return false;

	return true;
}

/* Takes a partially filled-in grid and attempts
to assign values to all unassigned locations in
such a way to meet the requirements for
Sudoku solution (non-duplication across rows,
columns, and boxes) */
bool solveSudokuview( vector<vector<int>>& grid, int row, int col)
{
	// Check if we have reached the 8th
	// row and 9th column (0
	// indexed matrix) , we are
	// returning true to avoid
	// further backtracking
	if (row == 9 - 1 && col == 9)
		return true;

	// Check if column value becomes 9 ,
	// we move to next row and
	// column start from 0
	if (col == 9) {
		row++;
		col = 0;
	}

	// Check if the current position of
	// the grid already contains
	// value >0, we iterate for next column
	if (grid[row][col] > 0)
		return solveSudokuview(grid, row, col + 1);

	for (int num = 1; num <= 9; num++)
	{
		
		// Check if it is safe to place
		// the num (1-9) in the
		// given row ,col ->we
		// move to next column
		if (isSafeview(grid, row, col, num))
		{
			
		/* Assigning the num in
			the current (row,col)
			position of the grid
			and assuming our assigned
			num in the position
			is correct	 */
			grid[row][col] = num;
		
			// Checking for next possibility with next
			// column
			if (solveSudokuview(grid, row, col + 1))
				return true;
		}
	
		// Removing the assigned num ,
		// since our assumption
		// was wrong , and we go for
		// next assumption with
		// diff num value
		grid[row][col] = 0;
	}
	return false;
}
// Function to check if it's safe to place a number at a given position
bool isSafe(const std::vector<std::vector<int>>& grid, int row, int col, int num) {
    // Check if the number is already present in the row
    for (int i = 0; i < S; ++i) {
        if (grid[row][i] == num) {
            return false;
        }
    }

    // Check if the number is already present in the column
    for (int i = 0; i < S; ++i) {
        if (grid[i][col] == num) {
            return false;
        }
    }

    // Check if the number is already present in the 3x3 subgrid
    int subgridStartRow = row - row % 3;
    int subgridStartCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i + subgridStartRow][j + subgridStartCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(std::vector<std::vector<int>>& grid) {
    for (int row = 0; row < S; ++row) {
        for (int col = 0; col < S; ++col) {
            // Check if the cell is empty
            if (grid[row][col] == 0) {
                // Try different numbers from 1 to 9
                for (int num = 1; num <= 9; ++num) {
                    if (isSafe(grid, row, col, num)) {
                        // Place the number in the cell
                        grid[row][col] = num;

                        // Recursively solve the puzzle
                        if (solveSudoku(grid)) {
                            return true;
                        }

                        // If the current configuration is not valid, backtrack
                        grid[row][col] = 0;
                    }
                }

                // If no number can be placed in the cell, the puzzle is unsolvable
                return false;
            }
        }
    }

    // The entire puzzle has been filled
    return true;
}
void viewsol(vector<std::vector<int>>& grid){
	if (solveSudokuview(grid, 0, 0))
		printSudoku(grid);
	else
		cout << "no solution exists " << endl;

}
// Function to generate a Sudoku puzzle
vector<vector<int>> generateSudoku() {
    std::vector<std::vector<int>> grid(S, std::vector<int>(S, 0));

    // Solve the puzzle
    if (solveSudoku(grid)) {
        // Remove some numbers to create the puzzle
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(0, S - 1);

        int numToRemove = 50; // Adjust the difficulty level by changing the number of removed cells

        while (numToRemove > 0) {
            int row = dis(gen);
            int col = dis(gen);

            if (grid[row][col] != 0) {
                grid[row][col] = 0;
                numToRemove--;
            }
        }

        // Print the puzzle
        return grid;
    } else {
        std::cout << "Unable to generate Sudoku puzzle." << std::endl;
    }
}

/*
int main() {
    vector<vector<int>>g=generateSudoku();
    printSudoku(g);
    viewsol(g);
    return 0;
}
*/
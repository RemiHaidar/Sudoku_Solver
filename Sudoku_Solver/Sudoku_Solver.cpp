#include <iostream>

#define EMPTY 0

int sudoku[9][9] = {
   0,0,7   ,0,0,0    ,4,0,6,
   8,0,0   ,4,0,0    ,1,7,0,
   0,0,0   ,3,0,0    ,9,0,5,
   0,0,0   ,7,0,5    ,0,0,8,
   0,0,0   ,0,0,0    ,0,0,0,
   4,0,0   ,2,0,8    ,0,0,0,
   7,0,4   ,0,0,3    ,0,0,0,
   0,5,2   ,0,0,1    ,0,0,9,
   1,0,8   ,0,0,0    ,6,0,0
};

void PrintGrid() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (j == 3 || j == 6) {
				std::cout << " | ";
				std::cout << " " << sudoku[i][j];
			}
			else {
				std::cout << " " << sudoku[i][j];
			}
		}
		if (i == 2 || i == 5) {
			std::cout << "\n";
			for (int c = 0; c < 9; c++)
				std::cout << "---";
		}
		std::cout << "\n";
	}
}

bool RowIsSafe(int row, int number) {
	for (int column = 0; column < 9; column++) {
		if (sudoku[row][column] == number) {
			return false;
		}
	}
	return true;
}
bool ColumnIsSafe(int column, int number) {
	for (int row = 0; row < 9; row++) {
		if (sudoku[row][column] == number) {
			return false;
		}
	}
	return true;
}
bool BoxIsSafe(int row, int column, int number) {
	int rowBox = floor(row / 3) * 3;
	int columnBox = floor(column / 3) * 3;

	for (int row = rowBox; row < rowBox + 3; row++) {
		for (int column = columnBox; column < columnBox + 3; column++) {
			if (sudoku[row][column] == number) {
				return false;
			}
		}
	}
	return true;
}


bool IsValidPlace(int row, int column, int number) {
	if (RowIsSafe(row, number) && ColumnIsSafe(column, number) && BoxIsSafe(row, column, number)) {
		return true;
	}
	return false;
}

bool FindEmptyLocation(int* row, int* column) {
	for (*row = 0; *row < 9; (*row)++) {
		for (*column = 0; *column < 9; (*column)++) {
			if (sudoku[*row][*column] == EMPTY) {
				return false;
			}
		}
	}
	return true;
}


bool SolveSudoku() {
	int row, column;
	if (FindEmptyLocation(&row, &column))
		return true;
	for (int n = 1; n <= 9; n++)
	{
		if (IsValidPlace(row, column, n))
		{
			sudoku[row][column] = n;
			if (SolveSudoku())
				return true;
			sudoku[row][column] = EMPTY;
		}
	}
	return false;
}


int main() {

	if (SolveSudoku())
		PrintGrid();
	else
		std::cout << "Sudoku does not have a solution!" << std::endl;

	std::cin.ignore();
}

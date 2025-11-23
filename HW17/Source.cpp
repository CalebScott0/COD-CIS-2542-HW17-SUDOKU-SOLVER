// This program currently finds all valid 4x4 Sudoku grids

// There are 288 possible SOLUTIONS to this problem!
// If you just randomly put values 1-4 into each of the 16 squares,
// there would be 4,294,967,296 POSSIBILITES to try!
// This recursive method only searches 9,860 of the possibilities!

// ----------
// ASSIGNMENT
// ----------
// 1) Convert the code below to find and print out valid 9x9 grids

// If you just randomly put values 1-9 into each of the 81 squares,
// there would be 1.96627e77 POSSIBILITES to try!

// There are 6,670,903,752,021,072,936,960 SOLUTIONS so as long 
// each output is a valid grid then you have done your job

// 2) Find the solution to this specific 9x9 Sudoku puzzle:
//                 8 7 6 9 0 0 0 0 0
//				   0 1 0 0 0 6 0 0 0
//				   0 4 0 3 0 5 8 0 0
//				   4 0 0 0 0 0 2 1 0
//				   0 9 0 5 0 0 0 0 0
//				   0 5 0 0 4 0 3 0 6
//				   0 2 9 0 0 0 0 0 8
//				   0 0 4 6 9 0 1 7 3
//				   0 0 0 0 0 1 0 0 4

#include <iostream>
#include <vector>

void PrintFourByFourGrid(const std::vector<int> & grid)
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			std::cout << grid[(i << 2) + j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

bool IsLegalRowColumnWhatever(const std::vector<int> & vector)
{
	std::vector<int> occurrences(vector.size() + 1);

	try
	{
		for (const int & i : vector)
		{
			++occurrences.at(i);
		}
	}

	catch (const std::exception &)
	{
		return false;
	}

	for (std::size_t i = 1; i < occurrences.size(); ++i)
	{
		if (occurrences[i] > 1)
		{
			return false;
		}
	}

	return true;
}

bool IsFourByFourSudokuLegal(const std::vector<int> & grid)
{
	int rows[] = { 0, 4, 8, 12 };
	for (const int & i : rows)
	{
		std::vector<int> v{ grid[i], grid[i + 1], grid[i + 2], grid[i + 3] };
		if (IsLegalRowColumnWhatever(v) == false)
		{
			return false;
		}
	}

	int columns[] = { 0, 1, 2, 3 };
	for (const int & i : columns)
	{
		std::vector<int> v{ grid[i], grid[i + 4], grid[i + 8], grid[i + 12] };
		if (IsLegalRowColumnWhatever(v) == false)
		{
			return false;
		}
	}

	int squares[] = { 0, 2, 8, 10 };
	for (const int & i : squares)
	{
		std::vector<int> v{ grid[i], grid[i + 1], grid[i + 4], grid[i + 5] };
		if (IsLegalRowColumnWhatever(v) == false)
		{
			return false;
		}
	}

	return true;
}

void GenerateValidFourByFourGrids(std::vector<int> & grid, int index)
{
	if (index == 16)
	{
		PrintFourByFourGrid(grid);
	}
	else
	{
		for (int i = 1; i <= 4; ++i)
		{
			grid[index] = i;
			if (IsFourByFourSudokuLegal(grid) == true)
			{
				GenerateValidFourByFourGrids(grid, index + 1);
			}
		}
		grid[index] = 0;
	}
}

void GenerateAllValidFourByFourGrids()
{
	std::vector<int> grid(16, 0);
	GenerateValidFourByFourGrids(grid, 0);
}

int main()
{
	GenerateAllValidFourByFourGrids();
	system("PAUSE");
	return 0;
}

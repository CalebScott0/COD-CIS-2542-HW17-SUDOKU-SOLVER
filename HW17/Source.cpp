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

const int SIZE = 9;

void PrintNineByNineGrid(const std::vector<int> & grid)
{
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			std::cout << grid[(i * 9) + j] << " ";
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

bool IsNineByNineSudokuLegal(const std::vector<int> & grid)
{
    // initialize rows array 
    int rows[SIZE];
    for(int i = 0; i < SIZE; ++i)
    {
        rows[i] = (i * 9);
    }

	for (const int & i : rows)
	{
        std::vector<int> v;
        for(int j = 0; j < SIZE; ++j)
        {
            v.push_back(grid[i + j]);
        }

		if (IsLegalRowColumnWhatever(v) == false)
		{
			return false;
		}
	}

	int columns[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

	for (const int & i : columns)
	{
        std::vector<int> v;
        for(int j = 0; j < SIZE; ++j)
        {
            v.push_back(grid[i + (j * 9)]);
        }

		if (IsLegalRowColumnWhatever(v) == false)
		{
			return false;
		}
	}

	int squares[] = { 0, 3, 6, 27, 30, 33, 54, 57, 60 };
	for (const int & i : squares)
	{
		std::vector<int> v{ grid[i], grid[i + 1], grid[i + 2],
                            grid[i + 9], grid[i + 10], grid[i + 11],
                            grid[i + 18], grid[i + 19], grid[i + 20] }; 

		if (IsLegalRowColumnWhatever(v) == false)
		{
			return false;
		}
	}

	return true;
}

void GenerateValidNineByNineGrids(std::vector<int> & grid, int index)
{
	if (index == 81)
	{
		PrintNineByNineGrid(grid);
	}
	else
    {
        if(grid[index] == 0)
        {
		    for (int i = 1; i <= 9; ++i)
		    {
		        grid[index] = i;
		        if (IsNineByNineSudokuLegal(grid) == true)
		        {
		    	    GenerateValidNineByNineGrids(grid, index + 1);
		        }
            
		    }
		    grid[index] = 0;
	    }
        else
        {
            GenerateValidNineByNineGrids(grid, index + 1);
        }
    }
}

void GenerateAllValidNineByNineGrids()
{
	//std::vector<int> grid(81, 0);
	//GenerateValidNineByNineGrids(grid, 0);

    std::vector<int> grid2 {  8, 7, 6, 9, 0, 0, 0, 0, 0,
        				      0, 1, 0, 0, 0, 6, 0, 0, 0,
   				              0, 4, 0, 3, 0, 5, 8, 0, 0,
        				      4, 0, 0, 0, 0, 0, 2, 1, 0,
        				      0, 9, 0, 5, 0, 0, 0, 0, 0,
        				      0, 5, 0, 0, 4, 0, 3, 0, 6,
				              0, 2, 9, 0, 0, 0, 0, 0, 8,
        				      0, 0, 4, 6, 9, 0, 1, 7, 3,
        				      0, 0, 0, 0, 0, 1, 0, 0, 4 } ;

    GenerateValidNineByNineGrids(grid2, 0);
}


int main()
{
	GenerateAllValidNineByNineGrids();

	//system("PAUSE");
	return 0;
}

#include "sudoku.h"

int sudoku::simple()
{
	int				i,j,t;

	++sudoku::passes;
	sudoku::eliminated = 0;

	//std::cout << "Pass " << sudoku::passes << " (simple)" << std::endl;
	
	for (i = 0; i < 9; ++i) {
		for (j = 0; j < 9; ++j) {
			t = (int)sudoku::problem[i][j][0];

			if (t != 0) {
				sudoku::elimcol(i, j);
				sudoku::elimrow(i, j);
				sudoku::elim3x3(i, j);
			}
		}
	}

	//std::cout << std::endl;
	
	//std::cout << "Updating working grid..." << std::endl;
	sudoku::update();

	//sudoku::print_working();
	//std::cout << std::endl;

	std::cout << "Pass " << sudoku::passes << " (simple)\t\teliminated: " << sudoku::eliminated << std::endl;

	return sudoku::eliminated;
}

int sudoku::nakedpairs()
{
	int				i,j,t;

	sudoku::eliminated = 0;
	++sudoku::passes;

	for (i = 0; i < 9; ++i) {
		for (j = 0; j < 9; ++j) {
			t = (int)sudoku::problem[i][j][0];

			if (t == 0) {

				
			}
		}
	}

	std::cout << "Pass " << sudoku::passes << " (nakedpairs)\teliminated: " << sudoku::eliminated << std::endl;
	return sudoku::eliminated;
}


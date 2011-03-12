#include "sudoku.h"

sudoku::sudoku(const char *prob[])
{
	int				i,j,t;

	// populate working grid
	for (i = 0; i < 9; ++i) {
		for (j = 0; j < 9; ++j) {
			sudoku::problem[i][j][0] = (char)(((int)prob[i][j])-48);

			if (sudoku::problem[i][j][0] == (char)0) {
				for (t = 1; t < 10; ++t)
					sudoku::problem[i][j][t] = (char)1;
			} else {
				for (t = 1; t < 10; ++t)
					sudoku::problem[i][j][t] = (char)0;

				t = (int)sudoku::problem[i][j][0];
				sudoku::problem[i][j][t] = (char)1;
			}
		}
	}

	//std::cout << "Loaded sudoku and created basic working grid.\n" << std::endl;

	//sudoku::print();
	//sudoku::print_working();

	sudoku::passes = 0;
	sudoku::eliminated = 0;
}

sudoku::~sudoku()
{

}

bool sudoku::setval(int x, int y, int v)
{
	if (sudoku::getval(x,y) == 0) {
		sudoku::problem[x][y][0] = (char)v;
		return true;
	}

	return false;
}

bool sudoku::solved()
{
	int i, j, tmp;

	// sum all rows
	for (i = 0; i < 9; ++i)
	{
		tmp = 0;
		for (j = 0; j < 9; ++j)
			tmp += sudoku::getval(i,j);

		if (tmp != 45) return false;
	}

	// sum all cols
	for (j = 0; j < 9; ++j)
	{
		tmp = 0;
		for (i = 0; i < 9; ++i)
			tmp += sudoku::getval(i,j);

		if (tmp != 45) return false;
	}

	return true;
}

int sudoku::getval(int x, int y)
{
	return (int)sudoku::problem[x][y][0];
}

void sudoku::elimrow(int x, int y)
{
	int			j, v;

	v = sudoku::getval(x,y);

	for (j = 0; j < 9; ++j)
		if ( sudoku::getval(x,j) == 0 ) sudoku::elimpos(x,j,v);

	//std::cout << v << " eliminated from row " << x+1 << " because of " << x << "," << y << std::endl;
}

void sudoku::elimcol(int x, int y)
{
	int			i, v;

	v = sudoku::getval(x,y);

	for (i = 0; i < 9; ++i) {
		if ( sudoku::getval(i,y) == 0 ) sudoku::elimpos(i,y,v);
	}

	//std::cout << v << " eliminated from col " << y+1 << " because of " << x+1 << "," << y+1 << std::endl;
}

void sudoku::elim3x3(int x, int y)
{
	int si, sj, i, j, v;

	v = sudoku::getval(x,y);

	si = (x/3)*3;
	sj = (y/3)*3;

	for (i = si; i < si+3; ++i) {
		for (j = sj; j < sj+3; ++j) {
			if ( sudoku::getval(i,j) == 0 ) {
				sudoku::elimpos(i,j,v);

				//std::cout << v << " eliminated from 3x3 at " << i << "," << j << " because of " << x+1 << "," << y+1 << std::endl;
			}
		}
	}
}

void sudoku::elimpos(int x, int y, int v)
{
	if (sudoku::problem[x][y][v] != 0) sudoku::eliminated++;
	sudoku::problem[x][y][v] = 0;
}

void sudoku::getrow(int x, int *out)
{
	int			i;

	for (i = 0; i < 9; ++i )
		out[i] = sudoku::getval(x,i);
}

void sudoku::getcol(int y, int *out)
{
	int			i;

	for (i = 0; i < 9; ++i )
		out[i] = sudoku::getval(i,y);
}

void sudoku::getbox(int x, int y, int *out)
{
	int			i, j, si, sj, c;

	c = 0;

	si = (x/3)*3;
	sj = (y/3)*3;

	for (i = si; i < si+3; ++i) {
		for (j = sj; j < sj+3; ++j) {
			out[c] = sudoku::getval(i,j);
			c++;
		}
	}
}

void sudoku::update()
{
    int             i,j,t,x,c,last;

    for (i = 0; i < 9; ++i) {
		for (j = 0; j < 9; ++j) {
		    t = sudoku::getval(i,j);

		    if ( t == 0 ) {
		        // check it really hasn't got a value yet.

		        c = 0;
		        for (x = 1; x < 10; ++x) {
		            c += sudoku::problem[i][j][x];

		            if ( sudoku::problem[i][j][x] == 1 )
                        last = x;
		        }

		        if ( c == 1 ) {
		            // we found one possibility
		            sudoku::problem[i][j][0] = last;
		        }
		    }
		}
    }

}

void sudoku::print()
{
	int				i,j;

	std::cout << "Basic problem:\n" << std::endl;

	for (i = 0; i < 9; ++i) {
		for (j = 0; j < 9; ++j)
			std::cout << (int)sudoku::problem[i][j][0];

		std::cout << std::endl;
	}

	std::cout << std::endl;
}

void sudoku::print_working()
{
	int				i, j, t, x, c;

	std::cout << "Current working grid:\n" << std::endl;

	for (c = 0; c <= (9*9)+(3*9) ; ++c )
		std::cout << "-";
	std::cout << std::endl;

	for (i = 0; i < 9; ++i) {

		std::cout << "| ";

		for (j = 0; j < 9; ++j) {
			c = 0;

			for (t = 1; t < 10; ++t) {
				x = (int)sudoku::problem[i][j][t];

				if (x == 1) {
					++c;
					std::cout << t;
				}
			}

			if (sudoku::getval(i,j) != 0) {
				++c;
				std::cout << "*";
			}

			while (c < 10) {
				std::cout << " ";
				++c;
			}
			std::cout << "| ";
		}
		std::cout << std::endl;

		for (c = 0; c <= (9*9)+(3*9) ; ++c )
			std::cout << "-";
		std::cout << std::endl;
	}

	std::cout << std::endl;
}






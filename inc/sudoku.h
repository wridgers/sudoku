#ifndef _SUDOKU_H_
#define _SUDOKU_H_

#include <iostream>

class sudoku
{
public:
	sudoku(const char *prob[]);
	~sudoku();

	bool		setval(int x, int y, int v);
	bool		solved();

	int			getval(int x, int y);

	void		elimrow(int x, int y);
	void		elimcol(int x, int y);
	void		elim3x3(int x, int y);
	void		elimpos(int x, int y, int v);

	// methods
	int			simple();
	int			nakedpairs();

	// update working
	void        update();

	void		getrow(int x, int *out);
	void		getcol(int y, int *out);
	void		getbox(int x, int y, int *out);
	int			getpossibles(int x, int y);

	void		print();
	void		print_working();

protected:

private:
	char			problem[9][9][10];
	int				passes, eliminated;

};

#endif



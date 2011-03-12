#include "main.h"

int main()
{
	bool		solved;

	const char	*problem[9] = {	"093105640",
					"700000005",
					"501209307",
					"200000003",
					"036907520",
					"900000001",
					"302408109",
					"600000004",
					"047302850"  };

	int					mods = 1;	
	sudoku					*s;

	s = new sudoku(problem);

	s->print();

	while (mods != 0) {
		mods = s->simple();

		if (mods == 0) mods = s->nakedpairs();
	}

	std::cout << std::endl;
	std::cout << "System has done all it can." << std::endl;

	if (s->solved()) {
		std::cout << "Solved!" << std::endl << std::endl;
		s->print();
	} else {
		std::cout << "Can't be solved." << std::endl << std::endl;
		s->print_working();
	}
	
	delete s;
	return 0;
}



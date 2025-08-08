#pragma once

# include <algorithm>
# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <sstream>
# include <cmath>
# include <climits>
# include <sys/time.h>	

class PmergeMe {
	private:
		std::vector<int>					_vector;
		std::deque<int>						_deque;
		std::vector<std::pair<int, int> >	_vecPair;
		std::deque<std::pair<int, int> >	_deqPair;
		size_t								_nbElements;

		void			sortVector();
		void			sortDeque();
		PmergeMe();
	public:
		PmergeMe(int ac, char **av);
		~PmergeMe();
		void	run();
};

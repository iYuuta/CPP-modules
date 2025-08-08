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
		void			mergeInsertDeq(std::deque<int> mainChain);
		PmergeMe();
	public:
		PmergeMe(int ac, char **av);
		~PmergeMe();
		void	run();
};

template		<typename T>
bool		isSorted(T d)
{
	typename	T::iterator	it = d.begin();
	for (; it != d.end() - 1; ++it)
		if (*it > *(it + 1))	return	0;
	return	1;
}
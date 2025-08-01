#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <sstream>

class PmergeMe {
	private:
		std::vector<int>					_vector;
		std::deque<int>						_deque;
		std::vector<std::pair<int, int>>	_vecPair;
		std::vector<std::pair<int, int>>	_deqPair;

		void			sortVector();
		void			sortDeque();
		void			mergeInsertVec(std::vector<int>& mainChain);
		void			mergeInsertDeq(std::deque<int>& mainChain);
		PmergeMe();
	public:
		PmergeMe(std::string args);
		~PmergeMe();
		void	run();
};

template		<typename T>
bool		is_sorted(T d)
{
	typename	T::iterator	it = d.begin();
	for (; it != d.end() - 1; ++it)
		if (*it > *(it + 1))	return	0;
	return	1;
}
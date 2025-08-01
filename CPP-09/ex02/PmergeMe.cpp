#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(std::string args) {
	long num;
	std::istringstream oss(args);

	while (oss >> num) {
		if (num > INT32_MAX || num < 0)
			throw (std::string) "Invalid number";
		_deque.push_back(num);
		_vector.push_back(num);
	}
	if (_deque.size() < 2)
		throw (std::string) "too few arguments";
}

void PmergeMe::mergeInsertVec(std::vector<int>& mainChain) {
	if (is_sorted(mainChain))
		return ;
	int middle, start, end;
	
}

void PmergeMe::mergeInsertDeq(std::deque<int>& mainChain) {

}

void PmergeMe::sortVector() {
	int	a, b, stray;

	while (_vector.size() > 0) {
		if (_vector.size() == 1) {
			stray = _vector.front();
			_vector.erase(_vector.begin());
		}
		else {
			a = _vector.front();
			_vector.erase(_vector.begin());
			b = _vector.front();
			_vector.erase(_vector.begin());
			_vecPair.push_back(std::make_pair(a, b));
		}
	}

	for (std::vector<std::pair<int, int>>::iterator it = _vecPair.begin(); it != _vecPair.end(); it++) {
		if (it->first < it->second)
			std::swap(it->first, it->second);
	}

	std::vector<int> mainChain;
	for (size_t i = 0; i < _vecPair.size(); i++)
		mainChain.push_back(_vecPair[i].first);

	mergeInsertVec(mainChain);

	std::vector<int> pending;
	for (size_t i = 0; i < _vecPair.size(); i++)
		pending.push_back(_vecPair[i].second);

	// jacobsthal_insert(mainChain, pending);
}

void PmergeMe::sortDeque() {

}

void PmergeMe::run() {

}
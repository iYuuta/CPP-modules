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

void merge(std::vector<std::pair<int, int> >& arr, int left, int mid, int right) {
	std::vector<std::pair<int, int> > leftArr(arr.begin() + left, arr.begin() + mid + 1);
	std::vector<std::pair<int, int> > rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

	int i = 0, j = 0, k = left;
	while (i < (int)leftArr.size() && j < (int)rightArr.size()) {
		if (leftArr[i] <= rightArr[j])
			arr[k++] = leftArr[i++];
		else
			arr[k++] = rightArr[j++];
	}
	while (i < (int)leftArr.size())
		arr[k++] = leftArr[i++];
	while (j < (int)rightArr.size())
		arr[k++] = rightArr[j++];
}

void mergeSort(std::vector<std::pair<int, int> >& arr, int left, int right) {
	if (left >= right)
		return;
	int mid = left + (right - left) / 2;
	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}


std::vector<int> generateJacobsthal(int n) {
	std::vector<int> sequence;
	int num = 0;
	for (int i = 0; i < n; i++) {
		num = (pow(2, i) - pow(-1, i)) / 3;
		sequence.push_back(num);
	}
	return sequence;
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
	for (std::vector<std::pair<int, int> >::iterator it = _vecPair.begin(); it != _vecPair.end(); it++) {
		if (it->first < it->second)
			std::swap(it->first, it->second);
	}
	mergeSort(_vecPair, 0, _vecPair.size() - 1);
	std::vector<int> mainChain;
	mainChain.push_back(_vecPair.front().second);
	for (size_t i = 0; i < _vecPair.size(); i++)
		mainChain.push_back(_vecPair[i].first); 
	std::vector<int> pending;
	for (size_t i = 0; i < _vecPair.size(); i++)
		pending.push_back(_vecPair[i].second);
	std::vector<int> seq = generateJacobsthal(pending.size());

}

void PmergeMe::sortDeque() {

}

void PmergeMe::run() {
	sortVector();
}

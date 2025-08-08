#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(int ac, char **av) {
	long num;

	for (int i = 1; i < ac; i++) {
		std::istringstream oss(av[i]);
		if (!(oss >> num) || !oss.eof())
			throw (std::string) "Invalid number";
		if (num > INT32_MAX || num < 0)
			throw (std::string) "Invalid number";
		_deque.push_back(num);
		_vector.push_back(num);
	}
	if (_deque.size() < 2)
		throw (std::string) "too few arguments";
	_nbElements = _vector.size();
}

double get_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1e6 + tv.tv_usec;
}

void merge(std::deque<std::pair<int, int> >& arr, int left, int mid, int right) {
	std::deque<std::pair<int, int> > leftArr(arr.begin() + left, arr.begin() + mid + 1);
	std::deque<std::pair<int, int> > rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

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

void mergeSort(std::deque<std::pair<int, int> >& arr, int left, int right) {
	if (left >= right)
		return;
	int mid = left + (right - left) / 2;
	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);
	merge(arr, left, mid, right);
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

std::deque<int> generateJacobsthaldeq(int maxIndex) {
	std::deque<int> sequence;
	int i = 0;
	while (true) {
		int num = (pow(2, i) - pow(-1, i)) / 3;
		if (num >= maxIndex)
			break;
		sequence.push_back(num);
		i++;
	}
	return sequence;
}

std::vector<int> generateJacobsthalvec(int maxIndex) {
	std::vector<int> sequence;
	int i = 0;
	while (true) {
		int num = (pow(2, i) - pow(-1, i)) / 3;
		if (num >= maxIndex)
			break;
		sequence.push_back(num);
		i++;
	}
	return sequence;
}

void PmergeMe::sortVector() {
	long	a, b, stray = LONG_MAX;

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
	_vector.push_back(_vecPair.front().second);
	for (size_t i = 0; i < _vecPair.size(); i++)
		_vector.push_back(_vecPair[i].first); 
	_vecPair.erase(_vecPair.begin());
	std::vector<int> pending;
	for (size_t i = 0; i < _vecPair.size(); i++)
		pending.push_back(_vecPair[i].second);
	std::vector<int> seq = generateJacobsthalvec(pending.size());
	
	std::vector<bool> inserted(pending.size(), false);
	int value;
	std::vector<int>::iterator pos;

	size_t prev_jump = 1;
	for (size_t i = 2; i < seq.size(); ++i) {
    	int jump_index = seq[i];
	    if (jump_index >= (int)pending.size())
    	    break;
    	if (!inserted[jump_index]) {
	        int value = pending[jump_index];
	        auto pos = std::lower_bound(_vector.begin(), _vector.end(), value);
	    	_vector.insert(pos, value);
    	    inserted[jump_index] = true;
	    }
	    for (int j = jump_index - 1; j > (int)prev_jump; --j) {
	        if (!inserted[j]) {
    	        int value = pending[j];
	            auto pos = std::lower_bound(_vector.begin(), _vector.end(), value);
            	_vector.insert(pos, value);
        	    inserted[j] = true;
    	    }
	    }
    	prev_jump = jump_index;
	}
	for (size_t i = 0; i < pending.size(); ++i) {
		if (inserted[i])
			continue;
		value = pending[i];
		pos = std::lower_bound(_vector.begin(), _vector.end(), value);
		_vector.insert(pos, value);
	}
	if (stray != LONG_MAX) {
		pos = std::lower_bound(_vector.begin(), _vector.end(), stray);
		_vector.insert(pos, stray);
	}
}

void PmergeMe::sortDeque() {
    long a, b, stray = LONG_MAX;
    _deqPair.clear();
    while (!_deque.empty()) {
        if (_deque.size() == 1) {
            stray = _deque.front();
            _deque.pop_front();
        } else {
            a = _deque.front();
            _deque.pop_front();
            b = _deque.front();
            _deque.pop_front();
            _deqPair.push_back(std::make_pair(a, b));
        }
    }
    for (std::deque<std::pair<int, int>>::iterator it = _deqPair.begin(); it != _deqPair.end(); ++it) {
        if (it->first < it->second)
            std::swap(it->first, it->second);
    }
    mergeSort(_deqPair, 0, _deqPair.size() - 1);
    _deque.push_back(_deqPair.front().second);
    for (size_t i = 0; i < _deqPair.size(); i++)
        _deque.push_back(_deqPair[i].first);
    _deqPair.pop_front();
    std::deque<int> pending;
    for (size_t i = 0; i < _deqPair.size(); i++)
        pending.push_back(_deqPair[i].second);
    std::deque<int> seq = generateJacobsthaldeq(pending.size());
    std::deque<bool> inserted(pending.size(), false);
    int value;
    for (size_t i = 0; i < seq.size(); ++i) {
        int index = seq[i];
        if (index >= (int)pending.size() || inserted[index])
            continue;
        inserted[index] = true;
        value = pending[index];
        std::deque<int>::iterator pos = std::lower_bound(_deque.begin(), _deque.end(), value);
        _deque.insert(pos, value);
    }
    for (size_t i = 0; i < pending.size(); ++i) {
        if (inserted[i])
            continue;
        value = pending[i];
        std::deque<int>::iterator pos = std::lower_bound(_deque.begin(), _deque.end(), value);
        _deque.insert(pos, value);
    }
    if (stray != LONG_MAX) {
        std::deque<int>::iterator pos = std::lower_bound(_deque.begin(), _deque.end(), stray);
        _deque.insert(pos, stray);
    }
}

void PmergeMe::run() {
	std::cout << "Before:";
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++)
	std::cout << " " << *it;
	std::cout << std::endl;
	double end;
	double start = get_time();
	sortVector();
	end = get_time();
	double duration_On = (end - start);
	std::cout << "after: ";
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++)
		std::cout << " " << *it;
	std::cout << std::endl;
	std::cout << "Time to process a range of " << _nbElements << " elements with std::vector : " << duration_On << " us" << std::endl;

	// std::cout << "Before:";
	// for (std::deque<int>::iterator it = _deque.begin(); it != _deque.end(); it++)
	// std::cout << " " << *it;
	// std::cout << std::endl;
	start = get_time();
	sortDeque();
	end = get_time();
	duration_On = (end - start);
	// std::cout << "after: ";
	// for (std::deque<int>::iterator it = _deque.begin(); it != _deque.end(); it++)
	// 	std::cout << " " << *it;
	// std::cout << std::endl;
	std::cout << "Time to process a range of " << _nbElements << " elements with std::deque : " << duration_On << " us" << std::endl;
}

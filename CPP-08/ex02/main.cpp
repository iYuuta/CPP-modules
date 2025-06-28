#include "MutantStack.hpp"

int main() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(4);
    mstack.push(3);
    mstack.push(2);
    mstack.push(1);
    mstack.pop();
    for (std::deque<int>::iterator it = mstack.begin(); it != mstack.end(); it++) {
        std::cout << *it << std::endl;
    }
}

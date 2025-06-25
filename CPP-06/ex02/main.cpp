#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <typeinfo>

Base* generate(void) {
    int ran;

    srand((unsigned int)time(NULL));
    ran = rand() % 3;
    switch (ran) {
        case 0:
            return new A;
            break;
        case 1:
            return new B;
            break;
        case 2:
            return new C;
            break;
        default:
            break;
    }
    return NULL;
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "this pointer points to an A object\n";
    if (dynamic_cast<B*>(p))
        std::cout << "this pointer points to a B object\n";
    if (dynamic_cast<C*>(p))
        std::cout << "this pointer points to a C object\n";
}

void identify(Base& p) {
    try {
        A &tmp = dynamic_cast<A&>(p);
        (void)tmp;
        std::cout << "this is a reference to an A object\n";
    }
    catch (std::bad_cast&) {}
    try {
        B& tmp = dynamic_cast<B&>(p);
        (void)tmp;
        std::cout << "this is a reference to a B object\n";
    }
    catch (std::bad_cast&) {}
    try {
        C& tmp = dynamic_cast<C&>(p);
        (void)tmp;
        std::cout << "this is a reference to a C object\n";
    }
    catch (std::bad_cast&) {}
}

int main () {
    Base *rndm = generate();
    identify(rndm);
    identify(*rndm);
    return 0;
}
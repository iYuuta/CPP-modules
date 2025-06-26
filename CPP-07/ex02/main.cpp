#include "Array.hpp"
#include <cstdlib>

int		main() {
	int			size = 1;

	std::cout << "test 1:\n";
	Array<int>		one(size);
	one[0] = 12;

	std::cout << "index one: " << one[0] << std::endl;
	std::cout << "\ntest 2:\n";
	size = 3;
	Array<std::string>		two(size);
	two[0] = "first";
	two[1] = "second";
	two[2] = "third";
	for (int i=0; i< size; i++)
		std::cout << i << ": " << two[i] << std::endl;
	std::cout << "\ntest 3: copy\n";
	Array<std::string>		*first = new Array<std::string>(size);
	(*first)[0] = "some text added to First[]";
	Array<std::string>		const *second = new Array<std::string>(*first);
	delete	first;
	std::cout << "from Second[] after freeing First[]: " << (*second)[0] << std::endl;
	delete	second;
	std::cout << "\ntest 4: (empty)\n";
	try {
		Array<int>		empty(0);
		std::cout << "OK\n";
	}
	catch ( const std::exception &e )
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\ntest 5: on the heap\n";
	size = 2;
	Array<char>		*arr_ptr = new Array<char>(size);
	(*arr_ptr)[0] = 'O';
	(*arr_ptr)[1] = 'K';
	for (int i = 0;i<size; i++)
		std::cout << (*arr_ptr)[i];
	std::cout << std::endl;
	delete	arr_ptr;
	std::cout << "\ntest 6: error: retrieving beyond the size (empty)\n";
	try {
		size = 0;
		Array<float>	zero(size);
		std::cout << zero[0];
	}
	catch (const std::exception	&e)
	{
		std::cout << "failure: " << e.what() << std::endl;
	}
	std::cout << "\ntest 7: error: adding beyond the size\n";
	try {
		size = 10;
		Array<char>	three(size);
		three[11] = 'a';
		std::cout	<< three[0];
	}
	catch ( const std::exception	&e)
	{
		std::cout << "failure: " << e.what() << std::endl;
	}
	std::cout << "\ntest 8: error: negative input\n";
	try {
		size = -1;
		Array<int>	four(size);
		four[0] = 1;
		std::cout << four[0];
	}
	catch (const std::exception	&e)
	{
		std::cout << "failure: " << e.what() << std::endl;
	}
}
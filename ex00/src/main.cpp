#include <iostream>
#include <cstdlib>
#include <ctime>

#include "../inc/whatever.hpp"

#define CLI_GREEN		"\033[32m"
#define CLI_RESET		"\033[0m"
#define CLI_CYAN		"\033[36m"

#define TEST_LINE_LEN	100

#define DO_TEST(name, test_scope)					\
	do												\
	{												\
		testHeader(std::cout, name);				\
		test_scope									\
		testFooter(std::cout);						\
	} while(0)

void	testFooter(std::ostream &o)
{
	o << std::endl << CLI_GREEN;
	o << std::string(TEST_LINE_LEN, '-');
	o << CLI_RESET << std::endl;
}

void	testHeader(std::ostream &o, std::string name)
{
	size_t		len;

	testFooter(std::cout);
	if (name.length() > TEST_LINE_LEN / 2)
		name = "  " + name.substr(TEST_LINE_LEN / 2) + " test  ";
	else
		name = "  " + name + " test  ";
	o << std::endl << CLI_GREEN;
	len = (TEST_LINE_LEN / 2) - (name.length() / 2);
	o << std::string(len, '-') << name;
	if (name.length() & 1)
		len--;
	o << std::string(len, '-') << std::endl << std::endl << CLI_CYAN;
}

int main(void)
{
	const int	rand_range = 10;
	int	a;
	int	b;

	std::srand(std::time(NULL));
	DO_TEST("swap ints",
	{
		a = rand() % rand_range;
		b = rand() % rand_range;
		std::cout << "Before swap:" << std::endl << '\t';
		std::cout << "a == " << a << " b == " << b << std::endl;
		swap(a, b);
		std::cout << "After swap:" << std::endl << '\t';
		std::cout << "a == " << a << " b == " << b << std::endl;
	});
	DO_TEST("min ints",
	{
		a = rand() % rand_range;
		b = rand() % rand_range;
		std::cout << "a == " << a << " b == " << b << std::endl;
		std::cout << "(a addr) == " << &a << " (b addr) == " << &b;
		int	&_min = min<int>(a, b);
		std::cout << std::endl << "min == " << _min << std::endl;
		std::cout << "(min addr) == " << &_min << std::endl;
	});
	DO_TEST("max ints",
	{
		a = rand() % rand_range;
		b = rand() % rand_range;
		std::cout << "a == " << a << " b == " << b << std::endl;
		std::cout << "(a addr) == " << &a << " (b addr) == " << &b;
		int	&_max = max<int>(a, b);
		std::cout << std::endl << "max == " << _max << std::endl;
		std::cout << "(max addr) == " << &_max << std::endl;
	});
}

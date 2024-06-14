#include <iostream>
#include <cstdlib>
#include <ctime>

#include "../inc/iter.hpp"

#define CLI_GREEN		"\033[32m"
#define CLI_RESET		"\033[0m"
#define CLI_CYAN		"\033[36m"

#define TEST_LINE_LEN	100

#define DO_TEST(name, test_scope)		\
	do									\
	{									\
		testHeader(std::cout, name);	\
		test_scope						\
		testFooter(std::cout);			\
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

std::string	randomString()
{
	static const std::string	possible[] =
	{
		"sad",
		"OwO",
		"eggsD",
		"Something",
		"Nothing",
		"PoggieWoggie",
		"Wowzers",
		"Don't read this"
	};

	return (possible[rand() % (sizeof(possible) / sizeof(std::string))]);
}

std::string	*getStrings(unsigned long const &size)
{
	std::string	*strings;

	strings = new std::string[size];
	for (unsigned long i = 0; i < size; i++)
		strings[i] = randomString();
	return (strings);
}

int main(void)
{
	const unsigned long size = 10;

	std::srand(std::time(NULL));
	DO_TEST("print int arr",
		{
			const int			rand_range = 1024;
			int					arr[size];

			for (unsigned long i = 0; i < size; i++)
				arr[i] = rand() % rand_range;
			iter(arr, size, print);
		});
	DO_TEST("print string arr",
		{
			std::string	*arr = getStrings(size);

			iter(arr, size, print);
			delete [] arr;
		});
}

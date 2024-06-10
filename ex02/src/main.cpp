#include <iostream>
#include <cstdlib>
#include <ctime>

#include "../inc/Array.hpp"

#define CLI_GREEN		"\033[32m"
#define CLI_RESET		"\033[0m"
#define CLI_CYAN		"\033[36m"

#define TEST_LINE_LEN	100

#define TRY_CATCH_TEST(name, test_scope)			\
	do												\
	{												\
		testHeader(std::cout, name);				\
		try											\
			test_scope								\
		catch (std::exception &ex)					\
		{											\
			std::cout << ex.what() << std::endl;	\
		}											\
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
	size_t	padding_right;
	size_t	padding_left;

	testFooter(std::cout);
	if (name.length() > TEST_LINE_LEN / 2)
		name = "  " + name.substr(TEST_LINE_LEN / 2) + " test  ";
	else
		name = "  " + name + " test  ";
	o << std::endl << CLI_GREEN;
	padding_left = (TEST_LINE_LEN / 2) - (name.length() / 2);
	o << std::string(padding_left, '-') << name;
	padding_right = name.length() & 1 ? padding_left - 1 : padding_left;
	o << std::string(padding_right, '-') << std::endl;
	o << std::endl << CLI_CYAN;
}

int main(void)
{
	const unsigned int	size = 25;
 
	std::srand(std::time(NULL));
	TRY_CATCH_TEST("index into empty Array<int>",
		{
			Array<int>	arr;

			arr[0];
		});
	TRY_CATCH_TEST("iterate trough Array<int>",
	{
		Array<int>	arr(size);
		const int	rand_range = 1024;

		for (unsigned int i = 0; i < arr.size(); i++)
		{
			arr[i] = std::rand() % rand_range;
			std::cout << arr[i] << std::endl;	
		}
	});
	TRY_CATCH_TEST("Copying empty Array<int>",
	{
		Array<int>	empty;
		Array<int>	arr(empty);

		std::cout << arr[0] << std::endl;	
	});
	TRY_CATCH_TEST("Copy uses different memory",
	{
		Array<int>	orig(size);
		Array<int>	copy(orig);

		std::cout << "Original arr addr:\t" << &orig[0] << std::endl;	
		std::cout << "Copy arr addr:\t\t" << &copy[0] << std::endl;	
	});
}

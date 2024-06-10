#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	print(T const &to_print)
{
	std::cout << to_print << std::endl;
}

template <typename T>
void	iter(T *arr, unsigned long const &arr_len, void (*func)(T const &))
{
	for (unsigned long i = 0; i < arr_len; i++)
		func(*(arr + i));
}

#endif

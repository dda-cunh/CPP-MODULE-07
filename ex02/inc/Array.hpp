#ifndef ARRAY_HPP
# define ARRAY_HPP

# include "ExceptionMaker.hpp"

template <typename T>
class Array
{
	public:
		Array(void);
		Array(Array const & src);
		Array &operator=(Array const & rhs);
		~Array(void);

		Array(unsigned int size);

		T	&operator[](unsigned int)	const;

		unsigned int	size()			const;

	private:
		unsigned int	_size;
		T				*_arr;

		class IndexOutOfBounds : public ExceptionMaker
		{
			public:
				IndexOutOfBounds();
		};
};

#include "Array.tpp"

#endif
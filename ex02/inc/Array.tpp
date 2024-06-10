//-------------------------------  CANONICAL  -------------------------------//
template <typename T>
Array<T>::Array(void) : _size(0), _arr(NULL)
{
	// std::cout << "Default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(Array const & src) : _size(0), _arr(NULL)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

template <typename T>
Array<T>    &Array<T>::operator=(Array const & rhs)
{
	// std::cout << "Copy Assignement operator called" << std::endl;
	if (rhs._arr && rhs.size() != 0)
	{
		this->_size = rhs.size();
		this->_arr = new T[rhs.size()];
		for (unsigned int i = 0; i < rhs.size(); i++)
			this->_arr[i] = rhs._arr[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array(void)
{
	// std::cout << "Destructor called" << std::endl;
	if (this->_arr)
		delete [] this->_arr;
}
//---------------------------------------------------------------------------//

//------------------------------  CONSTRUCTORS  -----------------------------//
template <typename T>
Array<T>::Array(unsigned int size)
	: _size(size), _arr(new T[size])
{
	for (unsigned int i = 0; i < this->_size; i++)
		this->_arr[i] = T();
}
//---------------------------------------------------------------------------//

//----------------------------  MEMBER FUNCTIONS  ---------------------------//
template <typename T>
unsigned int	Array<T>::size()	const
{
	return (this->_size);
}
//---------------------------------------------------------------------------//

//------------------------------  EXCEPTIONS  -------------------------------//
template <typename T>
Array<T>::IndexOutOfBounds::IndexOutOfBounds()
	: ExceptionMaker("Given index goes beyond the array")
{

}
//---------------------------------------------------------------------------//

//------------------------------  OP Overloads  -----------------------------//
template <typename T>
T	&Array<T>::operator[](unsigned int i)	const
{
	if (i >= this->_size)
		throw (Array::IndexOutOfBounds());
	return (this->_arr[i]);
}
//---------------------------------------------------------------------------//

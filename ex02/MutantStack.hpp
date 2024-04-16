#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <string>
# include <iostream>
# include <stack>
# include <iterator>
# include <deque>

template <typename T>
class MutantStack : public std::stack<T>{

typedef typename std::deque<T>::iterator deque_iterator;

private:

public:

	/*CONSTRUCTORS*/
	MutantStack<T>(){std::cout << "class created" << std::endl;};
	MutantStack(MutantStack const &original)
	{
		if (this != &original)
		return(*this);
	}

	//Assignment operator:
	MutantStack &operator=(MutantStack const &original)
	{
		*this = original;
	}

	/*Iterators*/
	class iterator : public deque_iterator
	{
		public:
			iterator(const deque_iterator& iter) : deque_iterator(iter){}
	};


	// class deque_iterator : public std::iterator{};
	MutantStack<T>::iterator begin()
	{
		return(this->c.begin());
	}

	MutantStack<T>::iterator end()
	{
		return(this->c.end());
	}

	/*DESTRUCTOR*/
	~MutantStack(){};
};

#endif

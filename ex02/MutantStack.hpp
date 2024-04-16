#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <string>
# include <iostream>
# include <stack>
# include <iterator>
# include <deque>

template <typename T>
class MutantStack : public std::stack<T>{

typedef typename std::deque<T>::iterator deq_iterator;
typedef typename std::deque<T>::reverse_iterator deq_r_iterator;
typedef typename std::deque<T>::const_iterator deq_c_iterator;
typedef typename std::deque<T>::const_reverse_iterator deq_cr_iterator;

public:

	/*CONSTRUCTORS*/
	MutantStack<T>(){};
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
	class iterator : public deq_iterator
	{
		public:
			iterator(const deq_iterator& iter) : deq_iterator(iter){}
	};

	class reverse_iterator : public deq_r_iterator
	{
		public:
			reverse_iterator(const deq_r_iterator& iter) : deq_r_iterator(iter){}
	};

	class const_iterator : public deq_c_iterator
	{
		public:
			const_iterator(const deq_c_iterator& iter) : deq_c_iterator(iter){}
	};

	class const_reverse_iterator : public deq_cr_iterator
	{
		public:
			const_reverse_iterator(const deq_cr_iterator& iter) : deq_cr_iterator(iter){}
	};

	MutantStack<T>::iterator begin(){return(this->c.begin());}
	MutantStack<T>::reverse_iterator rbegin(){return(this->c.rbegin());}
	MutantStack<T>::const_iterator cbegin(){return(this->c.cbegin());}
	MutantStack<T>::const_reverse_iterator crbegin(){return(this->c.crbegin());}

	MutantStack<T>::iterator end(){return(this->c.end());}
	MutantStack<T>::reverse_iterator rend(){return(this->c.rend());}
	MutantStack<T>::const_iterator cend(){return(this->c.cend());}
	MutantStack<T>::const_reverse_iterator crend(){return(this->c.crend());}

	/*DESTRUCTOR*/
	~MutantStack(){};
};

#endif

#include "MutantStack.hpp"
template <typename T>
/*CONSTRUCTORS*/
MutantStack::MutantStack<T>()
{
	std::cout << "class created" << std::endl;
}

//Assignment operator:
MutantStack &MutantStack::operator=(MutantStack const &original)
{
	if (this != &original)
	return(*this);
}

MutantStack::MutantStack(MutantStack const &original)
{
	*this = original;
}

/*FUNCTIONS*/
/*DESTRUCTOR*/
MutantStack::~MutantStack(){}

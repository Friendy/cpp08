/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:58:00 by mrubina           #+#    #+#             */
/*   Updated: 2024/04/15 18:58:01 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

class Span::NoAddException : public std::exception
{
	virtual const char *what() const throw()
	{
		return("Maximum numbers reached");
	}
};

class Span::NoSpanException : public std::exception
{
	virtual const char *what() const throw()
	{
		return("Too few elements to find a span");
	}
};

/*CONSTRUCTORS*/
Span::Span(){}
Span::Span(u_int N) : _N(N){}

//Assignment operator:
Span &Span::operator=(Span const &original)
{
	if (this != &original)
	{
		this->_N = original._N;
		this->_nums = std::vector<int>(original._nums);
	}
	return(*this);
}

//Copy constructor:
Span::Span(Span const &original)
{
	*this = original;
}

/*FUNCTIONS*/
u_int Span::getN() const
{
	return(this->_N);
}

void Span::addNumber(int num)
{
	if (_nums.size() < _N)
		_nums.push_back(num);
	else
		throw NoAddException();
}

void Span::print()
{
	if (!_nums.empty())
	{
		for(std::vector<int>::iterator it = _nums.begin(); it < _nums.end() - 1; ++it)
		{
			std::cout << *it << ", ";
		}
		std::cout << *(_nums.end() - 1) << "\n";
	}
	else
		std::cout << "The span is empty \n";
}

void Span::batchAdd(int *nums, u_int size)
{
	int space_left = _N - _nums.size();
	if (space_left > 0)
	{
		size = std::min(size, static_cast<u_int>(space_left));
		std::vector<int>::iterator it = _nums.end();
		_nums.insert(it, nums, nums + size);
	}
}

void shortestSpan()
{

}

void longestSpan()
{

}

// const std::vector Span::getNums() const
// {
// 	return(this->_nums);
// }

// void Span::setNums(std::vector nums)
// {
// 	this->_nums = nums;
// }

/*DESTRUCTOR*/
Span::~Span(){}

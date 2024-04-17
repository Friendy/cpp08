/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:58:00 by mrubina           #+#    #+#             */
/*   Updated: 2024/04/17 15:38:31 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

typedef std::vector<int>::iterator iterator;

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
Span::Span() : _N(0){}
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
void Span::addNumber(int num)
{
	if (_nums.size() < _N)
		_nums.push_back(num);
	else
		throw NoAddException();
}

int Span::shortestSpan()
{
	if (_nums.size() <= 1)
		throw NoSpanException();
	Span tmp(*this);
	tmp.sort();
	int span_candidate = *(tmp._nums.begin() + 1) - *(tmp._nums.begin());
	for (std::vector<int>::iterator it = tmp._nums.begin() + 1; it < tmp._nums.end() - 1; ++it)
		span_candidate = std::min(span_candidate, *(it + 1) - *it);
	return(span_candidate);
}

int Span::longestSpan()
{
	if (_nums.size() <= 1)
		throw NoSpanException();
	return(*std::max_element(_nums.begin(), _nums.end()) - *std::min_element(_nums.begin(), _nums.end()));
}

void Span::randFill(u_int n, int rand_gen(void))
{
	std::vector<int> v(n);
	srand(time(NULL));
	std::generate_n(v.begin(), n, rand_gen);
	this->rangeAdd(v.begin(), v.end() - 1);
}

void Span::print() const
{
	if (!_nums.empty())
	{
		for(std::vector<int>::const_iterator it = _nums.cbegin(); it < _nums.cend() - 1; ++it)
		{
			std::cout << *it << ", ";
		}
		std::cout << *(_nums.end() - 1) << "\n";
	}
	else
		std::cout << "The span is empty \n";
}

void Span::sort()
{
	std::sort(_nums.begin(), _nums.end());
}

u_int Span::getN() const
{
	return(this->_N);
}

/*DESTRUCTOR*/
Span::~Span(){}

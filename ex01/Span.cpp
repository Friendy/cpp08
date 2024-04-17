/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:58:00 by mrubina           #+#    #+#             */
/*   Updated: 2024/04/17 13:58:34 by mrubina          ###   ########.fr       */
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


void Span::randFill(u_int n, int rand_gen(void))
{
	std::vector<int> v(n);
	srand(time(NULL));
	std::generate_n(v.begin(), n, rand_gen);
	this->rangeAdd(v.begin(), v.end() - 1);
}

int Span::shortestSpan()
{
	if (_nums.size() <= 1)
		throw NoSpanException();
	int span_candidate = -1;
	Span tmp(*this);
	tmp.sort();
	for (std::vector<int>::iterator it = tmp._nums.begin(); it < tmp._nums.end() - 1; ++it)
	{
		if (span_candidate == -1)
			span_candidate = *(it + 1) - *it;
		else
			span_candidate = std::min(span_candidate, *(it + 1) - *it);
	}
	return(span_candidate);
}

int Span::longestSpan()
{
	if (_nums.size() <= 1)
		throw NoSpanException();
	return(*std::max_element(_nums.begin(), _nums.end()) - *std::min_element(_nums.begin(), _nums.end()));
}

void Span::sort()
{
	std::sort(_nums.begin(), _nums.end());
}

/*DESTRUCTOR*/
Span::~Span(){}

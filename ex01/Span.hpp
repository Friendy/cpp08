/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:58:05 by mrubina           #+#    #+#             */
/*   Updated: 2024/04/15 22:39:39 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <string>
# include <iostream>
# include <vector>
# include <stdexcept>

// typedef std::vector<int>::iterator it

class Span {

private:
	u_int _N;
	std::vector<int> _nums;

public:
	u_int getN() const;
	void addNumber(int num);
	void batchAdd(int *nums, u_int size);
	void randFill(int rand_gen(void));
	int shortestSpan();
	int longestSpan();
	void print();
	template <typename InputIterator>
	void rangeAdd(InputIterator first, InputIterator last)
	{
		for (InputIterator it = first; it <= last; ++it)
			addNumber(*it);
	}


	class NoAddException;
	class NoSpanException;
	// const std::vector getNums() const;
	// void setNums(std::vector nums);

	Span();
	Span(u_int N);
	Span(Span const &original);
	Span &operator=(Span const &original);
	~Span();
};

#endif

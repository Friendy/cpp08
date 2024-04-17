/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:58:05 by mrubina           #+#    #+#             */
/*   Updated: 2024/04/17 15:36:05 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <string>
# include <iostream>
# include <vector>
# include <stdexcept>

class Span {

private:
	u_int _N;
	std::vector<int> _nums;

public:
	void addNumber(int num);
	int shortestSpan();
	int longestSpan();
	template <typename InputIterator>
	void rangeAdd(InputIterator first, InputIterator last)
	{
		for (InputIterator it = first; it <= last; ++it)
			addNumber(*it);
	}

	void randFill(u_int n, int rand_gen(void));
	void print() const;
	void sort();
	u_int getN() const;

	class NoAddException;
	class NoSpanException;

	Span();
	Span(u_int N);
	Span(Span const &original);
	Span &operator=(Span const &original);
	~Span();
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:52:03 by mrubina           #+#    #+#             */
/*   Updated: 2024/04/17 14:13:30 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <list>
#include <iostream>

int rand_gen()
{
	return(rand() % 1000);
}

int rand_gen_max()
{
	return(rand());
}

void test1()
{
	std::cout << "****subject test****" << "\n";
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	try
	{
		sp.addNumber(7);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}
	sp.print();
}

void test2()
{
	std::cout << "****range add test****" << "\n";
	Span sp(100);
	sp.print();
	std::vector<int>v(100, 1);
	sp.rangeAdd(v.begin(), v.end() - 1);
	sp.print();
}

void test3()
{
	std::cout << "****copy constructor test****" << "\n";
	Span sp(10);
	sp.randFill(8, rand_gen);
	Span sp_copy(sp);
	std::cout << "after copying: \n";
	sp.print();
	sp_copy.print();
	sp_copy.randFill(2, rand_gen);
	std::cout << "after modifying: \n";
	sp.print();
	sp_copy.print();
}

void test4()
{
	std::cout << "****assignment test****" << "\n";
	Span sp(10);
	sp.randFill(8, rand_gen);
	Span sp1(14);
	sp1.randFill(14, rand_gen);
	sp.print();
	sp1.print();
	sp1 = sp;
	std::cout << "after copying: \n";
	sp.print();
	sp1.print();
	std::cout << "N: "<< sp.getN() << ", " << sp1.getN() << " \n";
	sp1.randFill(2, rand_gen);
	std::cout << "after modifying: \n";
	sp.print();
	sp1.print();
}

void test5()
{
	std::cout << "****longest/shortest span test****" << "\n";
	Span sp(20);
	sp.randFill(20, rand_gen);
	std::cout << "longest span: " << sp.longestSpan() << "\n";
	std::cout << "shortest span: " << sp.shortestSpan() << "\n";
	sp.sort();
	sp.print();
}

void test6()
{
	std::cout << "****no span test****" << "\n";
	Span sp(10);
	try
	{
		std::cout << "longest span: " << sp.longestSpan() << "\n";
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}
	sp.addNumber(6);
	try
	{
		std::cout << "shortest span: " << sp.shortestSpan() << "\n";
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}
	sp.print();
}

void test7()
{
	std::cout << "****10000 test****" << "\n";
	Span sp(10000);
	sp.randFill(sp.getN(), rand_gen_max);
	// sp.sort();
	// sp.print();
	std::cout << "shortest span: " << sp.shortestSpan() << "\n";
	std::cout << "longest span: " << sp.longestSpan() << "\n";
}

void test8()
{
	std::cout << "****100000 test****" << "\n";
	Span sp(100000);
	sp.randFill(sp.getN(), rand_gen_max);
	// sp.sort();
	// sp.print();
	std::cout << "shortest span: " << sp.shortestSpan() << "\n";
	std::cout << "longest span: " << sp.longestSpan() << "\n";
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	return (0);
}

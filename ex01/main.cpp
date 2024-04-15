/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:52:03 by mrubina           #+#    #+#             */
/*   Updated: 2024/04/15 18:54:02 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <array>
#include <list>
#include <iostream>

#define S(n) sizeof(n)/sizeof(int)
// #define S sizeof(int)

void test1()
{
	std::cout << "****subject test****" << "\n";
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
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
	std::cout << "****batch add test****" << "\n";
	Span sp = Span(10);
	sp.print();
	int n[] = {1, 6, 7, 8, 9, 4};
	sp.batchAdd(n, S(n));
	sp.print();
	int k[] = {34, 62, 42, 92, 31, 56};
	sp.batchAdd(k, S(k));
	sp.print();
}

// void test3()
// {
// 	std::cout << "****list test****" << "\n";
// 	std::list<int> l;
// 	l.push_back(5);
// 	l.push_back(6);
// 	l.push_back(7);
// 	l.push_back(6);
// 	std::list<int>::iterator found = easyfind(l, 6);
// 	std::cout << "found element: " << *found  << ", index: " << std::distance(l.begin(), found) << "\n";
// }

// void test4()
// {
// 	std::cout << "****not found test****" << "\n";
// 	std::list<int> l;
// 	l.push_back(5);
// 	l.push_back(6);
// 	l.push_back(7);
// 	l.push_back(6);
// 	try
// 	{
// 		easyfind(l, 42);
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cerr << e.what() << "\n";
// 	}
// }

// void test5()
// {
// 	std::cout << "****empty container test****" << "\n";
// 	std::list<int> l;
// 	try
// 	{
// 		easyfind(l, 42);
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cerr << e.what() << "\n";
// 	}
// }

int main()
{
	test1();
	test2();
	// test3();
	// test4();
	// test5();
	return (0);
}

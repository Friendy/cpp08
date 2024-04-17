/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:52:03 by mrubina           #+#    #+#             */
/*   Updated: 2024/04/17 15:41:28 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <array>
#include <vector>
#include <list>
#include <iostream>

void test1()
{
	std::cout << "****array test****" << "\n";
	std::array <int, 10>a = {5, 7, 8, 3, 79, 3, 76};
	int *found = easyfind(a, 3);
	std::cout << "found element: " << *found << ", index: " << found - a.begin() << "\n";
}

void test2()
{
	std::cout << "****vector test****" << "\n";
	std::vector<int> v;
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(6);
	std::vector<int>::iterator found = easyfind(v, 6);
	std::cout << "found element: " << *found << ", index: " << found - v.begin() << "\n";
}

void test3()
{
	std::cout << "****list test****" << "\n";
	std::list<int> l;
	l.push_back(5);
	l.push_back(6);
	l.push_back(7);
	l.push_back(6);
	std::list<int>::iterator found = easyfind(l, 6);
	std::cout << "found element: " << *found  << ", index: " << std::distance(l.begin(), found) << "\n";
}

void test4()
{
	std::cout << "****not found test****" << "\n";
	std::list<int> l;
	l.push_back(5);
	l.push_back(6);
	l.push_back(7);
	l.push_back(6);
	try
	{
		easyfind(l, 42);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}
}

void test5()
{
	std::cout << "****empty container test****" << "\n";
	std::list<int> l;
	try
	{
		easyfind(l, 42);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	return (0);
}

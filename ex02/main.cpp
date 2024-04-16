/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:52:03 by mrubina           #+#    #+#             */
/*   Updated: 2024/04/16 21:23:36 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array>
#include <list>
#include <iostream>
#include "MutantStack.hpp"

void test1(MutantStack<int> &mstack)
{
	std::cout << "****testing iterators(subject test part2)****" << "\n";
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void test2(std::list<int> &mstack)
{
	std::cout << "****list test****" << "\n";
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void test3(MutantStack<int> &mstack)
{
	std::cout << "****testing reverse iterators****" << "\n";
	MutantStack<int>::reverse_iterator it = mstack.rbegin();
	MutantStack<int>::reverse_iterator ite = mstack.rend();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void test4(std::list<int> &mstack)
{
	std::cout << "****list test with reverse iterators****" << "\n";
	std::list<int>::reverse_iterator it = mstack.rbegin();
	std::list<int>::reverse_iterator ite = mstack.rend();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void test5(MutantStack<int> &mstack)
{
	std::cout << "****const iterator test****" << "\n";
	MutantStack<int>::iterator it = mstack.begin();
	std::cout << "first element " << *it << "\n";
	*it = 42;
	MutantStack<int>::const_iterator const_it = mstack.cbegin();
	std::cout << "first element " << *const_it << "\n";
	// *const_it = 3;
	MutantStack<int>::const_reverse_iterator cr_it = mstack.crbegin();
	std::cout << "last element " << *cr_it << "\n";
	// *cr_it = 3;
}

void test6(MutantStack<int> &mstack)
{
	std::cout << "****shortest span test****" << "\n";
}

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
	std::cout << "****creating stack(subject test part1)****" << "\n";
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	std::cout << "****creating list \"copy\" of the stack****" << "\n";
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << lst.back() << std::endl;
	lst.pop_back();
	std::cout << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	//[...]
	lst.push_back(0);

	test1(mstack);
	test2(lst);
	test3(mstack);
	test4(lst);
	test5(mstack);
	// test6();
	return (0);
}
// int f() {
//     return 1;
// }

// int main() {
//     std::vector<int> v(5);

//     // Generate values in the vector using the function f
//     std::generate_n(v.begin(), v.size(), f);

//     // Print the generated values
//     // for (const auto& value : v) {
//     //     std::cout << value << " ";
//     // }
// 	std::cout << *v.begin() << "\n";
//     std::cout << std::endl;

//     return 0;
// }

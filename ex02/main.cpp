/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:52:03 by mrubina           #+#    #+#             */
/*   Updated: 2024/04/17 12:31:40 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	*it = 5;
}


void test6(MutantStack<int> &mstack)
{
	std::cout << "****MutantStack copy constructor test****" << "\n";
	MutantStack<int> mstack_copy(mstack);
	print_stack<int>(mstack_copy);
	MutantStack<int>::iterator it = mstack_copy.begin();
	*it = 42;
	print_stack<int>(mstack_copy);
	print_stack<int>(mstack);
}

void test7(MutantStack<int> &mstack)
{
	std::cout << "****MutantStack assignment test****" << "\n";
	MutantStack<int> *mstack1 = new MutantStack<int>();
	(*mstack1).push(123);
	(*mstack1).push(464);
	(*mstack1).push(344);
	print_stack<int>(*mstack1);
	*mstack1 = mstack;
	print_stack<int>(*mstack1);
	print_stack<int>(mstack);
	MutantStack<int>::iterator it = (*mstack1).begin();
	*it = 42;
	print_stack<int>(*mstack1);
	print_stack<int>(mstack);
	delete(mstack1);
}

void test8(MutantStack<int> &mstack)
{
	std::cout << "****iterator copy constructor test****" << "\n";
	MutantStack<int>::iterator it_second = mstack.begin(); 
	++it_second;
	MutantStack<int>::iterator it_first(it_second);
	std::cout << "it_first " << *it_first << "\n";
	std::cout << "it_second " << *it_second << "\n";
	--it_first;
	std::cout << "it_first " << *it_first << "\n";
	std::cout << "it_second " << *it_second << "\n";
}

void test9(MutantStack<int> &mstack)
{
	std::cout << "****iterator assignment test****" << "\n";
	MutantStack<int> mstack1;
	mstack1.push(54);
	mstack1.push(42);
	MutantStack<int>::iterator it1 = mstack.begin(); 
	++it1;
	MutantStack<int>::iterator it2 = mstack1.begin();
	std::cout << "iterator 1 " << *it1 << "\n";
	std::cout << "iterator 2 " << *it2<< "\n";
	it2 = it1;
	std::cout << "iterator 1 " << *it1 << "\n";
	std::cout << "iterator 2 " << *it2 << "\n";
	--it2;
	std::cout << "iterator 1 " << *it1 << "\n";
	std::cout << "iterator 2 " << *it2 << "\n";
}

void test10(MutantStack<int> &mstack)
{
	std::cout << "****const reverse iterator copy constructor test****" << "\n";
	MutantStack<int>::const_reverse_iterator it_second = mstack.crbegin(); 
	++it_second;
	MutantStack<int>::const_reverse_iterator it_first(it_second);
	std::cout << "it_first " << *it_first << "\n";
	std::cout << "it_second " << *it_second << "\n";
	--it_first;
	std::cout << "it_first " << *it_first << "\n";
	std::cout << "it_second " << *it_second << "\n";
}

void test11(MutantStack<int> &mstack)
{
	std::cout << "****const reverse iterator assignment test****" << "\n";
	MutantStack<int> mstack1;
	mstack1.push(54);
	mstack1.push(42);
	MutantStack<int>::const_reverse_iterator it1 = mstack.crbegin();
	++it1;
	MutantStack<int>::const_reverse_iterator it2 = mstack1.crbegin();
	std::cout << "iterator 1 " << *it1 << "\n";
	std::cout << "iterator 2 " << *it2<< "\n";
	it2 = it1;
	std::cout << "iterator 1 " << *it1 << "\n";
	std::cout << "iterator 2 " << *it2 << "\n";
	--it2;
	std::cout << "iterator 1 " << *it1 << "\n";
	std::cout << "iterator 2 " << *it2 << "\n";
}

void test12()
{
	std::cout << "****string stack test****" << "\n";
	MutantStack<std::string> words;
	words.push("school");
	words.push("sandwich");
	words.push("clock");
	print_stack<std::string>(words);
	MutantStack<std::string>::iterator *it = new MutantStack<std::string>::iterator();
	*it = words.begin();
	std::cout << "first word: " << *(*it) << "\n";
	delete(it);
}

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
	test6(mstack);
	test7(mstack);
	test8(mstack);
	test9(mstack);
	test10(mstack);
	test11(mstack);
	test12();
	return (0);
}

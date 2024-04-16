/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:52:03 by mrubina           #+#    #+#             */
/*   Updated: 2024/04/16 14:51:02 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array>
#include <list>
#include <iostream>
#include "MutantStack.hpp"
// #include "MutantStack.tpp"

// #define S(n) sizeof(n)/sizeof(int)

// int rand_gen()
// {
// 	return(rand() % 100);
// }

// int rand_gen_max()
// {
// 	return(rand());
// }

void test1()
{
	std::cout << "****subject test****" << "\n";
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
	// std::cout << typeid(std::deque<int>.).name() << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite) {
    std::cout << *it << std::endl;
++it; }
std::stack<int> s(mstack);
}

// void test2()
// {
// 	std::cout << "****batch add test****" << "\n";
// 	Span sp = Span(10);
// 	sp.print();
// 	int n[] = {1, 6, 7, 8, 9, 4};
// 	sp.batchAdd(n, S(n));
// 	sp.print();
// 	int k[] = {34, 62, 42, 92, 31, 56};
// 	sp.batchAdd(k, S(k));
// 	sp.print();
// }

// void test3()
// {
// 	std::cout << "****range add test****" << "\n";
// 	Span sp = Span(100);
// 	sp.print();
// 	// int n[] = {1, 6, 7, 8, 9, 4, 23, 41, 2, 8};
// 	std::vector<int>v(100, 1);
// 	std::cout << *v.end() << "\n";
// 	sp.rangeAdd(v.begin(), v.end() - 1);
// 	sp.print();
// }

// void test4()
// {
// 	std::cout << "****rand fill test****" << "\n";
// 	Span sp = Span(1000);
// 	sp.randFill(rand_gen);
// 	sp.print();
// }

// void test5()
// {
// 	std::cout << "****longest span test****" << "\n";
// 	Span sp = Span(10);
// 	sp.randFill(rand_gen);
// 	sp.print();
// 	std::cout << "longest span: " << sp.longestSpan() << "\n";
// 	sp.longestSpan();
// }

// void test6()
// {
// 	std::cout << "****shortest span test****" << "\n";
// 	Span sp = Span(100000);
// 	sp.randFill(rand_gen_max);
// 	// sp.print();
// 	std::cout << "shortest span: " << sp.shortestSpan() << "\n";
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
	// test2();
	// test3();
	// test4();
	// test5();
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:19:30 by mrubina           #+#    #+#             */
/*   Updated: 2024/04/15 12:19:41 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int el)
{
	typename T::iterator found;
	found = std::find(container.begin(), container.end(), el);
	if (found == container.end())
		throw std::exception();
	return(found);
}
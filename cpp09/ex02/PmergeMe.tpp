/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 19:19:30 by zernest           #+#    #+#             */
/*   Updated: 2026/02/16 23:32:28 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename Container>
void PmergeMe::mergeInsert(Container &c)
{
	bool hasLeftover = 0;
	if (c.size() % 2 != 0)
	{
		hasLeftover = 1;
	}

	int leftover = 0;
	if (hasLeftover)
		leftover = c.back();

	std::vector<std::pair<int,int> > pairs;
	for (size_t i = 0; i < c.size(); i += 2)
	{
		if (i + 1 < c.size())
		{
			int a = c[i];
			int b = c[i + 1];
			
			if (a > b)
				std::swap(a, b);
			
			pairs.push_back(std::make_pair(a, b));
		}
	}

	//debug
	// if (hasLeftover)
	// 	std::cout << "leftover: " << leftover << std::endl;
	// for(size_t i = 0; i < pairs.size(); i++)
	// {
	// 	std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ")\n";
	// }

	Container mainChain;
	Container pending;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		pending.push_back(pairs[i].first)
		mainChain.push_back(pairs[i].second);
	}

	if (mainChain.size() > 1)
		mergeInsert(mainChain);

	
}
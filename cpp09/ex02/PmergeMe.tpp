/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 19:19:30 by zernest           #+#    #+#             */
/*   Updated: 2026/02/23 22:28:23 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename Container>
void PmergeMe::mergeInsert(Container &c)
{

	if (c.size() <= 1)
		return;

	bool hasLeftover = 0;
	if (c.size() % 2 != 0)
	{
		hasLeftover = 1;
	}

	int leftover = 0;
	if (hasLeftover)
		leftover = c.back();
	else
		(void) leftover;

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
	
	Container mainChain;
	Container pending;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		pending.push_back(pairs[i].first);
		mainChain.push_back(pairs[i].second);
	}

	mergeInsert(mainChain);

// 	std::vector<size_t> jacobIndices = jacobsThalGenerate(pending.size());
// 	std::cout << "Jacobsthal indices: ";
// for (size_t i = 0; i < jacobIndices.size(); i++)
//     std::cout << jacobIndices[i] << " ";
// std::cout << std::endl;
	std::vector<bool> inserted(pending.size(), false);

	// for (size_t i = 0; i < jacobIndices.size(); i++)
	// {
	// 	size_t idx = jacobIndices[i] - 1;
	// 	if (idx < pending.size())
	// 	{
	// 		binarySearchInsert(mainChain, pending[idx]);
	// 		inserted[idx] = true;
	// 	}
	// }

	for (size_t i = 0; i < pending.size(); i++)
	{
		if (!inserted[i])
			binarySearchInsert(mainChain, pending[i]);
	}

	if (hasLeftover)
		binarySearchInsert(mainChain, leftover);

	c = mainChain;
}

template <typename Container>
void PmergeMe::binarySearchInsert(Container &sorted, int value)
{	// (Container &sorted, int value, int &comparisonCount)
	typename Container::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);

	// size_t distance = std::distance(sorted.begin(), it);
	// if (distance > 0)
	// 	comparisonCount += static_cast<int>(ceil(log2(static_cast<double>(distance))));

	sorted.insert(it, value);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 19:19:30 by zernest           #+#    #+#             */
/*   Updated: 2026/03/02 20:47:25 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename Container>
void PmergeMe::mergeInsert(Container &c, size_t &comparisonCount)
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
			
			comparisonCount++;
			if (a > b)
				std::swap(a, b);
			
			pairs.push_back(std::make_pair(a, b));
		}
	}

	Container mainChain;
	Container pending;

	std::vector<size_t> bigPositions; // track where big elements go

	for (size_t i = 0; i < pairs.size(); i++)
	{
		pending.push_back(pairs[i].first);        // smaller element
		mainChain.push_back(pairs[i].second);     // bigger element
		bigPositions.push_back(mainChain.size() - 1); // record index
	}

	mergeInsert(mainChain, comparisonCount);

	std::vector<size_t> order = buildInsertionOrder(pending.size());

	for (size_t i = 0; i < order.size(); i++)
	{
		size_t idx = order[i] - 1;
		if (idx < pending.size())
			binarySearchInsertRestricted(mainChain, pending[idx], comparisonCount, bigPositions[idx]);
	}

	if (hasLeftover)
		binarySearchInsert(mainChain, leftover, comparisonCount);

	c = mainChain;
}

template <typename Container>
void PmergeMe::binarySearchInsert(Container &sorted, int value, size_t &comparisonCount)
{
	size_t left = 0;
	size_t right = sorted.size();

	while (left < right)
	{
		size_t mid = left + (right - left) / 2;

		comparisonCount++;  // count the comparison

		if (value < sorted[mid])
			right = mid;
		else
			left = mid + 1;
	}

	sorted.insert(sorted.begin() + left, value);
}

template <typename Container>
void PmergeMe::binarySearchInsertRestricted(Container &sorted, int value, size_t &comparisonCount, size_t maxIndex)
{
    size_t left = 0;
    size_t right = maxIndex + 1; // search only up to the bigger element

    while (left < right)
    {
        size_t mid = left + (right - left) / 2;
        comparisonCount++;  // count this comparison
        if (value < sorted[mid])
            right = mid;
        else
            left = mid + 1;
    }

    sorted.insert(sorted.begin() + left, value);
}

template <typename Container>
double	PmergeMe::run_sort(Container &c)
{
	size_t comparisonCount = 0;
	clock_t start = clock();
	mergeInsert(c, comparisonCount);
	clock_t end = clock();
	double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	return (time);
}
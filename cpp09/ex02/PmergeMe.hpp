#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <deque>
#include <climits>
#include <ctime>
#include <iomanip>

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		void validateFormat(const std::string &str);
		void checkDuplicate(int value);
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();
		void	printResult(void);
		void parseInput(char **args);
		void printContainers(void);
		template <typename Container>
		void mergeInsert(Container &c, size_t &comparisonCount);
		template <typename Container>
		void binarySearchInsert(Container &sorted, int value, size_t &comparisonCount);
		template <typename Container>
		void binarySearchInsertRestricted(Container &sorted, int value, size_t &comparisonCount, size_t maxIndex);
		template <typename Container>
		double	run_sort(Container &c);
		std::vector<size_t> jacobsThalGenerate(size_t n);
		std::vector<size_t> buildInsertionOrder(size_t n);

};

#include "PmergeMe.tpp"

#endif
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
		void parseInput(char **args);
		void printContainers(void);
		template <typename Container>
		void mergeInsert(Container &c);
		template <typename Container>
		void binarySearchInsert(Container &sorted, int value);
		std::vector<size_t> jacobsThalGenerate(size_t n);

};

#include "PmergeMe.tpp"

#endif
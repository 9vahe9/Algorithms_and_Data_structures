#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <iostream>
#include <vector>
#include <utility>

// Function prototypes
int binarySearch(const std::vector<int>& vec, int target);
int binarySearchRecursive(const std::vector<int>& vec, int target, int start, int end);

int lower_bound(const std::vector<int>& vec, int target);
int upper_bound(const std::vector<int>& vec, int target);

std::pair<int, int> equal_range(const std::vector<int>& vec, int target);

#endif // BINARY_SEARCH_H

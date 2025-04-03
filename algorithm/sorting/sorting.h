#pragma once

#include <vector>

void insertion_sort(std::vector<int>& arr);

void merge_sort(std::vector<int>& arr);
void merge_sort(std::vector<int>& arr, size_t start, size_t end);
void merge(std::vector<int>& arr, size_t start, size_t mid, size_t end);

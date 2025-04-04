#pragma once

#include <vector>

void insertion_sort(std::vector<int>& arr);

void merge_sort(std::vector<int>& arr);
void merge_sort(std::vector<int>& arr, int start, int end);
void merge(std::vector<int>& arr, int start, int mid, int end);

void quick_sort(std::vector<int>& arr);
void quick_sort(std::vector<int>& arr, int start, int end);

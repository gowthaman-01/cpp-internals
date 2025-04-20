#pragma once

#include <algorithm>
#include <cstdlib>
#include <vector>

namespace gstd::sort {

/*
 * Best Case / Average Case (pivot splits evenly)
 * - O(n log n)
 * - Pivot always divides array into two equal halves
 * - log n levels × O(n) work per level


 * Worst Case (pivot is min/max)
 * - O(n^2)
 * - One partition of size n-1, other of size 0
 * - n levels × O(n) work per level
 */
void quick_sort(std::vector<int>& arr) {
    quick_sort(arr, 0, static_cast<int>(arr.size() - 1));
}

void quick_sort(std::vector<int>& arr, int start, int end) {
    if (start >= end)
        return;

    int random_index = start + rand() % (end - start + 1);
    std::swap(arr[random_index], arr[end]);
    
    int pivot = arr[end];
    int partition_index = start;
    
    for (int i = start; i < end; i++) {
        if (arr[i] >= pivot) {
            continue;
        }
        std::swap(arr[partition_index++], arr[i]);
    }
    
    std::swap(arr[partition_index], arr[end]);
    
    quick_sort(arr, start, partition_index - 1);
    quick_sort(arr, partition_index + 1, end);
}

} // namespace gstd::sort
#include <vector>
#include "sorting.h"

void merge_sort(std::vector<int>& arr) {
    merge_sort(arr, 0, static_cast<int>(arr.size() - 1));
}

void merge_sort(std::vector<int>& arr, int start, int end) {
    if (start >= end)
        return;
    
    int mid = start + (end - start) / 2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);
    
    merge(arr, start, mid, end);
}

void merge(std::vector<int>& arr, int start, int mid, int end) {
    std::vector<int> left(arr.begin() + start, arr.begin() + mid + 1);
    std::vector<int> right(arr.begin() + mid + 1, arr.begin() + end + 1);
    
    int left_index = 0;
    int right_index = 0;
    int merge_index = start;
    
    while (left_index < left.size() && right_index < right.size()) {
        // <= to ensure stable sort
        if (left[left_index] <= right[right_index]) {
            arr[merge_index++] = left[left_index++];
        } else {
            arr[merge_index++] = right[right_index++];
        }
    }
    
    while (left_index < left.size()) {
        arr[merge_index++] = left[left_index++];
    }
    
    while (right_index < right.size()) {
        arr[merge_index++] = right[right_index++];
    }
}

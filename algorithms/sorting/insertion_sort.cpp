#include <vector>

/*
 * Best Case (nearly sorted input) : O(n)
 * Average Case                    : O(n^2)
 * Worst Case                      : O(n^2)
*/
void insertion_sort(std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        int cur = arr[i];
        int j = i;
        
        while (j > 0 && arr[j - 1] > cur) {
            arr[j] = arr[j - 1];
            j--;
        }
        
        arr[j] = cur;
    }
}
 

#pragma once

#include <algorithm>
#include <vector>

namespace gstd {

class MinHeap {
private:
    std::vector<int> heap;
    
    int get_parent(int child) const {
        return (child - 1) / 2;
    }
    
    int get_left_child(int parent) const {
        return parent * 2 + 1;
    }
    
    int get_right_child(int parent) const {
        return parent * 2 + 2;
    }
    
    bool check_bounds(int node) {
        return node >= 0 && node < get_size();
    }
    
    void heapify_up(int child) {
        while (child > 0) {
            int parent = get_parent(child);
            
            if (heap[parent] <= heap[child]) {
                return;
            }
            
            std::swap(heap[parent], heap[child]);
            child = parent;
        }
    }
    
    void heapify_down(int parent) {
        while (parent < get_size()) {
            int left_child = get_left_child(parent);
            int right_child = get_right_child(parent);
            
            // No children
            if (left_child >= get_size())
                return;
            
            int child = left_child;
            
            // If left and right child present, choose the child with the lesser value.
            if (right_child < get_size()) {
                child = heap[left_child] <= heap[right_child]
                ? left_child
                : right_child;
            }
            
            if (heap[parent] <= heap[child]) {
                return;
            }
            
            std::swap(heap[parent], heap[child]);
            parent = child;
        }
    }
    
    void heapify() {
        for (int parent = get_size() / 2 - 1; parent >= 0; --parent) {
            heapify_down(parent);
        }
    }
    
public:
    MinHeap() {}
    MinHeap(std::vector<int> arr) : heap(std::move(arr)) {
        heapify();
    }
    
    int get_size() const {
        return static_cast<int>(heap.size());
    }
    
    bool empty() const {
        return heap.empty();
    }
    
    void push(int val) {
        heap.push_back(val);
        heapify_up(get_size() - 1);
    }
    
    int top() const {
        if (heap.empty())
            throw std::out_of_range("Heap is empty");
        
        return heap.at(0);
    }
    
    int pop() {
        if (heap.empty())
            throw std::out_of_range("Heap is empty");
        
        int min_val = top();
        std::swap(heap.at(0), heap.at(get_size() - 1));
        heap.pop_back();
        
        heapify_down(0);
        
        return min_val;
    }
};

} // namespace gstd

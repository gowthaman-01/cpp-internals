#include <algorithm>

class DynamicArray {
private:
    int* arr = nullptr;
    int capacity = 0;
    int length = 0;

public:
    DynamicArray(int capacity) : arr(new int[capacity]), capacity(capacity), length(0) {}

    DynamicArray(const DynamicArray& other) 
        : arr(new int[other.capacity]), capacity(other.capacity), length(other.length){
        std::copy(other.arr, other.arr + other.length, arr);
    }

    ~DynamicArray() {
        delete[] arr;
    }   

    DynamicArray& operator=(const DynamicArray& other) {
        if (this == &other) 
            return *this;
        
        delete[] arr;
        arr = new int[other.capacity];
        capacity = other.capacity;
        length = other.length;
        std::copy(other.arr, other.arr + length, arr);
        return *this;
    }

    int get(int i) const {
        if (i < 0 || i >= length) 
            throw std::out_of_range("Index out of range");

        return arr[i];
    }

    void set(int i, int n) {
        if (i < 0 || i >= length) 
            throw std::out_of_range("Index out of range");

        arr[i] = n;
    }

    void push_back(int n) {
        if (length == capacity) {
            resize();
        }

        arr[length++] = n;
    }

    int pop_back() {
        if (length == 0) 
            throw std::underflow_error("Array is empty");

        return arr[--length];
    }

    int getSize() const {
        return length;
    }

    int getCapacity() const {
        return capacity;
    }

private:
    void resize() {
        capacity *= 2;
        int* new_arr = new int[capacity];
        std::copy(arr, arr + length, new_arr);
        delete[] arr;
        arr = new_arr;
    }
};

#include <algorithm>
#include <memory>

class DynamicArray {
private:
    std::unique_ptr<int[]> arr = nullptr;
    int capacity = 0;
    int length = 0;

public:
    DynamicArray(int capacity) : arr(new int[capacity]), capacity(capacity), length(0) {}

    DynamicArray(const DynamicArray&) = delete;
    DynamicArray& operator=(const DynamicArray&) = delete;

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
        auto new_arr = std::make_unique<int[]>(capacity);
        std::copy(arr.get(), arr.get() + length, new_arr.get());
        arr = std::move(new_arr);
    }
};

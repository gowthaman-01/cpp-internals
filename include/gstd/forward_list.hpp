#pragma once

#include <memory>
#include <vector>

namespace gstd {

class forward_list {
private:
    struct node {
        int val;
        std::unique_ptr<node> next;
    
        explicit node(int val) : val(val), next(nullptr) {}
    };

    std::unique_ptr<node> head;
    node* tail;
public:
    forward_list() : head(nullptr), tail(nullptr) {}
    
    int get(int index) const {
        node* cur = head.get();
        
        while (index-- && cur) {
            cur = cur->next.get();
        }
        
        return cur ? cur->val : -1;
    }
    
    bool empty() const {
        return head == nullptr;
    }
    
    void insert_head(int val) {
        auto new_node = std::make_unique<node>(val);
        if (!head) {
            head = std::move(new_node);
            tail = head.get();
        } else {
            new_node->next = std::move(head);
            head = std::move(new_node);
        }
    }
    
    void insert_tail(int val) {
        auto new_node = std::make_unique<node>(val);
        if (!head) {
            head = std::move(new_node);
            tail = head.get();
        } else {
            tail->next = std::move(new_node);
            tail = tail->next.get();
        }
    }
    
    bool remove(int index) {
        node* cur = head.get();
        node* prev = nullptr;
        
        while (index-- && cur) {
            prev = cur;
            cur = cur->next.get();
        }
        
        if (!cur)
            return false;
        
        if (!prev) {
            head = std::move(head->next);
            if (!head)
                tail = head.get();
            return true;
        }
        
        if (!cur->next)
            tail = prev;
        prev->next = std::move(cur->next);
        
        return true;
    }
    
    std::vector<int> get_values() const {
        node* cur = head.get();
        std::vector<int> values;
        
        while (cur) {
            values.push_back(cur->val);
            cur = cur->next.get();
        }
        
        return values;
    }
};

} // namespace gstd

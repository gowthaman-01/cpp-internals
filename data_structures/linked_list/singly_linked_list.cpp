#include <memory>
#include <vector>

class Node {
public:
    int val;
    std::unique_ptr<Node> next;

    Node()        : val(0), next(nullptr) {}
    Node(int val) : val(val), next(nullptr) {}
};

class LinkedList {
private:
    std::unique_ptr<Node> head;
    Node* tail;
public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    int get(int index) const {
        Node* cur = head.get();

        while (index-- && cur) {
            cur = cur->next.get();
        }

        return cur ? cur->val : -1;
    }
    
    bool empty() const {
        return head == nullptr;
    }

    void insert_head(int val) {
        auto new_node = std::make_unique<Node>(val);
        if (!head) {
            head = std::move(new_node);
            tail = head.get();
        } else {
            new_node->next = std::move(head);
            head = std::move(new_node);
        }
    }
    
    void insert_tail(int val) {
        auto new_node = std::make_unique<Node>(val);
        if (!head) {
            head = std::move(new_node);
            tail = head.get();
        } else {
            tail->next = std::move(new_node);
            tail = tail->next.get();
        }
    }

    bool remove(int index) {
        Node* cur = head.get();
        Node* prev = nullptr;

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
        Node* cur = head.get();
        std::vector<int> values;

        while (cur) {
            values.push_back(cur->val);
            cur = cur->next.get();
        }

        return values;
    }
};


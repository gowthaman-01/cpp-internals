#include <memory>

class Node {
public:
    int val;
    std::unique_ptr<Node> next;
    Node* prev;

    explicit Node(int val) : val(val), prev(nullptr), next(nullptr) {}
};

class Deque {
private:
    std::unique_ptr<Node> head;
    Node* tail;
public:
    Deque() : head(nullptr), tail(nullptr) {}
    
    bool isEmpty() const {
        return !head;
    }

    void append(int value) {
        auto new_node = std::make_unique<Node>(value);
        if (!head) {
            head = std::move(new_node);
            tail = head.get();
        } else {
            auto old_tail = tail;
            tail->next = std::move(new_node);
            tail = tail->next.get();
            tail->prev = old_tail;
        }
    }

    void appendleft(int value) {
        auto new_node = std::make_unique<Node>(value);
        if (!head) {
            head = std::move(new_node);
            tail = head.get();
        } else {
            auto old_head = head.get();
            new_node->next = std::move(head);
            head = std::move(new_node);
            old_head->prev = head.get();
        }
    }

    int pop() {
        if (!head)
            return -1;

        int val = tail->val;

        if (!tail->prev) {
            head.reset();
            tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next.reset();
        }

        return val;
    }

    int popleft() {
        if (!head)
            return -1;

        int val = head->val;

        if (!head->next) {
            head.reset();
            tail = nullptr;
        } else {
            head = std::move(head->next);
            head->prev = nullptr;
        }

        return val;
    }
};

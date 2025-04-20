#pragma once

#include "tree_node.hpp"

#include <stack>
#include <vector>


namespace gstd::tree {

inline std::vector<int> inorder(tree_node* root) {
    std::vector<int> result;
    std::stack<tree_node*> st;
    auto cur = root;

    while (!st.empty() || cur) {
        while (cur) {
            st.push(cur);
            cur = cur->left.get();
        }

        auto* top = st.top(); st.pop();
        result.push_back(top->val);
        cur = top->right.get();
    }

    return result;
}

inline std::vector<int> preorder(tree_node* root) {
    std::vector<int> result;
    std::stack<tree_node*> st;
    st.push(root);

    while (!st.empty()) {
        auto* top = st.top(); st.pop();
        if (!top) continue;

        result.push_back(top->val);
        if (top->right) st.push(top->right.get());
        if (top->left)  st.push(top->left.get());
    }

    return result;
}

inline std::vector<int> postorder(tree_node* root) {
    std::vector<int> result;
    std::stack<tree_node*> st;
    st.push(root);

    while (!st.empty()) {
        auto* top = st.top(); st.pop();
        if (!top) continue;

        result.push_back(top->val);
        if (top->left)  st.push(top->left.get());
        if (top->right) st.push(top->right.get());
    }

    std::reverse(result.begin(), result.end());
    return result;
}

} // namespace gstd::tree

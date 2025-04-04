#include <algorithm>
#include <stack>
#include <vector>

#include "binary_tree.h"

std::vector<int> inorder_traversal(TreeNode* root) {
    std::vector<int> inorder;
    std::stack<TreeNode*> st;

    auto cur = root;
    while (!st.empty() || cur) {
        while (cur) {
            st.push(cur);
            cur = cur->left.get();
        }
        
        auto* top = st.top();
        st.pop();

        inorder.push_back(top->val);
        cur = top->right.get();
    }

    return inorder;
}


std::vector<int> preorder_traversal(TreeNode* root) {
    std::vector<int> preorder;
    std::stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        auto* top = st.top();
        st.pop();

        if (!top)
            continue;

        preorder.push_back(top->val);
        
        if (top->right)
            st.push(top->right.get());
        if (top->left)
            st.push(top->left.get());
    }

    return preorder;
}

std::vector<int> postorder_traversal(TreeNode* root) {
    std::vector<int> postorder;
    std::stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        auto* top = st.top();
        st.pop();

        if (!top)
            continue;

        postorder.push_back(top->val);

        if (top->left)
            st.push(top->left.get());
        if (top->right)
            st.push(top->right.get());
    }

    std::reverse(postorder.begin(), postorder.end());
    return postorder;
}

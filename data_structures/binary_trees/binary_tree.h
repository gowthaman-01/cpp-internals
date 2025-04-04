#pragma once

#include <memory>

class TreeNode {
public:
    int val;
    std::unique_ptr<TreeNode> left;
    std::unique_ptr<TreeNode> right;

    TreeNode();
    TreeNode(int x);
    TreeNode(int x, std::unique_ptr<TreeNode> left, std::unique_ptr<TreeNode> right);
};


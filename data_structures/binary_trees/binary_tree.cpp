#include "binary_tree.h"

TreeNode::TreeNode() : val(0), left(nullptr), right(nullptr) {}

TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

TreeNode::TreeNode(int x, std::unique_ptr<TreeNode> left, std::unique_ptr<TreeNode> right)
    : val(x), left(std::move(left)), right(std::move(right)) {}


#pragma once

#include <memory>

namespace gstd::tree {

class tree_node {
public:
    int val;
    std::unique_ptr<tree_node> left;
    std::unique_ptr<tree_node> right;

    tree_node() : val(0), left(nullptr), right(nullptr) {}
    tree_node(int x) : val(x), left(nullptr), right(nullptr) {}
    tree_node(int x, std::unique_ptr<tree_node> l, std::unique_ptr<tree_node> r)
        : val(x), left(std::move(l)), right(std::move(r)) {}
};

} // namespace gstd::tree

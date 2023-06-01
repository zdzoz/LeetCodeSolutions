//
// Created by Oskar Zdziarski on 5/18/23.
//

#include <gtest/gtest.h>

#include <utility>
#include <vector>

class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }
    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = std::move(_neighbors);
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        Node* copy = new Node(node->val);



        return copy;
    }
};

TEST(CloneGraph, Case1) {
    Node one(1);
    Node two(2);
    Node three(3);
    Node four(4);

    one.neighbors.push_back(&two);
    one.neighbors.push_back(&four);

    two.neighbors.push_back(&one);
    two.neighbors.push_back(&three);

    three.neighbors.push_back(&two);
    three.neighbors.push_back(&four);

    four.neighbors.push_back(&one);
    four.neighbors.push_back(&three);

    Solution s;

    ASSERT_EQ(1, 2);

}

TEST(CloneGraph, Case2) {
    Node empty(1);
    Solution s;
    ASSERT_EQ(s.cloneGraph(&empty)->val, 1);
    ASSERT_EQ(s.cloneGraph(&empty)->neighbors.size(), 0);
}

TEST(CloneGraph, Case3) {
    Solution s;
    ASSERT_EQ(s.cloneGraph(nullptr), nullptr);
}
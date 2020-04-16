//
// Created by 陈桐 on 2020/4/15.
//

#ifndef LEETCODE_BINARYTREE_H
#define LEETCODE_BINARYTREE_H

#include <iostream>
#include <vector>
#include <assert.h>
#include <stack>

using namespace std;

//创建节点
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

struct Command {
    string s; // go ,print
    TreeNode *node;

    Command(string s, TreeNode *node) : s(s), node(node) {}
};

//114
class BinaryTree {

public:

    //非递归编写
    vector<int> preorderTraversal(TreeNode *root) {

        vector<int> res;
        if (root == NULL) return res;

        stack <Command> stack;
        stack.push(Command("go", root)); //根节点
        while (!stack.empty()) {
            Command command = stack.top();
            stack.pop();

            if (command.s == "print") {
                res.push_back(command.node->val);
            } else {
                assert(command.s == "go");

                if (command.node->right) {
                    stack.push(Command("go", command.node->right));
                }

                if (command.node->left) {
                    stack.push(Command("go", command.node->left));
                }

                stack.push(Command("print", command.node));

            }
        }
    }


    //前序遍历
    void preorder(TreeNode *node) {
        if (node) {
            cout << node->val;
            preorder(node->left);
            preorder(node->right);
        }
    }

    //中序遍历
    void midorder(TreeNode *node) {
        if (node) {
            midorder(node->left);
            cout << node->val;
            midorder(node->right);
        }
    }

    //后序遍历
    void aftorder(TreeNode *node) {
        if (node) {
            aftorder(node->left);
            aftorder(node->right);
            cout << node->val;
        }
    }

};


#endif //LEETCODE_BINARYTREE_H

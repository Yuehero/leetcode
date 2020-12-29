//
// Created by 郭越 on 2020/12/29.
//

#include "../util/commom.h"

#ifndef LEETCODE_TREE_H
#define LEETCODE_TREE_H

namespace leetcode {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Tree {
    public:
        //226. 翻转一棵二叉树
        TreeNode *invertTree(TreeNode *root);
        //112. 到树的叶子节点的最短路径
        bool hasPathSum(TreeNode* root, int sum);
        // 437. 路径总和 III
        int pathSum(TreeNode* root, int sum);

    };


#endif //LEETCODE_TREE_H
}
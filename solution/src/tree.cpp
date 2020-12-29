//
// Created by 郭越 on 2020/12/29.
//

#include "../inc/tree.h"

namespace leetcode {
    //226.
    TreeNode* Tree::invertTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }

    //112. 到树的叶子节点的最短路径
    bool Tree::hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return false;
        }
        int sub_val = sum - root->val;
        if (root->left == NULL && root->right ==NULL) {
            if (sub_val == 0) {
                return true;
            } else {
                return false;
            }
        } else {
            return hasPathSum(root->left, sub_val) || hasPathSum(root->right, sub_val);
        }
    }

}
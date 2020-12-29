//
// Created by 郭越 on 2020/12/29.
//

#ifndef LEETCODE_QUEUE_STACK_H
#define LEETCODE_QUEUE_STACK_H

#include "../util/commom.h"
#include <stack>
#include <queue>
namespace  leetcode {

     struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };

    class QueueStack {
    public:
        //347. topK前 K 个高频元素
        std::vector<int> topKFrequent(std::vector<int>& nums, int k);

        //102. 层序遍历
        std::vector<std::vector<int>> levelOrder(TreeNode* root);



    };

}

#endif //LEETCODE_QUEUE_STACK_H

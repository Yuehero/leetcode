//
// Created by 郭越 on 2020/12/29.
//

#include "../inc/queue_stack.h"

#include <unordered_map>
namespace leetcode {

    //347. 要求至少 O(nlog)
    std::vector<int> QueueStack::topKFrequent(std::vector<int>& nums, int k) {
        std::vector<int> result;
        if (k < nums.size() || nums.size() == 0) {
            return result;
        }
        std::unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]] ++;
        }

        assert(k <= m.size());

        //需要最小堆
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;

        for (std::unordered_map<int, int>::iterator iter = m.begin(); iter != m.end(); iter ++) {
            if (q.size() == k) {
                //寻找最小
                if (q.top().first < iter->second) {
                    q.pop();
                    q.push(std::make_pair(iter->second, iter->first));
                }

            } else {
                q.push(std::make_pair(iter->second, iter->first));
            }
        }
        while(!q.empty()) {
            result.push_back(q.top().second);
            q.pop();
        }
        return result;
    }

    //102.
    std::vector<std::vector<int>> QueueStack::levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> res;
        if (root == NULL) {
            return res;
        }
        //存放node和层id 的信息
        std::queue<std::pair<TreeNode*, int>> queue;
        queue.push(std::make_pair(root, 0));

        while(!queue.empty()) {
            TreeNode* node = queue.front().first;
            int level = queue.front().second;
            queue.pop();
            //查看有没有这一层push到res中
            if (res.size() == level) {
                res.push_back(std::vector<int>());
            }
            res[level].push_back(node->val);
            if (node->left) {
                queue.push(std::make_pair(node->left, level + 1));
            }
            if (node->right) {
                queue.push(std::make_pair(node->right, level + 1));
            }
        }
        return res;
    }


}

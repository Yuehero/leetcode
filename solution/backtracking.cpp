//
// Created by 郭越 on 2020/12/20.
//
#include "backtracking.h"

namespace leetcode {

    //46
    void BackTrack::findPermute(std::vector<int>& nums, int index, std::vector<int>& s) {
        //递归结束的条件，保存s
        if (index == nums.size()) {
            _int_res.push_back(s);
            return;
        }
        //遍历
        for (int i = 0; i < nums.size(); i ++) {
            //需要检查s中是否有nums[i]
            if (_used[i] == false) {
                s.push_back(nums[i]);
                _used[i] = true;
                findPermute(nums, index + 1, s);
                s.pop_back();
                _used[i] = false;
            }
        }
    }

    //46: 全排练问题
    std::vector<std::vector<int>> BackTrack::permute(std::vector<int> &nums) {
        //BackTrack::int_res
        _int_res.clear();
        if (nums.size() == 0) {
            return _int_res;
        }
        _used = std::vector<bool>(nums.size(), false);
        std::vector<int> s;
        findPermute(nums, 0, s);
        return _int_res;
    }

    //47: 唯一全排练问题


}//namespace leetcode

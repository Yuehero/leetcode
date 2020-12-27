//
// Created by 郭越 on 2020/12/20.
//
#include "../inc/backtracking.h"

namespace leetcode {

    //46. 全排练问题
    void BackTrack::_findPermute(std::vector<int>& nums, int index, std::vector<int>& s) {
        //递归结束的条件，保存s
        if (index == nums.size()) {
            _int_res2d.push_back(s);
            return;
        }
        //遍历
        for (int i = 0; i < nums.size(); i ++) {
            //需要检查s中是否有nums[i]
            if (_masked_1d[i] == false) {
                s.push_back(nums[i]);
                _masked_1d[i] = true;
                _findPermute(nums, index + 1, s);
                s.pop_back();
                _masked_1d[i] = false;
            }
        }
    }
    std::vector<std::vector<int>> BackTrack::permute(std::vector<int> &nums) {
        //BackTrack::int_res
        _int_res2d.clear();
        if (nums.size() == 0) {
            return _int_res2d;
        }
        _masked_1d = std::vector<bool>(nums.size(), false);
        std::vector<int> s;
        _findPermute(nums, 0, s);
        return _int_res2d;
    }

    // 字符串全排练问题
    void BackTrack::_findPermuate_string(std::string& S, int index, std::string& cur_s ) {
        //递归结束的条件
        if (index == S.size()) {
            //保存cur_s
            _str_res1d.push_back(cur_s);
            return;
        }
        for (int i = 0; i < S.size(); i++) {
            //遍历判断
            if(_masked_1d[i] == false) {
                cur_s.push_back(S[i]);
                _masked_1d[i] = true;
                _findPermuate_string(S, index + 1, cur_s);
                cur_s.pop_back();
                _masked_1d[i] = false;
            }
        }
    }

    std::vector<std::string> BackTrack::permutation_string(std::string S) {
        _str_res1d.clear();
        if (S.size() == 0) {
            return _str_res1d;
        }
        std::string cur_s;
        _masked_1d = std::vector<bool>(S.size(), false);
        _findPermuate_string(S, 0, cur_s);
        return _str_res1d;
    }

    //47: 唯一全排练问题

    //79: 单词搜索，回溯必定递归
    bool BackTrack::_findExist(std::vector<std::vector<char>>& board, int startx, int starty,
                              int index, std::string word) {
        //递归退出的条件
        if (index == word.size() - 1) {
            return (board[startx][starty] == word[index]);
        }
        if (board[startx][starty] == word[index]) {
                _masked_2d[startx][starty] = true;
                for (int i = 0; i < 4; i ++) {
                    int new_x = startx + _dims[i][0];
                    int new_y = starty + _dims[i][1];
                    if (_isArea(new_x, new_y) && _masked_2d[new_x][new_y] == false) {
                        if (_findExist(board, new_x, new_y, index + 1, word) == true) {
                            return true;
                        }
                    }
                }
                _masked_2d[startx][starty] = false;
        }
        return false;
    }

    bool BackTrack::exist(std::vector<std::vector<char>>& board, std::string word) {
         _m = board.size();
         if (_m == 0) {
             return false;
         }
         assert(_m > 0);
         _n = board[0].size(); //默认正方形
         _masked_2d = std::vector<std::vector<bool>>(_m, std::vector<bool>(_n, false));

         for (int i = 0; i < _m; i ++) {
             for (int j = 0; j < _n; j ++) {
                  if (_findExist(board, i, j, 0, word)) {
                      return true;
                  }
             }
         }
         return false;
    }


}//namespace leetcode

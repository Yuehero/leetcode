#pragma once

#include <string>
#include <vector>

namespace leetcode {


    class BackTrack {

    private:
        std::vector<std::vector<int>> _int_res2d;
        std::vector<std::string> _str_res1d;

        //用来标记
        std::vector<bool> _masked_1d;
        std::vector<std::vector<bool>> _masked_2d;

    public:
        //46. 全排练问题
        void _findPermute(std::vector<int>& nums, int index, std::vector<int>& s);
        std::vector<std::vector<int>> permute(std::vector<int>& nums);

        // 全排练字符串
        void _findPermuate_string(std::string& S, int index, std::string& cur_s);
        std::vector<std::string> permutation_string(std::string S);

        //47. 唯一全排练问题
        std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums);

        //79. 单词搜索
        int _m, _n;
        inline bool _isArea(int x, int y) {
            return (x >= 0 && x < _m && y >= 0 && y < _n);
        }
        int  _dims[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        bool _findExist(std::vector<std::vector<char>>& board, int startx, int starty,
                       int index, std::string word);
        bool exist(std::vector<std::vector<char>>& board, std::string word);






    };



} //leetcode


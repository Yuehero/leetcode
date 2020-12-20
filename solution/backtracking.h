#pragma once

#include <string>
#include <vector>

namespace leetcode {


    class BackTrack {

    private:
        std::vector<std::vector<int>> _int_res;
        std::vector<std::vector<std::string>> _str_res;

        std::vector<bool> _masked_1d;
        std::vector<std::vector<bool>> _masked_2d;

        int _m, _n;

        inline bool isArea(int x, int y) {
            return (x >= 0 && x < _m && y >= 0 && y < _n);
        }


    private:
        std::vector<bool> _used;
        void findPermute(std::vector<int>& nums, int index, std::vector<int>& s);
    public:
        //46 全排练问题
        std::vector<std::vector<int>> permute(std::vector<int>& nums);
        //47 唯一全排练问题
        std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums);






    };



} //leetcode


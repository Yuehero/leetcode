#pragma once

#include <string>
#include <vector>

namespace leetcode {


    class BackTrack {
        BackTrack();
        ~BackTrack();

    private:
        std::vector<std::vector<int>> int_res;
        std::vector<std::vector<std::string>> str_res;

        std::vector<bool> masked_1d;
        std::vector<std::vector<bool>> masked_2d;

        int m, n;

        inline bool isArea(int x, int y) {
            return (x >= 0 && x < m && y >= 0 && y < n);
        }

    public:
        //全排练问题

    };



} //leetcode


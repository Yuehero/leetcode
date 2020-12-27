//
// Created by 郭越 on 2020/12/21.
//

#ifndef LEETCODE_DP_H
#define LEETCODE_DP_H

#include <vector>
#include <string>

namespace leetcode {
    class Dp {
    public:
        //70.
        int climbStairs(int n);
        //120.
        int minimumTotal(std::vector<std::vector<int>> &triangle);
        //64.
        int minPathSum(std::vector<std::vector<int>> &grid);
        //63.
        int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid);
        //91.
        int numDecodings(std::string s);


    };

} //namesapce leetcode

#endif //LEETCODE_DP_H

//
// Created by 郭越 on 2020/12/21.
//

#include "dp.h"

namespace  leetcode {

    /*假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
      每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢*/
    int Dp::climbStairs(int n) {
        //dp 自底向上
        _dp = std::vector<int>(n + 1, -1);
        _dp[0] = 1;
        _dp[1] = 1;
        //求解dp[i]
        for (int i = 2; i <= n; i++) {
            if (_dp[i] == -1) {
                _dp[i] = _dp[i - 1] + _dp[i - 2];
            }
        }
        return _dp[n];
    }

    int Dp::minPathSum(std::vector<std::vector<int>> &grid) {

    }

    int Dp::minimumTotal(std::vector<std::vector<int>> &triangle) {

    }
    int Dp::uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid) {


    }



} //namespace leetcode

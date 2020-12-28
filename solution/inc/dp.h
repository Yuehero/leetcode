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
        //279. 完全平方数, 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。让组成和的完全平方数的个数最少
        int numSquares(int n);


    };

} //namesapce leetcode

#endif //LEETCODE_DP_H

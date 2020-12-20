//
// Created by 郭越 on 2020/11/23.
//

#ifndef PERSONALCODE_DYNAMIC_PROGAMMING_H
#define PERSONALCODE_DYNAMIC_PROGAMMING_H


#include <string>
#include <vector>

namespace leetcode {

    class DynamicProgamming {

    public:
        // 70爬楼梯问题，n阶台阶,
        int climbStairs(int n) {
            std::vector<int> memo(n + 1, -1);
            memo[0] = 1;
            memo[1] = 1;

            for (int i = 2; i <= n; i++) {
                memo[i] = memo[i - 1] + memo[i - 2];
            }
            return memo[n];
        }

        //120
        int minimumTotal(std::vector<std::vector<int>>& triangle) {
            int n = triangle.size();
            if (n == 0) {
                return 0;
            }
            std::vector<std::vector<int>> memo(n, std::vector<int>(n, -1));
            for (int i = 0; i < n; i ++) {
                memo[n - 1][i] = triangle[n -1][i];
            }

            for (int i = n - 2; i >= 0; i --) {
                for (int j = 0; j <= i; j ++) {
                    memo[i][j] = std::min(triangle[i][j] + memo[i + 1][j], triangle[i][j] + memo[i + 1][j + 1]);
                }
            }
            return memo[0][0];
        }

        //64
        int minPathSum(std::vector<std::vector<int>>& grid) {
            int m = grid.size();
            if (m == 0) {
                return 0;
            }
            int n = grid[0].size();
            // m * n 的网格
            std::vector<std::vector<int>> memo(m, std::vector<int>(n, 0));
            memo[0][0] = grid[0][0];
            for (int i = 1; i < m; i++) {
                //处理第 0 列，只能接受来自上的
                memo[i][0] = grid[i][0] + memo[i - 1][0];
            }
            for (int i = 1; i < n; i++) {
                //处理第 0 行，只能接受来自左的
                memo[0][i] = grid[0][i] + memo[0][i - 1];
            }
            for (int i = 1; i < m; i ++) {
                for (int j = 1; j < n; j ++) {
                    memo[i][j] = grid[i][j] + std::min(memo[i - 1][j], memo[i][j - 1]);
                }
            }
            return memo[m - 1][n - 1];
        }
        // 63
        int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
            int m = obstacleGrid.size();
            if (m == 0) {
                return 0;
            }
            int n = obstacleGrid[0].size();
            std::vector<std::vector<int>> memo(m, std::vector<int>(n, 0));
            if (obstacleGrid[0][0] == 0){
                memo[0][0] = 1; //start
            }
            for (int i = 1; i < m; i++) {
                 //处理第 0 列，没有障碍物且上一层是有路可走的
                 if (obstacleGrid[i][0] == 0 && memo[i - 1][0] != 0) {
                      memo[i][0] = 1;
                 }
            }
            for (int i = 1; i < n; i++) {
                //处理第 0 行，只能接受来自左的
                if (obstacleGrid[0][i] == 0 && memo[0][i - 1] != 0) {
                    memo[0][i] = 1;
                }
            }
            for (int i = 1; i < m; i ++) {
                for (int j = 1; j < n; j ++) {
                    if (obstacleGrid[i][j] == 1) {
                        memo[i][j] = 0;
                    } else {
                        memo[i][j] =  memo[i - 1][j] +  memo[i][j - 1];
                    }
                }
            }
            return memo[m - 1][n - 1];
        }


    };



}



#endif //PERSONALCODE_DYNAMIC_PROGAMMING_H

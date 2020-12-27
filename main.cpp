#include <iostream>
#include "solution/inc/dp.h"
#include "solution/inc/backtracking.h"
#include "solution/inc/arrays.h"
#include "solution/util/commom.h"


void test_bt () {
    std::cout << "==========BackTracking =======" << std::endl;
    leetcode::BackTrack s;
    {
        std::cout << "==========全排练问题=========" << std::endl;
        std::vector<int> test_vec{1, 2, 3};
        std::vector<std::vector<int>> res;
        res = s.permute(test_vec);
        Util::print2D(res);

        std::string yue = "abc";
        std::vector<std::string> res_string = s.permutation_string(yue);
        Util::print1D(res_string);
    }

    {
        std::cout << "==============二维平面的回溯问题==============" << std::endl;
        std::vector<std::vector<char>> boards = { {'A','B','C','E'},
                                                  {'S','F','C','S'},
                                                  {'A','D','E','E'}};
        Util::print2D(boards);
        std::cout << "leetcode 79 word search = " << s.exist(boards, "ABCCED") << std::endl;
    }

}

void test_dp() {

}

void test_arrays() {
    std::cout << "==========Arrays =======" << std::endl;
    leetcode::Arrays s;

    {
        std::cout << "==========Test Binary Search =======" << std::endl;
        std::vector<int> nums;
        int n = std::pow(10, 7);
        Util::genOrderedArrary(nums, n);
        clock_t st = clock();
        for (int i = 0; i < n; i++) {
            assert(i == s.binarySearch(nums, i));
        }
        clock_t ed = clock();
        std::cout << "Binary Search test complete." << std::endl;
        std::cout << "Time cost: " << double(ed - st) / CLOCKS_PER_SEC << " s" << std::endl;
    }

    {
        std::cout << "==========Test three ways quicksort =======" << std::endl;
        std::vector<int> nums{2,0,2,1,1,0};
        //s.sortColors(nums);
        //s.quickSort(nums);
        Util::print1D(nums);
    }

}

int main() {
    //test_bt();
    //test_dp();
    test_arrays();
    return 0;
}

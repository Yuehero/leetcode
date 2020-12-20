#include <iostream>
#include "solution/dp.h"
#include "solution/backtracking.h"
#include "solution/commom.h"


void test_back_tracking () {
    std::cout << "==========BackTracking =======" << std::endl;
    std::cout << "==========leetcode 46 ===========" << std::endl;
    leetcode::BackTrack s;
    std::vector<int> test_vec{1, 2, 3};
    std::vector<std::vector<int>> res;
    res = s.permute(test_vec);
    print2D(res);
}

void test_daynamic_progaming() {

}

int main() {
    test_back_tracking();
    test_daynamic_progaming();
    return 0;
}

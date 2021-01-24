//
// Created by 郭越 on 2020/12/27.
//

#include "commom.h"

namespace Util {

    template<typename T>
    void print2D(std::vector<std::vector<T>> &nums) {
        assert(nums.size() > 0);
        for (int i = 0; i < nums.size(); i++) {
            assert(nums[i].size() > 0);
            for (int j = 0; j < nums[i].size(); j++) {
                std::cout << " " << nums[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

#define OP_TEMPLATE(T) \
template void print2D<T>(std::vector<std::vector<T>> &nums);

    OP_TEMPLATE(float);

    OP_TEMPLATE(int);

    OP_TEMPLATE(std::string);

    OP_TEMPLATE(char);
#undef OP_TEMPLATE

    template<typename T>
    void print1D(std::vector<T> &nums) {
        assert(nums.size() > 0);
        for (int i = 0; i < nums.size(); i++) {
            std::cout << " " << nums[i] << " ";
        }
        std::cout << std::endl;
    }

#define OP_TEMPLATE(T) \
template void print1D<T>(std::vector<T> &nums);

    OP_TEMPLATE(float);

    OP_TEMPLATE(int);

    OP_TEMPLATE(std::string);

    OP_TEMPLATE(char);
#undef OP_TEMPLATE

    void genOrderedArrary(std::vector<int> &nums, int n) {
        assert(n > 0);
        nums.clear();
        nums.resize(n);
        for (int i = 0; i < n; i++) {
            nums[i] = i;
        }
    }

    void genRandomArrary(std::vector<int> &nums, int n, int l, int r) {
        assert(n > 0 && l <= r);
        nums.clear();
        nums.resize(n);

        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            nums[i] = rand() % (r - l + 1) + l;
        }
    }

    void genNearlyOrderedArrary(std::vector<int> &nums, int n, int swapTimes) {
        assert(n > 0);
        nums.clear();
        nums.resize(n);
        for (int i = 0; i < n; i++) {
            nums[i] = i;
        }
        srand(time(NULL));
        for (int i = 0; i < swapTimes; i++) {
            int posx = rand() % n;
            int posy = rand() % n;
            std::swap(nums[posx], nums[posy]);
        }
    }


} //namesapce Util
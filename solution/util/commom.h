//
// Created by 郭越 on 2020/12/21.
//

#ifndef LEETCODE_COMMOM_H
#define LEETCODE_COMMOM_H

#include <vector>
#include <string>
#include <iostream>
#include <assert.h>
#include<algorithm>
#include <time.h>
#include <random>
namespace Util {
    template <typename T>
    void swap(T a, T b);
    template<typename T>
    void print2D(std::vector<std::vector<T>> &nums);

    template<typename T>
    void print1D(std::vector<T> &nums);

    void genOrderedArrary(std::vector<int> &nums, int n);

    void genRandomArrary(std::vector<int> &nums, int n, int l, int r);

} //namespce Util

#endif //LEETCODE_COMMOM_H

//
// Created by 郭越 on 2020/12/21.
//

#ifndef LEETCODE_COMMOM_H
#define LEETCODE_COMMOM_H
#include <vector>
#include <iostream>
#include <assert.h>

template <typename T>
void print2D(std::vector<std::vector<T>> & nums) {
    assert(nums.size() > 0);
    for (int i = 0; i < nums.size(); i++) {
        assert(nums[i].size() > 0);
        for (int j = 0; j < nums[i].size(); j++) {
            std::cout << " " << nums[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
void print1D(std::vector<T> & nums) {
    assert(nums.size() > 0);
    for (int i = 0; i < nums.size(); i++) {
        std::cout << " " << nums[i] << " ";
    }
    std::cout << std::endl;
}

template void print2D(std::vector<std::vector<int>> & nums);
template void print2D(std::vector<std::vector<float>> & nums);
template void print1D(std::vector<int>& nums);
template void print1D(std::vector<float>& nums);


#endif //LEETCODE_COMMOM_H

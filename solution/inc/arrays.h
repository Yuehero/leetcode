//
// Created by guoyue on 2020/12/27.
//

#ifndef LEETCODE_ARRAYS_H
#define LEETCODE_ARRAYS_H

#include "../util/commom.h"
namespace  leetcode {
    class Arrays {

    public:
        //二分查找方法, 数组必须有序的
        int binarySearch(std::vector<int> &nums, int target);
        //快速排序，递归排序
        void quickSort(std::vector<int>&nums);
        void _quickSort(std::vector<int> &nums, int l, int r);
        int _partition(std::vector<int>& nums, int l, int r);
        //双路快排，避免partition 不平衡，存在大量重复元素的时候，双路快排把等于v的元素分散到2部分, <=v, >=v
        int _partition_II(std::vector<int>& nums, int l, int r);
        //三路快排, 把数组分成三部分，<v, =v, >v
        void _quickSort_III(std::vector<int>& nums, int l, int r);
        //283. 移动零，必须在原数组上操作，不能拷贝额外的数组
        void moveZeroes(std::vector<int>& nums);
        //27. 移除数组元素，空间复杂度为O(1), 元素顺序可以改变, 你必须仅使用 O(1) 额外空间并原地修改输入数组
        int removeElement(std::vector<int>& nums, int val);
        //26. 给定一个排序数组, 删除重复的数组元素，每个元素出现一次，返回新数组的长度，不要使用额外的数组空间，你必须在原地修改输入数组 并在使用 O(1) 额外空间的条件下完成
        int removeDuplicates(std::vector<int>& nums);
        //80. 给定一个增序排列数组, 你需要在原地删除重复出现的元素, 使得每个元素最多出现两次，返回移除后数组的新长度
        int removeDuplicates_II(std::vector<int>& nums) ;
        //75. 排序, 三路快排应用
        void sortColors(std::vector<int>& nums);
        //TODO: 88. 合并2个有序的数组，使nums1 成为有序的数组
        void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n);
        //215. 寻找topK, 递归快排
        int _quickSortTopK(std::vector<int>& nums, int k, int l, int r);
        int findKthLargest(std::vector<int>& nums, int k);
        ///////////////////对撞指针问题/////////////////////
        //167. 已按照升序排列的有序数组，找到两个数使得它们相加之和等于目标数, 返回数组下标
        std::vector<int> twoSum(std::vector<int>& nums, int target);
        //125. 验证回文字符串, 考虑字母和数字字符，忽略字母大小写
        bool isPalindrome(std::string s);
        //344. 反转字符串, O(1) 空间复杂度，原地修改数组
        void reverseString(std::vector<char>& s);
        //11. 盛最多水的容器, 给你 n 个非负整数 a，每个数代表坐标中的一个点 (i, ai)
        int maxArea(std::vector<int>& height);
        ///////////////////滑动窗口问题/////////////////////
        //209. 长度最小的子数组, 找出该数组中满足其和 ≥ s 的长度最小的连续子数组，并返回其长度
        int minSubArrayLen(int s, std::vector<int>& nums);
        //3. 无重复字符的最长子串，给定一个字符串，请你找出其中不含有重复字符的最长子串的长度
        int lengthOfLongestSubstring(std::string s);
        //TODO：438. 找到 s中所有是p的所有字母异位词, 字母异位词指字母相同，但排列不同的字符串, 字符串只包含小写英文字母, 返回起始索引
        std::vector<int> findAnagrams(std::string s, std::string p);


    };

} //namesapce leetcode

#endif //LEETCODE_ARRAYS_H

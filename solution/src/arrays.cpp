//
// Created by 郭越 on 2020/12/27.
//

#include "../inc/arrays.h"
#include <ctype.h>

namespace leetcode {

    int Arrays::binarySearch(std::vector<int> &nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1; // 在[l...r]的范围里寻找target
        while (l <= r) {    // 当 l == r时,区间[l...r]依然是有效的
            int mid = l + (r - l) / 2; //避免溢出，不使用 mid = (l + r) / 2, 使用如下
            if (nums[mid] == target) {
                return mid;
            }
            if (target > nums[mid]) {
                l = mid + 1;  // target在[mid+1...r]中; [l...mid]一定没有target
            } else {   // target < arr[mid]
                r = mid - 1;  // target在[l...mid-1]中; [mid...r]一定没有target
            }
        }
        return -1;
    }

    //返回索引p, 达到效果：nums[l, p - 1] < nums[p]; nums[p + 1, r] >= nums[p]
    int Arrays::_partition(std::vector<int>& nums, int l, int r) {

        int v = nums[l]; //标准
        //定义j，使得 nums[l + 1, j] < v,  num[j + 1, i] > v
        int j = l;
        for (int i = l + 1; i <= r; i++) {
            if (nums[i] < v) {
                std::swap(nums[j + 1], nums[i]);
                j ++;
            }
        }
        std::swap(nums[l], nums[j]);
        return j;
    }

    //返回索引p, 达到效果：nums[l, p - 1] <= nums[p]; nums[p + 1, r] >= nums[p]
    int Arrays::_partition_II(std::vector<int>& nums, int l, int r) {

        int v = nums[l]; //标准
        //定义j，使得 nums[l + 1, i) <= v,  num(j, r] >= v
        int i = l + 1;
        int j = r;

        while (true) {
            while (nums[i] < v && i <= r) {
                i ++;
            }
            while (nums[j] > v && j >= l + 1) {
                j --;
            }
            if (i > j) {
                break;
            }

            std::swap(nums[i], nums[j]);
            i ++;
            j --;
        }
        std::swap(nums[l], nums[j]);
        return j;
    }

    //三部分
    void Arrays::_quickSort_III(std::vector<int> &nums, int l, int r) {
        int v = nums[l];
        int lt = l + 1;
        int gt = r;
        int i = l + 1;

        //分成三部分，[l + 1, lt] < v, [lt + 1, i-1] == v, [gt, r] > v
        while(i < gt) {
            //nums[i] == v i++
            //nums[i] < v, lt + 1个元素和i swap，lt ++
            //nums[i] > v, gt -1 个元素和i swap, gt --
            if (nums[i] < v) {
                std::swap(nums[lt + 1], nums[i]);
                lt ++;
                i ++;
            } else if (nums[i] > v) {
                std::swap(nums[gt - 1], nums[i]);
                gt --;
            } else {
                i ++;
            }
        }
        std::swap(nums[l], nums[lt]);
        _quickSort_III(nums, l, lt - 1);
        _quickSort_III(nums, gt, r);
    }

    //对[l, r]部分进行快速排序
    void Arrays::_quickSort(std::vector<int> &nums, int l, int r) {
        if (l >= r) {
            return;
        }
        int p = _partition(nums, l, r);
        _quickSort(nums, l, p - 1);
        _quickSort(nums, p + 1, r);
    }
    void Arrays::quickSort(std::vector<int> &nums) {
        _quickSort(nums, 0, nums.size() - 1);
    }
    //283问题
    void Arrays::moveZeroes(std::vector<int>& nums) {
        int n = nums.size();
        assert(n > 0);
        int i = 0;
        int j = i + 1;
        while (i < n && j < n) {
            if (nums[i] == 0) {
                if (nums[j] != 0) {
                    nums[i] = nums[j];
                    nums[j] = 0;
                    i ++;
                    j = i + 1;
                } else {
                    j ++;
                }
            } else {
                i++;
                j = i+1;
            }
        }
    }
    //27
    int Arrays::removeElement(std::vector<int> &nums, int val) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int i = 0;
        int j = n - 1;
        while (i <= j) {
            if (nums[i] == val) {
                if (nums[j] != val) {
                    nums[i] = nums[j];
                    nums[j] = val;
                    i ++;
                    j --;
                } else {
                    j--;
                }
            } else {
                i ++;
            }
        }
        return i;
    }
    //26, 数组是有序的
    int Arrays::removeDuplicates(std::vector<int> &nums) {
        int n = nums.size();
        if (n == 0 || n == 1) {
            return n;
        }
        int i = 0, j = 1;

        while (j < n) {
            if (nums[i] == nums[j]) {
                j ++;
            } else {
                i ++;
                nums[i] = nums[j];
                j ++;
            }
        }
        return i + 1;
    }
    //75 三路快速排序的运用
    void Arrays::sortColors(std::vector<int>& nums) {
       int n = nums.size();
        int zero = -1;
        int two = n;
        int i = 0;
        while (i < two) {
            if (nums[i] == 1) {
                i ++;
            } else if (nums[i] == 2) {
                std::swap(nums[i], nums[--two]);
            } else {
                std::swap(nums[++zero], nums[i++]);
            }
        }
    }
    //215, 寻找topK, O(n), 如果直接排序会是O(nlogn)
    int Arrays::_quickSortTopK(std::vector<int>& nums, int index, int l , int r) {
        int p = _partition(nums, l, r);
        if (p == index) {
            return nums[p];
        }
        if (p < index) {
            return _quickSortTopK(nums, index, p + 1, r);
        } else {
            return _quickSortTopK(nums, index, l, p - 1);
        }
    }
    int Arrays::findKthLargest(std::vector<int> &nums, int k) {
        //从小到大排序，所以topK index = nums.size() - k
        return _quickSortTopK(nums, nums.size() - k, 0, nums.size() - 1);
    }
    //167, 有序升序列数组
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int n = nums.size();
        std::vector<int> result;
        if (n <= 1) {
            return result;
        }
        int i = 0, j = n - 1;
        while (i <= j) {
            if (nums[i] + nums[j] == target) {
                result.push_back(i + 1); //题目要求
                result.push_back(j + 1);
                return result;
            } else if (nums[i] + nums[j] > target) {
                j --;
            } else {
                i ++;
            }
        }
        return result;
    }

    //125, 回文字符串问题, 大小写转换 函数 islower, isupper,  toupper, tolower, #include <ctype.h>
    // isalpha 是否字母，是否数字isdigit， 是否字母和数字 isalnum
    bool Arrays::isPalindrome(std::string s) {
        int n = s.size();
        if (n == 0) {
            return true;
        }
        int i = 0;
        int j = n - 1;

        while (i <= j) {
            if (isalnum(s[i]) && isalnum(s[j])) {
                if (s[i] == s[j]) {
                    i ++;
                    j --;
                } else {
                    if (tolower(s[i]) == tolower(s[j])) {
                        i ++;
                        j --;
                    } else {
                        return false;
                    }
                }
            }
            if (!isalnum(s[i])) {
                i ++;
            }
            if (!isalnum(s[j])) {
                j --;
            }
        }
        return true;
    }

    //344
    void ArraysreverseString(std::vector<char>& s) {
        int i = 0, j = s.size() - 1;
        while (i <= j) {
            std::swap(s[i++], s[j--]);
        }
    }
    //11, 盛水最多的容器
    int Arrays::maxArea(std::vector<int> &height) {
        int maxVal = 0;
        int n = height.size();
        if (n == 0) {
            return 0;
        }
        int i = 0, j = n - 1;
        while (i <= j) {
            int w = j  - i;
            int h = std::min(height[i], height[j]);
            maxVal = std::max(h * w, maxVal);
            if (height[i] < height[j]) {
                i ++;
            } else {
                j--;
            }
        }
        return maxVal;
    }
    //209, O(n)
    int Arrays::minSubArrayLen(int s, std::vector<int> &nums) {
        int l = 0, r = -1;
        int res = nums.size() + 1;
        int sum = 0;
        while (l < nums.size()) {
            if (sum < s && r + 1 < nums.size()) {
                sum += nums[++r];
            } else {
                sum -= nums[l ++];
            }
            if (sum >= s) {
                res = std::min(res, r - l + 1); //闭区间
            }
        }
        if (res == nums.size() + 1) { //没有更新
            return 0;
        } else {
            return res;
        }
    }
    //3
    int Arrays::lengthOfLongestSubstring(std::string s) {
        int freqency[256] = {0};
        int l = 0, r = -1; //[l, r] 区间
        int maxLen = 0;
        while (l < s.size()) {
            //判断区间有重复的没有
            if (r + 1 < s.size() && freqency[s[r + 1]] == 0) {
                r ++;
                freqency[s[r]] ++;
            } else {
                freqency[s[l]] --;
                l ++;
            }
            maxLen = std::max(maxLen, r - l + 1);
        }
        return maxLen;
    }

}
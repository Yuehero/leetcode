//
// Created by 郭越 on 2021/1/24.
//

#include "../inc/sort.h"

namespace leetcode {
    //选择排序
    void ArraySort::select_sort(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int maxIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > arr[maxIdx]) {
                    maxIdx = j;
                }
            }
            std::swap(arr[i], arr[maxIdx]);
        }
    }
    //插入排序, 从大到小排序
    void ArraySort::insert_sort(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            //为arr[i] 找到合适的插入位置
            for (int j = i; j > 0 && arr[j] > arr[j - 1]; j --) {
                std::swap(arr[j], arr[j - 1]);
            }
        }
    }

    //只交换一次
    void ArraySort::insert_sort_pro(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            //为arr[i] 找到合适的插入位置
            int j;
            int e = arr[i];
            for (j = i; j > 0 && arr[j - 1] < e; j --) {
                //移动位置
                arr[j] = arr[j - 1];
            }
            arr[j] = e;
        }
    }

    //堆排序 o(nlogn)
    void ArraySort::heap_sort(std::vector<int> &arr) {
        MaxHeap<int> max_heap = MaxHeap<int>(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            max_heap.insert(arr[i]);
        }
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = max_heap.PopMax();
        }
    }


}
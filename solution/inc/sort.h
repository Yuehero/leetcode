//
// Created by yue on 2021/1/24.
//

#ifndef LEETCODE_SORT_H
#define LEETCODE_SORT_H
#include <vector>
#include <string>

namespace leetcode {

    template <typename T>
    class MaxHeap{
    private:
        T* _data;
        int _count;
        int _capacity;
        void _shiftUp(int k) {
            //k的父节点
            while (k > 1 && _data[k / 2] < _data[k]) {
                std::swap(_data[k / 2], _data[k]);
                k = k / 2;
            }
        }
        void _shiftDown(int k) {
            //k 位置的索引向下移动
            while ( 2 * k <= _count) { //表示有左孩子
                int j = 2 * k;
                if (j + 1 <= _count && _data[j + 1] > _data[j]) {
                     j = j + 1;
                }
                if (_data[k] > _data[j]) {
                    break;
                }
                std::swap(_data[k], _data[j]);
                k = j;
            }
        }
    public:
        MaxHeap(int capacity) {
            this->_capacity = capacity;
            _data = new T[capacity + 1];
            _count = 0;
        }
        MaxHeap (T* data, int n) {
            _data = new T[n];
            _count = n;
            _capacity = n + 1;
            for (int i = 0; i < n; i ++) {
                _data[i] = data[i];
            }
        }

        inline int getSize() {
            return _count;
        }

        inline bool isEmpty() {
            return _count == 0;
        }

        ~MaxHeap() {
            if (_data != NULL) {
                _data = NULL;
                delete _data;
            }
        }
        void insert(T val) {
            //索引从 1 开始
            assert(_count + 1 <= _capacity);
            _count += 1;
            _data[_count] = val;
            _shiftUp(_count);
        }
        T PopMax() {
            //索引从 1 开始
            assert(_count > 0);
            T res = _data[1];
            std::swap(_data[_count], _data[1]);
            _count --;
            _shiftDown(1);
            return res;
        }

    };

    //从大到小排序
    class ArraySort {
    public:
        //选择排序 O(n2)
        void select_sort(std::vector<int>& arr);
        //插入排序 O(n2)
        void insert_sort(std::vector<int>& arr);
        void insert_sort_pro(std::vector<int>& arr);
        //快速排序 O(nlogn)
        void quick_sort();
        //三路快排
        void quick_sort_3ways();
        //归并排序
        void merge_sort();
        //堆排序
        void heap_sort(std::vector<int>& arr);
    };
}
#endif //LEETCODE_SORT_H

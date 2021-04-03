//
//  heap_sort.cpp
//  LearnProGit
//
//  Created by 熊康 on 2021/4/3.
//

#include <stdio.h>

void adjustSingle(int *data, int i, int n)
{
    int left = 2 * i + 1;
    if (left < n) {
        int right = left + 1;
        if (right < n) {
            int maxIndex = (data[left] > data[right]) ? left : right;
            if (data[i] < data[maxIndex]) {
                swap(data[i], data[maxIndex]);
                adjustSingle(data, maxIndex, n);
            }
        } else {
            if (data[i] < data[left]) {
                swap(data[i], data[left]);
            }
        }
        
    }
}

void adjustHeap(int *data, int n)
{
    for (int i = (n - 2) / 2; i >= 0; i--) {
        adjustSingle(data, i, n);
    }
}

void heapSort(int *data, int len)
{
    for (int n = len; n > 0; n--) {
        adjustHeap(data, n);
        swap(data[0], data[n - 1]);
    }
    
}

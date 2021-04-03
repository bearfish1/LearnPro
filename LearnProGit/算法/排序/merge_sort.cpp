//
//  merge_sort.cpp
//  LearnProGit
//
//  Created by 熊康 on 2021/4/3.
//

#include <stdio.h>

void merge(int *data, int start, int mid, int end)
{
    int *tmp = new int [end - start + 1];
    int i = start;
    int j = mid + 1;
    int k = 0;
    
    while ((i <= mid) && (j <= end)) {
        if (data[i] <= data[j]) {
            tmp[k++] = data[i++];
        } else {
            tmp[k++] = data[j++];
        }
    }
    
    while (i <= mid) {
        tmp[k++] = data[i++];
    }
    
    while (j <= end) {
        tmp[k++] = data[j++];
    }
    
    for (int index = start; index <= end; index++) {
        data[index] = tmp[index - start];
    }
    
    delete [] tmp;
}

void mergeSort(int *data, int start, int end)
{
    if (start >= end) {
        return;
    }
    
    int mid = (end + start) / 2;
    mergeSort(data, start, mid);
    mergeSort(data, mid + 1, end);
    merge(data, start, mid, end);
}

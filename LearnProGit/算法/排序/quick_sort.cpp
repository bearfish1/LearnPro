//
//  quick_sort.cpp
//  LearnProGit
//
//  Created by 熊康 on 2021/4/3.
//

#include <stdio.h>

void quickSort(int *data, int start, int end)
{
    if (start >= end) {
        return;
    }

    int tmp = data[start];
    int i = start;
    int j = end;
    while (i < j) {
        while (i < j && data[j] > tmp) {
            j--;
        }
        data[i] = data[j];
        while (i < j && data[i] <= tmp) {
            i++;
        }
        data[j] = data[i];
    }
    data[i] = tmp;

    quickSort(data, start, i - 1);
    quickSort(data, i + 1, end);
}

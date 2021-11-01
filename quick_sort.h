#ifndef MAIN_C_QUICK_SORT_H
#define MAIN_C_QUICK_SORT_H

#include "swap.h"
// Sort the array using the quick sort algorithm.
void quick_sort(int *arr, int start_inx, int end_inx) {
    int left_elem = start_inx;
    int right_elem = end_inx;
    int pivot = arr[(start_inx + end_inx) / 2];       // The value of the pivot element.
    while (left_elem <= right_elem) {
        while (arr[left_elem] < pivot)
            left_elem++;
        while (arr[right_elem] > pivot)
            right_elem--;
        if (left_elem <= right_elem) {
            swap(arr, left_elem, right_elem);
            left_elem++;
            right_elem--;
        }
    }
    if (start_inx < right_elem)
        quick_sort(arr, start_inx, right_elem);
    if (left_elem < end_inx)
        quick_sort(arr, left_elem, end_inx);
}
#endif //MAIN_C_QUICK_SORT_H

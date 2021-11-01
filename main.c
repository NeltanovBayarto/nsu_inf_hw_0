#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

// Rearrange the array elements by indices.
void swap(int *arr, int fst_inx, int snd_inx) {
    int tmp = arr[fst_inx];
    arr[fst_inx] = arr[snd_inx];
    arr[snd_inx] = tmp;
}

// Enter the size of the array from the file.
void size_input(int *size, FILE *f_in) {
    if (fscanf(f_in, "%d", size) != 1) {
        fclose(f_in);
        exit(EXIT_SUCCESS);
    }
}

// Read an array from a file.
void fill_arr(int *arr, int size, FILE *f_in) {
    for (int i = 0; i < size; i++)
        fscanf(f_in, "%d", arr + i);
}

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

// Write the sorted array to a file.
void arr_output(int *arr, int size) {
    FILE *f_out = fopen("out.txt", "w");
    for (int i = 0; i < size; i++)
        fprintf(f_out, "%d ", arr[i]);
    fclose(f_out);
}

}
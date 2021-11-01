#ifndef MAIN_C_DATA_IN_OUT_H
#define MAIN_C_DATA_IN_OUT_H

#include <stdio.h>
#include <stdlib.h>

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


// Write the sorted array to a file.
void arr_output(int *arr, int size) {
    FILE *f_out = fopen("out.txt", "w");
    for (int i = 0; i < size; i++)
        fprintf(f_out, "%d ", arr[i]);
    fclose(f_out);
}

#endif //MAIN_C_DATA_IN_OUT_H

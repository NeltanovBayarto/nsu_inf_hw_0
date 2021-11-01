#include <malloc.h>
#include "quick_sort.h"
#include "data_in_out.h"


int main() {
    int size;
    FILE *f_in = fopen("in.txt", "r");
    size_input(&size, f_in);
    // Allocate memory for the array and fill it.
    int *arr = malloc(sizeof(int) * size);
    fill_arr(arr, size, f_in);
    fclose(f_in);
    quick_sort(arr, 0, size - 1);
    arr_output(arr, size);
    return 0;
}
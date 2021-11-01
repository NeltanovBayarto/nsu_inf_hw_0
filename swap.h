#ifndef MAIN_C_SWAP_H
#define MAIN_C_SWAP_H

// Rearrange the array elements by indices.
void swap(int *arr, int fst_inx, int snd_inx) {
    int tmp = arr[fst_inx];
    arr[fst_inx] = arr[snd_inx];
    arr[snd_inx] = tmp;
}
#endif //MAIN_C_SWAP_H

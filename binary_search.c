#include <stdio.h>

int binarySearch(int a[], int l, int r, int key) {
    if (l > r) return -1;
    int m = (l + r) / 2;

    if (a[m] == key) return m;
    if (a[m] > key) return binarySearch(a, l, m - 1, key);
    return binarySearch(a, m + 1, r, key);
}

int main() {
    int a[] = {1, 3, 5, 7, 9};
    int key = 7;

    int idx = binarySearch(a, 0, 4, key);
    printf("Index: %d\n", idx);
    return 0;
}

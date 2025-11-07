#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpStrings(const void *a, const void *b) {
    char *s1 = *(char **)a;
    char *s2 = *(char **)b;
    return strcmp(s1, s2);
}

int binarySearchIter(void *arr[], int n, void *target, int (*cmp)(const void *, const void *)) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        void *midItem = arr[mid];
        int res = cmp(&midItem, &target);
        if (res == 0) return mid;
        else if (res < 0) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int binarySearchRec(void *arr[], int l, int r, void *target, int (*cmp)(const void *, const void *)) {
    if (l > r) return -1;
    int mid = l + (r - l) / 2;
    void *midItem = arr[mid];
    int res = cmp(&midItem, &target);
    if (res == 0) return mid;
    else if (res < 0) return binarySearchRec(arr, mid + 1, r, target, cmp);
    else return binarySearchRec(arr, l, mid - 1, target, cmp);
}

int main() {
    char *names[] = {"DEF", "BBB", "EE", "AA", "CAB", "AAA", "DDDD", "BBB", "FFFF", "CCCC"};
    char *fav = "AA";
    int n = sizeof(names) / sizeof(names[0]);
    qsort(names, n, sizeof(char *), cmpStrings);
    printf("Sorted names: ");
    for (int i = 0; i < n; i++) printf("%s ", names[i]);
    printf("\n\n");
    int idx1 = binarySearchIter((void **)names, n, fav, cmpStrings);
    if (idx1 != -1) printf("Iterative: Found '%s' at index %d.\n", fav, idx1);
    else printf("Iterative: Did not find '%s'.\n", fav);
    int idx2 = binarySearchRec((void **)names, 0, n - 1, fav, cmpStrings);
    if (idx2 != -1) printf("Recursive: Found '%s' at index %d.\n", fav, idx2);
    else printf("Recursive: Did not find '%s'.\n", fav);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sortArray1(const void *x, const void *y) {
    return strcmp((const char *)x, (const char *)y);
}

int sortArray2(const void *x, const void *y) {
    const char *p = *(const char **)x;
    const char *q = *(const char **)y;
    return strcmp(p, q);
}

int main() {
    char manyNames[][10] = { "Jess", "Jade", "James" };
    char *moreNames[] = { "Joshua", "Jamie", "James" };

    int total1 = sizeof(manyNames) / sizeof(manyNames[0]);
    int total2 = sizeof(moreNames) / sizeof(moreNames[0]);

    qsort(manyNames, total1, sizeof(manyNames[0]), sortArray1);
    qsort(moreNames, total2, sizeof(moreNames[0]), sortArray2);

    printf("Sorted manyNames:\n");
    for (int i = 0; i < total1; i++) {
        printf("%s\n", manyNames[i]);
    }

    printf("\nSorted moreNames:\n");
    for (int i = 0; i < total2; i++) {
        printf("%s\n", moreNames[i]);
    }

    return 0;
}

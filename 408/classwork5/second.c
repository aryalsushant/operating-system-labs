#include <stdio.h>
#include <string.h>

int intCompare(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    return x - y;
}

int floatCompare(const void *a, const void *b) {
    float m = *(float *)a;
    float n = *(float *)b;
    if (m < n) return -1;
    if (m > n) return 1;
    return 0;
}

void genericBubble(void *arr, size_t len, size_t size, int (*cmp)(const void *, const void *)) {
    char *ptr = (char *)arr;
    char temp[size];
    for (size_t i = 0; i < len - 1; i++) {
        for (size_t j = 0; j < len - 1 - i; j++) {
            void *p = ptr + j * size;
            void *q = ptr + (j + 1) * size;
            if (cmp(p, q) > 0) {
                memcpy(temp, p, size);
                memcpy(p, q, size);
                memcpy(q, temp, size);
            }
        }
    }
}

int main() {
    int data[] = {50, 26, 83, 14, 92, 41};
    int n = sizeof(data) / sizeof(data[0]);

    printf("original int: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    genericBubble(data, n, sizeof(int), intCompare);

    printf("sorted int:   ");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n\n");

    float nums[] = {929.9, 112.5, 50.0, 52.75, 10.0, 75.95};
    int m = sizeof(nums) / sizeof(nums[0]);

    printf("original float: ");
    for (int i = 0; i < m; i++) {
        printf("%.2f ", nums[i]);
    }
    printf("\n");

    genericBubble(nums, m, sizeof(float), floatCompare);

    printf("sorted float:   ");
    for (int i = 0; i < m; i++) {
        printf("%.2f ", nums[i]);
    }
    printf("\n");

    return 0;
}

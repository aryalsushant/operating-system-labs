#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;


Point randomPoint() {
    Point p;
    p.x = rand() % 10 + 1;
    p.y = rand() % 10 + 1;
    return p;
}

double distanceFromOrigin(Point p) {
    return sqrt((p.x * p.x) + (p.y * p.y));
}


int linearSearch(void *arr, int n, size_t size, void *target, int (*equals)(const void *, const void *)) {
    char *ptr = (char *)arr;
    for (int i = 0; i < n; i++) {
        void *current = ptr + i * size;
        if (equals(current, target) == 0)
            return i;
    }
    return -1;
}


int pointEquals(const void *a, const void *b) {
    const Point *p1 = (const Point *)a;
    const Point *p2 = (const Point *)b;
    return (p1->x == p2->x && p1->y == p2->y) ? 0 : 1;
}


int compareDistance(const void *a, const void *b) {
    const Point *p1 = (const Point *)a;
    const Point *p2 = (const Point *)b;

    double d1 = distanceFromOrigin(*p1);
    double d2 = distanceFromOrigin(*p2);

    if (d1 > d2) return 1;
    else if (d1 < d2) return -1;
    return 0;
}


void bubbleSort(void *arr, int n, size_t size, int (*cmp)(const void *, const void *)) {
    char *base = (char *)arr;
    char *temp = malloc(size);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            void *a = base + j * size;
            void *b = base + (j + 1) * size;
            if (cmp(a, b) < 0) {
                memcpy(temp, a, size);
                memcpy(a, b, size);
                memcpy(b, temp, size);
            }
        }
    }
    free(temp);
}

int main() {
    srand(time(NULL));
    const int N = 20;
    Point points[N];

    printf("List of generated points:\n");
    for (int i = 0; i < N; i++) {
        points[i] = randomPoint();
        printf("Point %2d: (%d, %d)\n", i + 1, points[i].x, points[i].y);
    }

    Point A = randomPoint();
    printf("\nSearching for random point A: (%d, %d)\n", A.x, A.y);

    int found = linearSearch(points, N, sizeof(Point), &A, pointEquals);

    if (found != -1)
        printf("Point A found at index %d.\n", found);
    else
        printf("Point A not found.\n");

    bubbleSort(points, N, sizeof(Point), compareDistance);

    printf("\nPoints sorted by distance (descending):\n");
    for (int i = 0; i < N; i++) {
        printf("(%2d, %2d) -> %.2f\n", points[i].x, points[i].y, distanceFromOrigin(points[i]));
    }

    return 0;
}

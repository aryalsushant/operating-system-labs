#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAP 10

typedef struct {
    int usedLength;
    int totalLength;
    int elemSize;
    void *arr;
    void (*freeString)(void *position);
} stack;

void stackConstruct(stack *s, int elemSize, void (*freeString)(void *)) {
    s->usedLength = 0;
    s->elemSize = elemSize;
    s->totalLength = INITIAL_CAP;
    s->arr = malloc((size_t)elemSize * INITIAL_CAP);
    s->freeString = freeString;
}

void stackDestruct(stack *s) {
    if (s->freeString) {
        for (int i = 0; i < s->usedLength; ++i) {
            void *slot = (char *)s->arr + (size_t)i * s->elemSize;
            s->freeString(slot);
        }
    }
    free(s->arr);
}

void push(stack *s, void *element) {
    if (s->usedLength == s->totalLength) {
        s->totalLength *= 2;
        s->arr = realloc(s->arr, (size_t)s->totalLength * s->elemSize);
    }
    void *dst = (char *)s->arr + (size_t)s->usedLength * s->elemSize;
    memcpy(dst, element, (size_t)s->elemSize);
    s->usedLength++;
}

void pop(stack *s) {
    if (s->usedLength == 0) return;
    s->usedLength--;
}

void top(stack *s, void *out) {
    if (s->usedLength == 0) return;
    void *src = (char *)s->arr + (size_t)(s->usedLength - 1) * s->elemSize;
    memcpy(out, src, (size_t)s->elemSize);
}

int isEmpty(stack *s) {
    return s->usedLength == 0;
}

void freeString(void *position) {
    free(*(char **)position);
}

int main(void) {
    stack s;
    int peekVal;
    stackConstruct(&s, sizeof(int), NULL);

    for (int i = 0; i < 10; ++i) {
        int v = i + 1;
        push(&s, &v);
    }

    puts("Integers:");
    while (!isEmpty(&s)) {
        top(&s, &peekVal);
        printf("%d\n", peekVal);
        pop(&s);
    }
    stackDestruct(&s);

    stack s2;
    stackConstruct(&s2, sizeof(char *), freeString);

    char *names[] = {"John", "Jared", "Jemini", "Joseph"};
    for (int i = 0; i < 4; ++i) {
        char *dup = strdup(names[i]);
        push(&s2, &dup);
    }

    puts("\nStrings:");
    char *peekStr;
    while (!isEmpty(&s2)) {
        top(&s2, &peekStr);
        printf("%s\n", peekStr);
        pop(&s2);
    }
    stackDestruct(&s2);

    return 0;
}

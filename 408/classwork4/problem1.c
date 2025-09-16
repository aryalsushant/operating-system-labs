#include <stdio.h>
#include <string.h>

struct Book {
    char author[20];
    char title[20];
};

void read(struct Book *b) {
    printf("Enter author name: ");
    scanf("%19s", b->author);
    printf("Enter book title: ");
    scanf("%19s", b->title);
}

void print(struct Book b) {
    printf("Author: %s\n", b.author);
    printf("Title: %s\n", b.title);
}

void swap(void *a, void *b, size_t size) {
    char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

int main() {
    struct Book book1, book2;

    printf("Enter details for Book 1:\n");
    read(&book1);

    printf("\nEnter details for Book 2:\n");
    read(&book2);

    printf("\nBefore swap:\n");
    printf("Book 1:\n");
    print(book1);
    printf("Book 2:\n");
    print(book2);

    swap(&book1, &book2, sizeof(struct Book));

    printf("\nAfter swap:\n");
    printf("Book 1:\n");
    print(book1);
    printf("Book 2:\n");
    print(book2);

    return 0;
}

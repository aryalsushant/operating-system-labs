// sushant aryal
// w10166204

#include <stdio.h>

void printBinaryRec(int n) {
    if (n == 0) return;
    printBinaryRec(n / 2);
    printf("%d", n % 2);
}

void printBinary(int n) {
    if (n == 0) {
        printf("0");
        return;
    }
    printBinaryRec(n);
}

int countOnesRec(int n) {
    if (n == 0) return 0;
    return (n % 2) + countOnesRec(n / 2);
}

int countOnes(int n) {
    int count = 0;
    while (n > 0) {
        count += n % 2;
        n /= 2;
    }
    return count;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Binary (recursion): ");
    printBinary(num);
    printf("\n");

    printf("Number of ones (recursion): %d\n", countOnesRec(num));
    printf("Number of ones (loop): %d\n", countOnes(num));

    return 0;
}

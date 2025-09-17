// sushant aryal
// w10166204

#include <stdio.h>

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if ((num & 1) == 0)
        printf("Using &: %d is even\n", num);
    else
        printf("Using &: %d is odd\n", num);

    if ((num | 1) != num)
        printf("Using |: %d is even\n", num);
    else
        printf("Using |: %d is odd\n", num);

    if ((num ^ 1) == num + 1)
        printf("Using ^: %d is even\n", num);
    else
        printf("Using ^: %d is odd\n", num);

    return 0;
}

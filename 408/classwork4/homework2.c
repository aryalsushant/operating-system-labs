// sushant aryal
// w10166204

#include <stdio.h>
#include <stdint.h>

void showBits(int num) {
    uint32_t temp = (uint32_t)num;
    for (int i = 31; i >= 0; i--) {
        printf("%d", (temp >> i) & 1);
    }
    printf("\n");
}

int main() {
    int a = 1000;
    int b = -1000;

    printf("Bit pattern of %d:\n", a);
    showBits(a);

    printf("Bit pattern of %d:\n", b);
    showBits(b);

    return 0;
}

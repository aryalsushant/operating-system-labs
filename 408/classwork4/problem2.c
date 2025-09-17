#include <stdio.h>
#include <string.h>

union Packet {
    int num;
    char letter;
    float dec;
    double bigDec;
    char text[100];
};

void input(union Packet *pkt) {
    printf("Type a string for this packet: ");
    scanf("%99s", pkt->text);
}

void display(union Packet *pkt) {
    printf("Current value: %s\n", pkt->text);
}

void swapValues(void *first, void *second, size_t bytes) {
    char buffer[bytes];
    memcpy(buffer, first, bytes);
    memcpy(first, second, bytes);
    memcpy(second, buffer, bytes);
}

int main() {
    union Packet firstPacket, secondPacket;

    printf("Enter data for Packet #1:\n");
    input(&firstPacket);

    printf("Enter data for Packet #2:\n");
    input(&secondPacket);

    printf("\nBefore swapping:\n");
    display(&firstPacket);
    display(&secondPacket);

    swapValues(&firstPacket, &secondPacket, sizeof(union Packet));

    printf("\nAfter swapping:\n");
    display(&firstPacket);
    display(&secondPacket);

    printf("\nPress Enter to close...");
    getchar();
    getchar();
    return 0;
}

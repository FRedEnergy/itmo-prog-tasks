#include <stdio.h>

int main(int c, char ** args) {
    int a = 0;
    printf("Enter number:\n");
    scanf("%d", &a);
    printf("Checking if it's in range 1 - 1000: %d\n", a > 0 && a <= 1000);

    int b = 0;
    printf("Enter number:\n");
    scanf("%d", &b);
    printf("State of bit number 3: %d", (b >> 3) & 1);
    return 0;
}

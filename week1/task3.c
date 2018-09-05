
#include <stdio.h>

int main(int c, char ** args) {
    unsigned int num = 0;
    printf("Task 1\nEnter number:\n");
    scanf("%x", &num);

    printf("Task 2\nNumber in octal: %o\n", num);

    printf("Task 3\n");
    printf("Number in octal: %o\n", num);
    printf("Number in octal shifted by 3 to the left: %o\n", num << 3);

    printf("Task 4\n");
    printf("Number in octal: %o\n", num);
    printf("After binary NOT: %o\n", ~num);

    unsigned int a = 0;
    printf("Task 5\n");
    scanf("%d", &a);
    printf("Result of XOR with number %d: %d: ", num, a ^ num);
    return 0;
}

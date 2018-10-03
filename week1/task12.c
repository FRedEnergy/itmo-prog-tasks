
#include <stdio.h>

int main(int c, char** args){
    char first[50], second[50], third[50];

    printf("Enter first file:\n");
    scanf("%50s", first);
    printf("Enter second file:\n");
    scanf("%50s", second);
    printf("Enter third file:\n");
    scanf("%50s", third);

    printf("Merging %s and %s into %s\n", first, second, third);

    FILE* fsFirst = fopen(first, "r");
    FILE* fsSecond = fopen(second, "r");
    FILE* fsThird = fopen(third, "w");

    if(fsFirst == NULL || fsSecond == NULL){
        printf("Error while opening files...");
        return -1;
    }

    char ch;

    while ((ch = fgetc(fsFirst)) != EOF)
        fputc(ch, fsThird);

    while((ch = fgetc(fsSecond)) != EOF)
        fputc(ch, fsThird);

    printf("Successfully merged into %s\n", third);
    fclose(fsFirst);
    fclose(fsSecond);
    fclose(fsThird);
    return 0;
}

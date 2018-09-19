#include <stdio.h>
#include <memory.h>

int countSameChars(char *first, char *second){
    int j = 0;
    for(int i = 0; i < strlen(first); i++){
        char target = first[i];
        char *ch = strchr(second, target);
        if(ch != NULL)
            j++;
    }
    return j;
}

int main(int c, char **args){
    int n = 64;

    char first[n];
    printf("Enter first string:\n");
    scanf("%s", first);

    char second[n];
    printf("Enter second string:\n");
    scanf("%s", second);

    //comparison (3)
    printf("Comparison of two string: %d\n", strcmp(first, second));

    //copy (5)
    char third[n];
    strcpy(third, second);
    printf("Copied %s into new string, got %s\n", second, third);

    //length (7)
    printf("Length of string '%s' is %d\n", first, strlen(first));

    //find (9)
    char ch = 0;
    printf("Enter char to find in %s:\n", first);
    scanf(" %c", &ch);
    char *sr = strrchr(first, ch);
    unsigned long i = sr == NULL ? -1 : (sr - first) / sizeof(char);
    printf("First occurrence of %c in %s is at %d\n", ch, first, i);

    //find str (11)
    int count = countSameChars(first, second);
    printf("Amount of chars from %s in %s: %d", first, second, count);

    return 0;
}

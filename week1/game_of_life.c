#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
    int width, height;
    int* data;
} Board;

unsigned int endianReadInt(FILE* file) {
    unsigned char  b[4];
    if (fread(b, 1, 4, file) < 4)
        return 0;

    return (b[3] << 24) | (b[2] << 16) | (b[1] << 8) | b[0];
}

unsigned short int endianReadShort(FILE* file) {
    unsigned char  b[2];

    if (fread( b, 1, 2, file) < 2 )
        return 0;

    return (b[1] << 8) | b[0];
}

int readBMP(char* file, int* width, int* height, int* bpp, int* data){


    FILE* stream = fopen(file, "rb");
    if(stream == NULL)
        return -1;

    fseek(stream, 18, SEEK_CUR);

    *width = endianReadInt(stream);
    *height = endianReadInt(stream);

    printf("Size: %dx%d\n", width, height);

    int planes = endianReadShort(stream);
    *bpp = endianReadShort(stream);

    printf("Planes: %d, BPP: %d\n", planes, bpp);

    if(planes != 1)
        return -1;

    int size = *width * *height * (*bpp / 8);
    data = malloc(size);

    fseek(stream, 24, SEEK_CUR);

    fread(data, size, 1, stream);
    fclose(stream);
    return 0;
}

void readBoard(char* file, Board* board){

}

void writeBMP(char* file, int width, int height, int bpp, int* data){

}



int main(int count, char** args){

    char* file = "input.bmp";

    int width = 0, height = 0, bpp = 0;
    int* data = 0;

    Board* board;
    readBoard(file, &board);




    return 0;
}
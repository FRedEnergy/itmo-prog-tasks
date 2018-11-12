#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define TAG_HEADER_SIZE 10
#define FRAME_HEADER_SIZE 10
#define ACTION_PRINT_ALL 1
#define ACTION_PRINT_SPECIFIC 2
#define ACTION_CHANGE_SPECIFIC 4

typedef struct {
    char* id;
    int frameSize;
    int frameFlags;
    int isText;
    char* data;
} Frame;

typedef struct {
    Frame* frames;
    int size;
    int capacity;
} FrameArray;

FrameArray* createArray(int cap){
    FrameArray* frames = malloc(sizeof(FrameArray));
    frames->frames = malloc(sizeof(Frame) * cap);
    frames->size = 0;
    frames->capacity = cap;
    return frames;
}

void push(FrameArray* array, Frame* frame){
    if(array->size > array->capacity){
        array->capacity *= 2;
        realloc(array->frames, sizeof(Frame) * array->capacity);
    }
    array->frames[array->size++] = *frame;
}

long unpackInt(char* buf, int size){
    int result = 0;
    for(int i = 0; i < size; i++){
        result = result << 8;
        result |= (unsigned char) buf[i];
    }
    return result;
}

void packInt(char* buf, int val, int size){
    for(int i = 0; i < size; i++)
        buf[i] = (val >> ((size - 1 - i) * 8)) & 0xFF;
}

int isTextTag(char* buffer, int frameIdStart){
    return buffer[frameIdStart] == 'T' &&
           !(buffer[frameIdStart + 1] == 'X'
             && buffer[frameIdStart + 2] == 'X'
             && buffer[frameIdStart + 3] == 'X');
}

char* getTextFrameContent(Frame* frame){
    if(!frame->isText) return NULL;

    char* encoding = frame->data[0];
    char* text = malloc(frame->frameSize * sizeof(char));
    memcpy(text, frame->data + 1, frame->frameSize - 1);
    text[frame->frameSize - 1] = '\0';
    return text;
}

int startsWith(const char *pre, const char *str) {
    size_t lenpre = strlen(pre),
            lenstr = strlen(str);
    return lenstr < lenpre ? 0 : strncmp(pre, str, lenpre) == 0;
}

int main(int count, char** args){
    int action = 0;
    char* target;
    char* nextValue;
    char* filename;
    for(int i = 0; i < count; i++){
        char* arg = args[i];
        int argLen = strlen(arg);
        if(strcmp("--show", arg) == 0){
            action |= ACTION_PRINT_ALL;
        } else if(startsWith("--filepath=", arg)){
            filename = arg + 11; //size of '--filepath=
        } else if(startsWith("--get=", arg)){
            action |= ACTION_PRINT_SPECIFIC;
            target = arg + 6;
        } else if(startsWith("--set=", arg)){
            action |= ACTION_CHANGE_SPECIFIC;
            target = arg + 6;
        } else if(startsWith("--value=", arg)){
            nextValue = arg + 8;
        }
    }

    printf("Processing file %s\n", filename);

    FILE* file = fopen(filename, "rb");
    if(file == NULL){
        printf("File %s not found\n", filename);
        return 1;
    }

    if(action & ACTION_PRINT_ALL)
        printf("Printing all metadata\n");
    if(action & ACTION_PRINT_SPECIFIC)
        printf("Printing metadata about %s\n", target);
    if(action & ACTION_CHANGE_SPECIFIC)
        printf("Setting %s to %s\n", target, nextValue);

    fseek(file, 0, SEEK_END);
    long len = ftell(file);
    rewind(file);

    printf("File size is %d\n", (int)len);

    if(!(fgetc(file) == 0x49 && fgetc(file) == 0x44 && fgetc(file) == 0x33)){
        printf("Given file doesnt have and id3v2 tag\n");
        return 1;
    }

    int major = fgetc(file);
    int minor = fgetc(file);
    int flags = fgetc(file);
    char sizeBuf[4];
    for(int i = 0; i < 4; i++) sizeBuf[i] = fgetc(file);
    int tagSize = unpackInt(sizeBuf, 4);
    int useSynch = (flags & 0x80) != 0;
    int useExtHeader = (flags & 0x40) != 0;

    if(useExtHeader){
        for(int i = 0; i < 4; i++) sizeBuf[i] = fgetc(file);
        int extHeaderSize = unpackInt(sizeBuf, 4);
        fseek(file, extHeaderSize - 4, SEEK_CUR);
    }

    if(useSynch){
        //TODO: Implement synch
    }

    printf("Tag size %d\n", tagSize);
    printf("Tag version %d.%d\n", major, minor);
    printf("Use synch %d, use ext header %d\n", useSynch, useExtHeader);

    char* buf = malloc(tagSize * sizeof(char));
    fread(buf, tagSize, 1, file);
    fclose(file);

    int frameIdSize = major < 3 ? 6 : 10;
    int pos = 0;

    FrameArray* frames = createArray(10);
    while(1){
        int rem = tagSize - pos;
        if(rem < frameIdSize)
            break;

        if(buf[pos] < 'A' || buf[pos] > 'Z')
            break;

        char* id = malloc(5);
        memcpy(id, buf + pos, 4);
        id[4] = '\0';

        int frameSize = unpackInt(buf + pos + 4, 4);
        printf("Tag %s with size %d\n", id, frameSize);

        if(frameSize + pos > tagSize)
            break;

        Frame* frame = malloc(sizeof(Frame));
        frame->frameSize = frameSize;
        frame->id = id;
        frame->isText = isTextTag(id, 0);
        frame->frameFlags = unpackInt(buf + pos + 4 + 4, 2);

        frame->data = malloc(frame->frameSize * sizeof(char));
        memcpy(frame->data, buf + pos + 4 + 4 + 2, frame->frameSize);
        push(frames, frame);

        pos += frameSize + frameIdSize;
    }

    printf("Total read frames %d\n", frames->size);


    if(action & ACTION_PRINT_ALL){
        for(int i = 0; i < frames->size; i++){
            Frame frame = frames->frames[i];
            int id = i + 1;
            if(frame.isText) {
                printf("%d) %s: %s\n", id, frame.id, getTextFrameContent(&frame));
            } else {
                printf("%d) %s: (%d bytes)\n", id, frame.id, frame.frameSize);
            }
        }
    }
    if(action & ACTION_PRINT_SPECIFIC){
        for(int i = 0; i < frames->size; i++){
            Frame frame = frames->frames[i];
            if(!frame.isText || strcmp(frame.id, target) != 0)
                continue;
            printf("%s: %s\n", frame.id, getTextFrameContent(&frame));
        }
    }
    if(!(action & ACTION_CHANGE_SPECIFIC))
        return 0;

    Frame* targetFrame = NULL;
    for(int i = 0; i < frames->size; i++){
        Frame* frame = &frames->frames[i];
        if(strcmp(frame->id, target) == 0) {
            targetFrame = frame;
            break;
        }
    }
    size_t nextValueSize = (strlen(nextValue) + 1) * sizeof(char);
    int isPushed = targetFrame != NULL;
    if(!isPushed)
        targetFrame = malloc(sizeof(Frame));
    targetFrame->frameSize = 1 + nextValueSize;
    targetFrame->id = target;
    targetFrame->data = malloc(targetFrame->frameSize);
    targetFrame->data[0] = '\0'; //encoding
    memcpy(targetFrame->data + 1, nextValue, nextValueSize);
    targetFrame->isText = 1;
    targetFrame->frameFlags = 0;
    if(!isPushed) push(frames, targetFrame);

    printf("After modifications amount of frames is %d\n", frames->size);

    for(int i = 0; i < frames->size; i++){
        Frame frame = frames->frames[i];
        int id = i + 1;
        if(frame.isText) {
            printf("%d) %s: %s\n", id, frame.id, getTextFrameContent(&frame));
        } else {
            printf("%d) %s: (%d bytes)\n", id, frame.id, frame.frameSize);
        }
    }

    FILE* out = fopen("track_out.mp3", "w+");
    int fileContent = len - TAG_HEADER_SIZE - tagSize; //audio content
    printf("Audio content is %d bytes\n", fileContent);
    int nextTagSize = 0;
    for(int i = 0; i < frames->size; i++)
        nextTagSize += frames->frames[i].frameSize + FRAME_HEADER_SIZE;

    printf("Next tag size %d\n", nextTagSize);
    char* outbuf = malloc((TAG_HEADER_SIZE + nextTagSize + fileContent) * sizeof(char));
    int wpos = 0;
    outbuf[wpos++] = 0x49; outbuf[wpos++] = 0x44; outbuf[wpos++] = 0x33;
    outbuf[wpos++] = major;
    outbuf[wpos++] = minor;
    outbuf[wpos++] = flags;
    packInt(outbuf + wpos, tagSize, 4);
    wpos += 4;

    for(int i = 0; i < frames->size; i++){
        Frame frame = frames->frames[i];
        memcpy(outbuf + wpos, frame.id, 4);
        wpos += 4;
        packInt(outbuf + wpos, frame.frameSize, 4);
        wpos += 4;
        packInt(outbuf + wpos, frame.frameFlags, 2);
        wpos += 2;
        memcpy(outbuf + wpos, frame.data, frame.frameSize);
        wpos += frame.frameSize;
    }

    memcpy(outbuf + wpos, buf + TAG_HEADER_SIZE + tagSize, fileContent);

    int nextTotalSize = TAG_HEADER_SIZE + fileContent + nextTagSize;
    fwrite(outbuf, nextTotalSize, 1, out);
    fclose(out);

    printf("Successfully finished writing new file with size %d\n", nextTotalSize);
}



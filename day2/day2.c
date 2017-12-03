#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

int strip_newline(char* buffer) {
    char *c = strchr(buffer, '\n');
    if (c) {
        *c = 0;
        return 1;
    }
    return 0;
}

int day2(int argc, char** argv) {
    (void) argc;
    (void) argv;

    int rows;
    printf("How many rows should be read?\n");
    scanf("%d",&rows);
    printf("Rows is %d\n", rows);


    // init heap
    int MAX_SIZE = 200;
    char** spreadsheet = malloc(sizeof(char*)*rows);
    for (int i = 0; i < rows; i++) {
        spreadsheet[i] = malloc(sizeof(char)*MAX_SIZE);
    }

    char* b = NULL;
    size_t s;
    getline(&b, &s, stdin); // for some kind of reason we always trigger the first getline immediately, so catch it here.
    free(b);

    printf("Reading spreadsheet\n");
    for (int i = 0; i < rows; i++) {
        size_t size = MAX_SIZE;
        char* buffer = spreadsheet[i];
        getline(&buffer, &size, stdin);
        strip_newline(buffer);
    }

    printf("Read spreadsheet contains\n");
    for (int i = 0; i < rows; i++) {
        printf("%s\n", spreadsheet[i]);
        char* c = spreadsheet[i];
    }

    char tab[2] = "\t";
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        int min = 9999;
        int max = -9999;
        char* str = spreadsheet[i];
        char* token;

        token = strtok(str, tab);
        while(token != NULL) {
            int val = atoi(token);
            if (val > max) {
                max = val;
            }
            if (val < min) {
                min = val;
            }
            token = strtok(NULL, tab);
        }
        int diff = max - min;
        sum+= diff;
    }

    printf("Sum is %d\n", sum);

    // free heap
    for (int i = 0; i < rows; i++) {
        free(spreadsheet[i]);
    }
    free(spreadsheet);
    spreadsheet = NULL;
    return 0;
}

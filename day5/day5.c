#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>


void part1_d5() {

}

void part2_d5(char** received_strings, int rows) {
}

int day5(int argc, char** argv) {
    (void) argc;
    (void) argv;

    int rows;
    printf("How many rows should be read?\n");
    scanf("%d",&rows);
    printf("Rows is %d\n", rows);

    const int MAX_SIZE = 50;

    // init heap
    char** received_strings = malloc(sizeof(char*)*rows);
    for (int i = 0; i < rows; i++) {
        received_strings[i] = malloc(sizeof(char)*MAX_SIZE);
    }

    char* b = NULL;
    size_t s;
    getline(&b, &s, stdin); // for some kind of reason we always trigger the first getline immediately, so catch it here.
    free(b);

    printf("Reading received_strings\n");
    for (int i = 0; i < rows; i++) {
        size_t size = MAX_SIZE;
        char* buffer = received_strings[i];
        getline(&buffer, &size, stdin);
        strip_newline(buffer);
    }

    printf("Read received_strings contains\n");
    for (int i = 0; i < rows; i++) {
        printf("%s\n", received_strings[i]);
    }
    printf("Finished reading received_strings\n");

    printf("Part 1\n");
    part1_d5(received_strings, rows);
    printf("----\n");
    printf("Part 2\n");
    part2_d5(received_strings, rows);
    printf("----\n");

    // free heap
    for (int i = 0; i < rows; i++) {
        free(received_strings[i]);
    }
    free(received_strings);
    received_strings = NULL;
    return 0;
}

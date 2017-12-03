#include <stdio.h>
#include <string.h>
#include <inttypes.h>

int day2(int argc, char** argv) {
    (void) argc;
    (void) argv;

    char* input = "Hi\0";

    printf("Hello World\n");

    printf("%s\n", input);

    return 0;
}

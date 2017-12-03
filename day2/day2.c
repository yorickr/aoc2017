#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

int MAX_SIZE = 200;

int strip_newline(char* buffer) {
    char *c = strchr(buffer, '\n');
    if (c) {
        *c = 0;
        return 1;
    }
    return 0;
}

void part1_d2(char** spreadsheet, int rows) {
    char tab[2] = "\t";
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        int min = 9999;
        int max = -9999;
        char* str = malloc(sizeof(char) * MAX_SIZE);
        strcpy(str, spreadsheet[i]);

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
        free(str);
        str = NULL;
    }

    printf("Sum is %d\n", sum);
}

void part2_d2(char** spreadsheet, int rows) {
    char tab[2] = "\t";
    int sum = 0;

    for (int i = 0; i < rows; i++) {
        // set 1
        char* str = malloc(sizeof(char) * MAX_SIZE);
        strcpy(str, spreadsheet[i]);

        char* token;
        char* end_str;
        int cnt = 0;

        token = strtok_r(str, tab, &end_str);
        while (token != NULL) {
            int val = atoi(token);

            // loop through the rest, looking for val;
            char* end_token;
            int cnt2 = 0;

            // set 2
            char* str2 = malloc(sizeof(char) * MAX_SIZE);
            strcpy(str2, spreadsheet[i]);

            char* token2 = strtok_r(str2, tab, &end_token);
            while (token2 != NULL) {
                int val2 = atoi(token2);
                if (cnt != cnt2) {
                    if ((val % val2) == 0) {
                        // divisable!
                        sum+= (val/val2);
                    }
                }
                token2 = strtok_r(NULL, tab, &end_token);
                cnt2++;
            }

            free(str2);
            str2 = NULL;

            token = strtok_r(NULL, tab, &end_str);
            cnt++;
        }
        free(str);
        str = NULL;
    }

    printf("Sum is %d\n", sum);
}

int day2(int argc, char** argv) {
    (void) argc;
    (void) argv;

    int rows;
    printf("How many rows should be read?\n");
    scanf("%d",&rows);
    printf("Rows is %d\n", rows);


    // init heap
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
    }
    
    printf("Part 1\n");
    part1_d2(spreadsheet, rows);
    printf("----\n");
    printf("Part 2\n");
    part2_d2(spreadsheet, rows);
    printf("----\n");

    // free heap
    for (int i = 0; i < rows; i++) {
        free(spreadsheet[i]);
    }
    free(spreadsheet);
    spreadsheet = NULL;
    return 0;
}

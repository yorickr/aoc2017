#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>

void print_grid(int size, int grid[size][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

struct indexes {
    int i;
    int j;
};

struct indexes find_in_grid(int grid_size, int grid[grid_size][grid_size], int to_find) {
    struct indexes id = {-1, -1};
    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            if (grid[i][j] == to_find) {
                id.i = i;
                id.j = j;
                return id;
            }
        }
    }
    return id;
}

enum {
    RIGHT = 0,
    UP = 1,
    LEFT = 2,
    DOWN = 3,
};

int next(int dir) {
    switch(dir) {
        case RIGHT: return UP;
        case UP: return LEFT;
        case LEFT: return DOWN;
        case DOWN: return RIGHT;
    }
    return -1;
}

int day3(int argc, char** argv) {
    (void) argc;
    (void) argv;

    int to_find = 347991;

    size_t MAX = to_find;

    int grid_size = 1;
    while ((grid_size * grid_size) < MAX) {
        grid_size+=2; // so that we end up with an uneven grid.
    }

    // printf("Grid size is calculated to be %d\n", grid_size);

    int grid[grid_size][grid_size];

    // fill grid with zeros.
    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            grid[i][j] = 0;
        }
    }

    // print_grid(grid_size, grid);

    int half = grid_size / 2;
    // printf("Half is %d\n", half);
    grid[half][half] = 1;
    // print_grid(grid_size, grid);

    int posi = half;
    int posj = half;
    int dir = RIGHT;

    int times_ran = 0;
    int times_replaced = 0;
    int count = 1;

    for (int i = 0; i < grid_size*grid_size; i++) {
        grid[posi][posj] = i + 1;
        switch (dir) {
            case RIGHT:
                // check right
                posj++;
                break;
            case UP:
                posi--;
                break;
            case LEFT:
                posj--;
                break;
            case DOWN:
                posi++;
                break;
        }
        /*
        run twice
            run replace once, then switchdir
        run twice
            run replace twice, then switchdir
        run twice
            run replace thrice, then switchdir
        etc.
        */
        times_replaced++; // we've replaced one
        if (times_replaced == count) { // if we've replaced count times
            times_ran++; // we've ran once more
            times_replaced = 0; // reset replaced
            dir = next(dir); // switch dir
            if (times_ran == 2) {
                count++;
                times_ran = 0;
            }
        }


    }
    // printf("\n");
    // print_grid(grid_size, grid);

    // find value in grid.
    struct indexes id = find_in_grid(grid_size, grid, to_find);
    // printf("Found it at %d %d\n", id.i, id.j);

    // calc distance.
    printf("Distance to 1 is %d\n", (abs(half - id.i) + abs(half - id.j)));



    return 0;
}

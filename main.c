// Grayson Pike, 2016
// SDL visualization of 2d percolation using the
// path compressed weighted quick union algorithm

#include "algorithm.h"
#include "visualization.h"

int main() {

    /*
    init_objects();
    printf("Before unions:\n");
    print_objects();
    join(0, 0, 0, 1);
    printf("After unions:\n");
    print_objects();
    struct object *r1 = root(0, 0);
    struct object *r2 = root(0, 1);
    printf("(0, 0) root: (%2d, %2d)\n", r1->r, r1->c);
    printf("(0, 1) root: (%2d, %2d)\n", r2->r, r2->c);
    printf("(0, 0) connected to (0, 1): %s\n", is_connected(0, 0, 0, 1) ? "True" : "False");
    free(r1);
    free(r2);
    */

    init_sdl();
    render();
    quit_sdl();

    return 0;
}
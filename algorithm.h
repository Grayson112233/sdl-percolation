#include <stdbool.h>

// Side length of grid in squares
#define SIDE_LEN 10

struct object {
    int r;
    int c;
};

void init_objects();
struct object *root(int r, int c);
void join(int a_r, int a_c, int b_r, int b_c);
bool is_connected(int a_r, int a_c, int b_r, int b_c);
void print_objects();
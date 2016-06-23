#include <SDL2/SDL.h>
#include <stdbool.h>

// Side length of grid in squares
#define SIDE_LEN 10

// Size of a single square when rendered (in pixels)
#define SQUARE_PX 20

bool init_sdl();
void render();
void quit_sdl();
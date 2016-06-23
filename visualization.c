#include <SDL2/SDL.h>
#include "visualization.h"

SDL_Window *window;
SDL_Renderer *renderer;

void draw_square(int x, int y, int w, int h) {
    SDL_Rect dst_rect = {x, y, w, h};
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(renderer, &dst_rect);
}

// Initialize SDL (return true if successful, false otherwise)
bool init_sdl() {

    // Initialize SDL_video
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Error: Failed to init SDL2: %s\n", SDL_GetError());
        return false;
    }
    window = SDL_CreateWindow(
        "SDL2 Keypress Test",         // window title
        SDL_WINDOWPOS_UNDEFINED,      // initial x position
        SDL_WINDOWPOS_UNDEFINED,      // initial y position
        SIDE_LEN * SQUARE_PX,         // width, in pixels
        SIDE_LEN * SQUARE_PX,         // height, in pixels
        SDL_WINDOW_OPENGL             // flags - see below
    );
    if (window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        return false;
    }

    // Initialize Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL) {
        printf("Could not init renderer: %s\n", SDL_GetError());
        return false;
    }
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    return true;
}

void render() {
    SDL_RenderFillRect(renderer, NULL);
    for(int i = 0; i < SIDE_LEN; i++) {
        for(int j = 0; j < SIDE_LEN; j++) {
            if(i % 2 == 0 && j % 2 == 0) {
                draw_square(i * SQUARE_PX, j * SQUARE_PX, SQUARE_PX, SQUARE_PX);
            }
        }
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);
}

void quit_sdl() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
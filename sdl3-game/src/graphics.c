#include "graphics.h"
#include <SDL3/SDL.h>

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    int width;
    int height;
    Uint32 pixelFormat;
} GraphicsContext;

static GraphicsContext graphicsContext;

int initGraphics(const char *title, int width, int height) {
    graphicsContext.width = width;
    graphicsContext.height = height;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return -1;
    }

    graphicsContext.window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if (!graphicsContext.window) {
        SDL_Quit();
        return -1;
    }

    graphicsContext.renderer = SDL_CreateRenderer(graphicsContext.window, -1, SDL_RENDERER_ACCELERATED);
    if (!graphicsContext.renderer) {
        SDL_DestroyWindow(graphicsContext.window);
        SDL_Quit();
        return -1;
    }

    graphicsContext.pixelFormat = SDL_PIXELFORMAT_RGBA32; // Example pixel format
    return 0;
}

void closeGraphics() {
    if (graphicsContext.renderer) {
        SDL_DestroyRenderer(graphicsContext.renderer);
    }
    if (graphicsContext.window) {
        SDL_DestroyWindow(graphicsContext.window);
    }
    SDL_Quit();
}

void clearScreen() {
    SDL_SetRenderDrawColor(graphicsContext.renderer, 0, 0, 0, 255); // Clear to black
    SDL_RenderClear(graphicsContext.renderer);
}

void presentScreen() {
    SDL_RenderPresent(graphicsContext.renderer);
}

// Additional graphics functions can be added here, such as drawing shapes or loading textures.
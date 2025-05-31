#include <SDL3/SDL.h>
#include "window.h"

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    int width;
    int height;
    Uint32 pixelAddress;
    SDL_PixelFormatEnum pixelFormat;
} WindowInfo;

static WindowInfo windowInfo;

int openWindow(const char *title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return -1; // Initialization failed
    }

    windowInfo.window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (!windowInfo.window) {
        SDL_Quit();
        return -1; // Window creation failed
    }

    windowInfo.renderer = SDL_CreateRenderer(windowInfo.window, -1, SDL_RENDERER_ACCELERATED);
    if (!windowInfo.renderer) {
        SDL_DestroyWindow(windowInfo.window);
        SDL_Quit();
        return -1; // Renderer creation failed
    }

    windowInfo.width = width;
    windowInfo.height = height;
    windowInfo.pixelAddress = (Uint32)SDL_GetWindowSurface(windowInfo.window)->pixels;
    windowInfo.pixelFormat = SDL_PIXELFORMAT_RGBA32; // Example format

    return 0; // Success
}

void closeWindow() {
    if (windowInfo.renderer) {
        SDL_DestroyRenderer(windowInfo.renderer);
    }
    if (windowInfo.window) {
        SDL_DestroyWindow(windowInfo.window);
    }
    SDL_Quit();
}
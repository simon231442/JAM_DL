#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL3/SDL.h>

// Function declarations for graphics-related operations
void drawPixel(SDL_Renderer* renderer, int x, int y, SDL_Color color);
void drawLine(SDL_Renderer* renderer, int x1, int y1, int x2, int y2, SDL_Color color);
void drawRectangle(SDL_Renderer* renderer, int x, int y, int width, int height, SDL_Color color);
void clearScreen(SDL_Renderer* renderer, SDL_Color color);
void presentRenderer(SDL_Renderer* renderer);

#endif // GRAPHICS_H
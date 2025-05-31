/*                                                                             *
 *                ██████╗  █████╗ ███╗   ███╗     ██████╗ ██╗                  *
 *                ██╔════╝ ██╔══██╗████╗ ████║     ██╔══██╗██║                 *
 *                ██║  ███╗███████║██╔████╔██║     ██║  ██║██║                 *
 *                ██║   ██║██╔══██║██║╚██╔╝██║     ██║  ██║██║                 *
 *                ╚██████╔╝██║  ██║██║ ╚═╝ ██║     ██████╔╝███████╗            *
 *                 ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝     ╚═════╝ ╚══════╝            *
 *                                                                             *
 * ╭─────────────────────────────────────────────────────────────────────────╮ *
 * │  ** LEGENDARY ULTRA-MEGA AWESOME LIBRARY SDL3 C FOR RENDERS, MUSICS **  │ *
 * ├─────────────────────────────────────────────────────────────────────────┤ *
 * │  -> Nom      : GAM_DL_window.c                                          │ *
 * │  -> Auteur   : Votre Nom                                                │ *
 * │  -> Date     : 31/05/2025                                               │ *
 * ╰─────────────────────────────────────────────────────────────────────────╯ *
 */

#include "../include/GAM_DL_window.h"
#include <stdio.h>
#include <stdlib.h>

/* Crée une nouvelle fenêtre avec SDL3 */
GAM_Window* gam_create_window(const char* title, int width, int height) {
    GAM_Window* win = malloc(sizeof(GAM_Window));
    if (!win) {
        fprintf(stderr, "Erreur: Impossible d'allouer la mémoire pour GAM_Window\n");
        return NULL;
    }
    
    // Initialiser SDL
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "Erreur SDL_Init: %s\n", SDL_GetError());
        free(win);
        return NULL;
    }
    
    // Créer la fenêtre
    win->window = SDL_CreateWindow(title, width, height, SDL_WINDOW_RESIZABLE);
    if (!win->window) {
        fprintf(stderr, "Erreur SDL_CreateWindow: %s\n", SDL_GetError());
        SDL_Quit();
        free(win);
        return NULL;
    }
    
    // Créer le renderer
    win->renderer = SDL_CreateRenderer(win->window, NULL);
    if (!win->renderer) {
        fprintf(stderr, "Erreur SDL_CreateRenderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(win->window);
        SDL_Quit();
        free(win);
        return NULL;
    }
    
    // Créer une texture pour manipuler les pixels
    win->texture = SDL_CreateTexture(win->renderer, SDL_PIXELFORMAT_RGBA8888,
                                     SDL_TEXTUREACCESS_STREAMING, width, height);
    if (!win->texture) {
        fprintf(stderr, "Erreur SDL_CreateTexture: %s\n", SDL_GetError());
        SDL_DestroyRenderer(win->renderer);
        SDL_DestroyWindow(win->window);
        SDL_Quit();
        free(win);
        return NULL;
    }
    
    // Initialiser les propriétés
    win->width = width;
    win->height = height;
    win->title = title;
    win->is_running = true;
    win->pixels = NULL;
    win->pitch = 0;
    win->format = SDL_PIXELFORMAT_RGBA8888;
    
    printf("✅ Fenêtre créée: %s (%dx%d)\n", title, width, height);
    return win;
}

/* Détruit la fenêtre et libère les ressources */
void gam_destroy_window(GAM_Window* win) {
    if (!win) return;
    
    if (win->texture) SDL_DestroyTexture(win->texture);
    if (win->renderer) SDL_DestroyRenderer(win->renderer);
    if (win->window) SDL_DestroyWindow(win->window);
    
    SDL_Quit();
    free(win);
    printf("🗑️  Fenêtre détruite proprement\n");
}

/* Met à jour l'affichage de la fenêtre */
void gam_update_window(GAM_Window* win) {
    if (!win) return;
    
    SDL_RenderPresent(win->renderer);
}

/* Verrouille la texture pour accéder aux pixels */
int gam_lock_texture(GAM_Window* win) {
    if (!win || !win->texture) return -1;
    
    if (SDL_LockTexture(win->texture, NULL, &win->pixels, &win->pitch) != 0) {
        fprintf(stderr, "Erreur SDL_LockTexture: %s\n", SDL_GetError());
        return -1;
    }
    return 0;
}

/* Déverrouille la texture */
void gam_unlock_texture(GAM_Window* win) {
    if (!win || !win->texture) return;
    
    SDL_UnlockTexture(win->texture);
    win->pixels = NULL;
    win->pitch = 0;
}

/* Efface l'écran avec une couleur */
void gam_clear_screen(GAM_Window* win, Uint32 color) {
    if (!win) return;
    
    Uint8 r = (color >> 24) & 0xFF;
    Uint8 g = (color >> 16) & 0xFF;
    Uint8 b = (color >> 8) & 0xFF;
    Uint8 a = color & 0xFF;
    
    SDL_SetRenderDrawColor(win->renderer, r, g, b, a);
    SDL_RenderClear(win->renderer);
}

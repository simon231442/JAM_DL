
#ifndef GAM_DL_WINDOW_H
#define GAM_DL_WINDOW_H

#include <SDL3/SDL.h>
#include <stdbool.h>

/* Structure principale pour la gestion de la fenêtre */
typedef struct {
    SDL_Window* window;         // Pointeur vers la fenêtre SDL
    SDL_Renderer* renderer;     // Rendu SDL
    SDL_Texture* texture;       // Texture pour manipuler les pixels
    
    // Informations sur l'image/pixels
    void* pixels;               // Adresse des pixels
    int width;                  // Largeur de la fenêtre
    int height;                 // Hauteur de la fenêtre
    int pitch;                  // Nombre d'octets par ligne
    Uint32 format;              // Format des pixels (endianness)
    
    // État de la fenêtre
    bool is_running;            // État d'exécution
    const char* title;          // Titre de la fenêtre
} GAM_Window;

/* Prototypes des fonctions */
GAM_Window* gam_create_window(const char* title, int width, int height);
void gam_destroy_window(GAM_Window* win);
void gam_update_window(GAM_Window* win);
int gam_lock_texture(GAM_Window* win);
void gam_unlock_texture(GAM_Window* win);
void gam_clear_screen(GAM_Window* win, Uint32 color);

#endif /* GAM_DL_WINDOW_H */

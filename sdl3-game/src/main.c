#include "../include/GAM_DL_window.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
    (void)argc;  // Éviter le warning unused
    (void)argv;
    
    printf("🚀 Démarrage du moteur GAM_DL avec SDL3\n");
    
    // Créer une fenêtre
    GAM_Window* window = gam_create_window("GAM_DL - Test SDL3", 800, 600);
    if (!window) {
        fprintf(stderr, "❌ Impossible de créer la fenêtre\n");
        return 1;
    }
    
    printf("🎮 Fenêtre créée! Appuyez sur ECHAP pour quitter.\n");
    
    // Boucle principale du jeu
    SDL_Event event;
    while (window->is_running) {
        // Gestion des événements
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT:
                    window->is_running = false;
                    break;
                case SDL_EVENT_KEY_DOWN:
                    if (event.key.key == SDLK_ESCAPE) {
                        window->is_running = false;
                    }
                    break;
            }
        }
        
        // Effacer l'écran (noir)
        gam_clear_screen(window, 0x000000FF);
        
        // Dessiner quelque chose de simple (carré rouge au centre)
        SDL_FRect rect = {350, 250, 100, 100};
        SDL_SetRenderDrawColor(window->renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(window->renderer, &rect);
        
        // Mettre à jour l'affichage
        gam_update_window(window);
        
        // Petite pause pour éviter 100% CPU
        SDL_Delay(16);  // ~60 FPS
    }
    
    // Nettoyer et quitter
    gam_destroy_window(window);
    printf("👋 Au revoir!\n");
    
    return 0;
}
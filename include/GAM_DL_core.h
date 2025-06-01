/*                                                                             *
 *                 ██████╗  █████╗ ███╗   ███╗     ██████╗ ██╗                 *
 *                ██╔════╝ ██╔══██╗████╗ ████║     ██╔══██╗██║                 *
 *                ██║  ███╗███████║██╔████╔██║     ██║  ██║██║                 *
 *                ██║   ██║██╔══██║██║╚██╔╝██║     ██║  ██║██║                 *
 *                ╚██████╔╝██║  ██║██║ ╚═╝ ██║     ██████╔╝███████╗            *
 *                 ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝     ╚═════╝ ╚══════╝            *
 *                                                                             *
 * ╭─────────────────────────────────────────────────────────────────────────╮ *
 * │  ** LEGENDARY ULTRA-MEGA AWESOME LIBRARY SDL3 C FOR RENDERS, MUSICS **  │ *
 * ├─────────────────────────────────────────────────────────────────────────┤ *
 * │  -> Nom      : GAM_DL_core.h                                            │ *
 * │  -> Auteur   : tricaducee SpartaCod lolilol                             │ *
 * │  -> Date     : 01/06/2025                                               │ *
 * ╰─────────────────────────────────────────────────────────────────────────╯ *
 */

#ifndef GAM_DL_CORE_H
#define GAM_DL_CORE_H

#include <SDL3/SDL.h>
#include <stdbool.h>
#include <stdlib.h>

// ═══════════════════════════════════════════════════════════════════════════
// CONSTANTES ET DÉFINITIONS
// ═══════════════════════════════════════════════════════════════════════════

#define GAM_DL_DEFAULT_WIDTH 800
#define GAM_DL_DEFAULT_HEIGHT 600

// ═══════════════════════════════════════════════════════════════════════════
// STRUCTURES PRINCIPALES
// ═══════════════════════════════════════════════════════════════════════════

typedef struct
{
    SDL_Window *window;     // Fenêtre SDL
    SDL_Renderer *renderer; // Renderer SDL
    SDL_Texture *texture;   // Texture pour manipulation pixels

    // Informations sur l'image/pixels
    void *pixels; // Adresse des pixels
    int width;    // Largeur de la fenêtre
    int height;   // Hauteur de la fenêtre
    int pitch;    // Largeur d'une ligne en octets

    // État
    bool is_running;   // État d'exécution
    const char *title; // Titre de la fenêtre
} GAM_Window;

// ═══════════════════════════════════════════════════════════════════════════
// VOS FONCTIONS EXISTANTES
// ═══════════════════════════════════════════════════════════════════════════

// Fonctions que vous avez déjà implémentées
GAM_Window *GAM_DL_CoreWindowPop(int width, int height);
void GAM_DL_GAM_DL_CoreExit(GAM_Window *gam_window);
int GAM_DL_CoreMainWindowShow(void);

#endif // GAM_DL_CORE_H
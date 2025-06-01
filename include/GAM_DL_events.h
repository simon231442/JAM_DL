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
 * │  -> Nom      : GAM_DL_events.h                                          │ *
 * │  -> Auteur   : tricaducee SpartaCod lolilol                             │ *
 * │  -> Date     : 01/06/2025                                               │ *
 * ╰─────────────────────────────────────────────────────────────────────────╯ *
 */

#ifndef GAM_DL_EVENTS_H
#define GAM_DL_EVENTS_H

#include "GAM_DL_core.h"

// ═══════════════════════════════════════════════════════════════════════════
// TYPES ET STRUCTURES POUR LES ÉVÉNEMENTS
// ═══════════════════════════════════════════════════════════════════════════

// Type de fonction pour gérer les événements
typedef void (*GAM_EventHandler)(SDL_Event *event, GAM_Window *window);

// Structure pour mapper les événements
typedef struct
{
    Uint32 event_type;
    GAM_EventHandler handler;
} GAM_EventMapping;

// États des touches et souris
typedef struct
{
    bool keys[SDL_NUM_SCANCODES];     // État de toutes les touches
    bool mouse_buttons[8];            // État des boutons souris
    int mouse_x, mouse_y;             // Position souris
    int mouse_wheel_x, mouse_wheel_y; // Molette souris
} GAM_InputState;

// ═══════════════════════════════════════════════════════════════════════════
// VOS FONCTIONS EXISTANTES
// ═══════════════════════════════════════════════════════════════════════════

// Fonction que vous avez déjà implémentée
int GAM_DL_EventHandle(SDL_Event *event);

// ═══════════════════════════════════════════════════════════════════════════
// CONSTANTES UTILES
// ═══════════════════════════════════════════════════════════════════════════

// Aliases pour les touches courantes
#define GAM_KEY_ESC SDL_SCANCODE_ESCAPE
#define GAM_KEY_SPACE SDL_SCANCODE_SPACE
#define GAM_KEY_ENTER SDL_SCANCODE_RETURN
#define GAM_KEY_W SDL_SCANCODE_W
#define GAM_KEY_A SDL_SCANCODE_A
#define GAM_KEY_S SDL_SCANCODE_S
#define GAM_KEY_D SDL_SCANCODE_D
#define GAM_KEY_UP SDL_SCANCODE_UP
#define GAM_KEY_DOWN SDL_SCANCODE_DOWN
#define GAM_KEY_LEFT SDL_SCANCODE_LEFT
#define GAM_KEY_RIGHT SDL_SCANCODE_RIGHT

// Boutons souris
#define GAM_MOUSE_LEFT SDL_BUTTON_LEFT
#define GAM_MOUSE_RIGHT SDL_BUTTON_RIGHT
#define GAM_MOUSE_MIDDLE SDL_BUTTON_MIDDLE

#endif // GAM_DL_EVENTS_H

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
 * │  -> Nom      : GAM_DL_draw.h                                            │ *
 * │  -> Auteur   : tricaducee SpartaCod lolilol                             │ *
 * │  -> Date     : 01/06/2025                                               │ *
 * ╰─────────────────────────────────────────────────────────────────────────╯ *
 */

#ifndef GAM_DL_DRAW_H
#define GAM_DL_DRAW_H

#include "GAM_DL_core.h"

// ═══════════════════════════════════════════════════════════════════════════
// TYPES POUR LE DESSIN
// ═══════════════════════════════════════════════════════════════════════════

typedef struct
{
    float x, y;
} GAM_Point;

typedef struct
{
    float x, y, w, h;
} GAM_Rect;

typedef struct
{
    Uint8 r, g, b, a;
} GAM_Color;

// ═══════════════════════════════════════════════════════════════════════════
// VOS FONCTIONS EXISTANTES (à implémenter)
// ═══════════════════════════════════════════════════════════════════════════

// Espace réservé pour vos futures fonctions de dessin

// ═══════════════════════════════════════════════════════════════════════════
// COULEURS PRÉDÉFINIES UTILES
// ═══════════════════════════════════════════════════════════════════════════

// Macros pour couleurs courantes
#define GAM_COLOR_BLACK (GAM_Color){0, 0, 0, 255}
#define GAM_COLOR_WHITE (GAM_Color){255, 255, 255, 255}
#define GAM_COLOR_RED (GAM_Color){255, 0, 0, 255}
#define GAM_COLOR_GREEN (GAM_Color){0, 255, 0, 255}
#define GAM_COLOR_BLUE (GAM_Color){0, 0, 255, 255}
#define GAM_COLOR_YELLOW (GAM_Color){255, 255, 0, 255}
#define GAM_COLOR_MAGENTA (GAM_Color){255, 0, 255, 255}
#define GAM_COLOR_CYAN (GAM_Color){0, 255, 255, 255}
#define GAM_COLOR_TRANSPARENT (GAM_Color){0, 0, 0, 0}

#endif // GAM_DL_DRAW_H

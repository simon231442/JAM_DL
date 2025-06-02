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

/* ═══════════════════════════════════════════════════════════════════════
	 * CALCULS UTILES - FORMAT RGBA8888 (4 octets par pixel)
	 * ═══════════════════════════════════════════════════════════════════════
	 * 
	 * ORGANISATION MÉMOIRE PAR PIXEL:
	 * Pixel = [R][G][B][A] = 4 octets (32 bits)
	 *          0  1  2  3   (indices d'octets)
	 * 
	 * CALCULS FONDAMENTAUX:
	 * - Octets par pixel       = 4
	 * - Largeur ligne (pitch)  = width * 4
	 * - Taille texture totale  = width * height * 4
	 * - Adresse pixel (x,y)    = pixels + (y * pitch) + (x * 4)
	 * 
	 * EXEMPLES POUR 800x600:
	 * - 1 ligne    = 800 × 4 = 3,200 octets
	 * - Texture    = 800 × 600 × 4 = 1,920,000 octets (≈1.92 MB)
	 * 
	 * ACCÈS PIXEL INDIVIDUEL:
	 * Uint32* pixel_addr = (Uint32*)((Uint8*)pixels + y*pitch + x*4);
	 * ═══════════════════════════════════════════════════════════════════════ */

// ═══════════════════════════════════════════════════════════════════════════
// VOS FONCTIONS EXISTANTES
// ═══════════════════════════════════════════════════════════════════════════

// Fonctions que vous avez déjà implémentées
GAM_Window *GAM_DL_CoreWindowPop(int width, int height);
void GAM_DL_GAM_DL_CoreExit(GAM_Window *gam_window);
int GAM_DL_CoreMainWindowShow(void);

#endif // GAM_DL_CORE_H
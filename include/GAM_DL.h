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
 * │  -> Nom      : GAM_DL.h                                                 │ *
 * │  -> Auteur   : tricaducee SpartaCod lolilol                             │ *
 * │  -> Date     : 31/05/2025                                               │ *
 * ╰─────────────────────────────────────────────────────────────────────────╯ *
*/

#ifndef GAM_DL_H
#define GAM_DL_H

#include <SDL3/SDL.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct
{
	SDL_Window      *window;       // Fenêtre SDL (corrigé: était "widow")
	SDL_Renderer    *renderer;     // Renderer SDL
	SDL_Texture     *texture;      // Texture pour manipulation pixels

	// Informations sur l'image/pixels
	void            *pixels;       // Adresse des pixels
	int             width;         // Largeur de la fenêtre
	int             height;        // Hauteur de la fenêtre
	int             pitch;         // Largeur d'une ligne en octets

}	GAM_Window;

	
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

GAM_Window	*GAM_DL_CoreWindowPop(int width, int height);
void		GAM_DL_GAM_DL_CoreExit(GAM_Window *GAM_Window);
int			GAM_DL_EventHandle(SDL_Event *event);
#endif

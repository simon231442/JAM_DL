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
 * │  -> Nom      : GAM_DL_TextureLoad.c                                     │ *
 * │  -> Auteur   : lolilol                                                  │ *
 * │  -> Date     : 01/06/2025                                               │ *
 * ╰─────────────────────────────────────────────────────────────────────────╯ *
 */

#include "GAM_DL.h"

GAM_Image *GAM_DL_TextureLoad(GAM_Window *window, const char *filepath)
{
	GAM_Image *gam_image;
	SDL_Surface *surface;

	gam_image = malloc(sizeof(GAM_Image));
	if (!gam_image)
		return (SDL_Log("GAM_DL_TextureLoad: Memory allocation failed for GAM_Image"),
				NULL);
	surface = SDL_LoadBMP(filepath);
	if (!surface)
		return (free(gam_image), SDL_Log("GAM_DL_TextureLoad: Failed to load image from %s",
				filepath),
				NULL);
	gam_image->texture = SDL_CreateTextureFromSurface(window->renderer, surface);
	gam_image->width = surface->w;
	gam_image->height = surface->h;
	SDL_DestroySurface(surface);
	if (!gam_image->texture)
		return (free(gam_image),
				SDL_Log("GAM_DL_TextureLoad: Failed to create texture from surface"),
				NULL);
}

/* ═══════════════════════════════════════════════════════════════════════════
 * DÉFINITIONS DES STRUCTURES UTILISÉES :
 * ═══════════════════════════════════════════════════════════════════════════
 *
 * GAM_Image (définie dans GAM_DL_texture.h) :
 * typedef struct {
 *     SDL_Texture *texture;    // Texture SDL pour le rendu GPU
 *     int width;               // Largeur de l'image en pixels
 *     int height;              // Hauteur de l'image en pixels
 *     const char *filepath;    // Chemin du fichier source
 * } GAM_Image;
 *
 * SDL_Surface (structure SDL3 interne) :
 * typedef struct SDL_Surface {
 *     SDL_PixelFormat *format; // Format des pixels (RGBA, etc.)
 *     int w, h;               // Largeur et hauteur
 *     int pitch;              // Octets par ligne
 *     void *pixels;           // Données des pixels en RAM
 *     int refcount;           // Compteur de références
 *     // ... autres champs internes SDL
 * } SDL_Surface;
 *
 * DIFFÉRENCE SURFACE vs TEXTURE :
 * - SDL_Surface = Image en RAM (CPU), manipulation pixels possible
 * - SDL_Texture = Image en VRAM (GPU), optimisée pour le rendu rapide
 * ═══════════════════════════════════════════════════════════════════════════ */

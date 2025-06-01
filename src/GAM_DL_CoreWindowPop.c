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
 * │  -> Nom      : GAM_DL_CoreWindowPop.c                                   │ *
 * │  -> Auteur   : lolilol                                                  │ *
 * │  -> Date     : 31/05/2025                                               │ *
 * ╰─────────────────────────────────────────────────────────────────────────╯ *
 */

#include "GAM_DL.h"

/**
 * @brief Creates a new SDL window with OpenGL renderer and texture.
 * 
 * This function initializes a new SDL window with the specified width and height,
 * creates an OpenGL renderer, and a texture for pixel manipulation.
 * 
 * SDL_TEXTUREACCESS_TARGET if you want to use the texture as a render target,
 * SDL_TEXTUREACCESS_STREAMING if you want to update the texture pixels directly.
 * @param width The width of the window.
 * @param height The height of the window.
 * @return A pointer to the newly created GAM_Window structure, or NULL on failure.
 */

GAM_Window *GAM_DL_CoreWindowPop(int width, int height)
{
	GAM_Window	*GAM_Window;

	GAM_Window = malloc(sizeof(GAM_Window));
	if (!GAM_Window)
		return (SDL_Log("GAM_DL_CoreWindowPop: Memory allocation failed for GAM_Window"), NULL);
	
	GAM_Window->window = SDL_CreateWindow("GAM_DL Window",
										  width, height,
										  SDL_WINDOW_OPENGL);
	if (!GAM_Window->window)
		return (SDL_Log("GAM_DL_CoreWindowPop: Failed to create window"), NULL);
	GAM_Window->renderer = SDL_CreateRenderer(GAM_Window->window, "opengl");
	if (!GAM_Window->renderer)
		return (SDL_Log("GAM_DL_CoreWindowPop: Failed to create renderer"), NULL);
	GAM_Window->texture = SDL_CreateTexture(GAM_Window->renderer,
											SDL_PIXELFORMAT_RGBA8888,
											SDL_TEXTUREACCESS_STREAMING,
											width, height);
	if (!GAM_Window->texture)
		return (SDL_Log("GAM_DL_CoreWindowPop: Failed to create texture"), NULL);
	GAM_Window->pixels = NULL;
	GAM_Window->width = width;
	GAM_Window->height = height;
	return (GAM_Window);
}

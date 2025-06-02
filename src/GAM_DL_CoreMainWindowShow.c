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
 * │  -> Nom      : GAM_DL_CoreMainWindowShow.c                              │ *
 * │  -> Auteur   : lolilol                                                  │ *
 * │  -> Date     : 31/05/2025                                               │ *
 * ╰─────────────────────────────────────────────────────────────────────────╯ *
 */

#include "GAM_DL.h"

int GAM_DL_CoreMainWindowShow(void)
{
	GAM_Window	*gam_window;
	GAM_Image	*gam_image;
	SDL_Event	event;

	gam_window = GAM_DL_CoreWindowPop(WIDTH, HEIGHT);
	if (!gam_window)
		return (GAM_DL_CoreExit(gam_window), 1);
	gam_image = GAM_DL_Texture_load();
	if (!gam_image)
		return (GAM_DL_CoreExit(gam_window), 1);
	while (1)
	{
		// Gestion des événements - Vider complètement la queue
		while (SDL_PollEvent(&event))
		{
			if (GAM_DL_EventHandle(&event))
				return (GAM_DL_CoreExit(gam_window), 0);
		}

		// TODO: Ajouter la logique du jeu ici

		// TODO: Ajouter le rendu ici
		SDL_Delay(16); // ~60 FPS temporaire
	}

	// Nettoyage avant fermeture
	GAM_DL_CoreExit(gam_window);
	return (0);
}

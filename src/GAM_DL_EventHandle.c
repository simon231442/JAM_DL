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
 * │  -> Nom      : GAM_DL_EventHandle.c                                     │ *
 * │  -> Auteur   : lolilol                                                  │ *
 * │  -> Date     : 01/06/2025                                               │ *
 * ╰─────────────────────────────────────────────────────────────────────────╯ *
 */

#include "GAM_DL.h"

int GAM_DL_EventHandle(SDL_Event *event)
{
	switch (event->type)
	{
	case SDL_EVENT_QUIT: // Utilisateur clique sur la croix (X) de la fenêtre
		return (SDL_Log("GAM_DL: Fermeture demandée via croix de fenêtre"), 1);

	case SDL_EVENT_KEY_DOWN: // Gestion des touches pressées
		switch (event->key.key)
		{
		case SDLK_ESCAPE: // Touche Échap pressée
			return (SDL_Log("GAM_DL: Fermeture demandée via touche Échap"), 1);
		// Signal pour fermer l'application

		default: // Autres touches (pour extension future)
			break;
		}
		break;

	default: // Autres événements non gérés
		break;
	}

	return 0; // Continue l'exécution
}

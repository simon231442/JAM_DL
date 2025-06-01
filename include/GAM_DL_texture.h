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
 * │  -> Nom      : GAM_DL_texture.h                                         │ *
 * │  -> Auteur   : tricaducee SpartaCod lolilol                             │ *
 * │  -> Date     : 01/06/2025                                               │ *
 * ╰─────────────────────────────────────────────────────────────────────────╯ *
 */

#ifndef GAM_DL_TEXTURE_H
#define GAM_DL_TEXTURE_H

#include "GAM_DL_core.h"

// ═══════════════════════════════════════════════════════════════════════════
// STRUCTURES POUR LES TEXTURES ET IMAGES
// ═══════════════════════════════════════════════════════════════════════════

typedef struct
{
    SDL_Texture *texture; // Texture SDL
    int width;            // Largeur de l'image
    int height;           // Hauteur de l'image
    const char *filepath; // Chemin du fichier (optionnel)
} GAM_Image;

/* EXEMPLE D'UTILISATION GAM_Image :
 *
 * // Charger une image
 * GAM_Image player_image = {
 *     .texture = NULL,
 *     .width = 0,
 *     .height = 0,
 *     .filepath = "assets/player.png"
 * };
 *
 * // Après chargement, les valeurs seraient :
 * // player_image.texture = (pointeur vers texture SDL)
 * // player_image.width = 64;    // largeur réelle de l'image
 * // player_image.height = 32;   // hauteur réelle de l'image
 *
 * // Utilisation pour le rendu :
 * SDL_FRect dest = {x, y, player_image.width, player_image.height};
 * SDL_RenderTexture(renderer, player_image.texture, NULL, &dest);
 */

typedef struct
{
    GAM_Image *image;   // Image source
    SDL_FRect src_rect; // Rectangle source dans l'image
    int frame_count;    // Nombre de frames
    int current_frame;  // Frame actuelle
    float frame_time;   // Temps par frame (en secondes)
    float timer;        // Timer interne
} GAM_Sprite;

/* EXEMPLE D'UTILISATION GAM_Sprite :
 *
 * // Sprite d'animation (spritesheet horizontale 4 frames de 32x32)
 * GAM_Sprite player_walk = {
 *     .image = &player_image,           // Image chargée précédemment
 *     .src_rect = {0, 0, 32, 32},      // Frame 0 : x=0, y=0, w=32, h=32
 *     .frame_count = 4,                 // 4 frames d'animation
 *     .current_frame = 0,               // Commence à la frame 0
 *     .frame_time = 0.2f,              // 200ms par frame = 5 FPS
 *     .timer = 0.0f                     // Timer interne à 0
 * };
 *
 * // Animation dans la boucle de jeu :
 * // player_walk.timer += delta_time;
 * // if (player_walk.timer >= player_walk.frame_time) {
 * //     player_walk.current_frame = (player_walk.current_frame + 1) % player_walk.frame_count;
 * //     player_walk.src_rect.x = player_walk.current_frame * 32; // 32 = largeur frame
 * //     player_walk.timer = 0.0f;
 * // }
 *
 * // Rendu du sprite animé :
 * SDL_FRect dest = {player_x, player_y, 32, 32};
 * SDL_RenderTexture(renderer, player_walk.image->texture, &player_walk.src_rect, &dest);
 */

// ═══════════════════════════════════════════════════════════════════════════
// VOS FONCTIONS EXISTANTES
// ═══════════════════════════════════════════════════════════════════════════

// Fonction que vous avez déjà implémentée
void GAM_DL_TextureLoad(void);

#endif // GAM_DL_TEXTURE_H

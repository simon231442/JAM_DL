/*
 * ╔══════════════════════════════════════════════════════════════════════════════╗
 * ║                           🚀 GAM_DL GENERATOR 🚀                             ║
 * ║                    Générateur de fichiers C GAM_DL                           ║
 * ╠══════════════════════════════════════════════════════════════════════════════╣
 * ║ Auteur     : GAM_DL Team                                                     ║
 * ║ Date       : Mai 2025                                                        ║
 * ║ Version    : 1.0                                                             ║
 * ║ Description: Générateur simple avec paramètres en ligne de commande          ║
 * ╚══════════════════════════════════════════════════════════════════════════════╝
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Fonction pour obtenir la date actuelle
void getCurrentDate(char* buffer)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(buffer, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

// Génère l'en-tête GAM_DL
void generateGamDLHeader(FILE* file, const char* filename, const char* author)
{
    char date[32];
    getCurrentDate(date);
    
    fprintf(file, "/*                                                                             *\n");
    fprintf(file, " *                ██████╗  █████╗ ███╗   ███╗     ██████╗ ██╗                  *\n");
    fprintf(file, " *                ██╔════╝ ██╔══██╗████╗ ████║     ██╔══██╗██║                 *\n");
    fprintf(file, " *                ██║  ███╗███████║██╔████╔██║     ██║  ██║██║                 *\n");
    fprintf(file, " *                ██║   ██║██╔══██║██║╚██╔╝██║     ██║  ██║██║                 *\n");
    fprintf(file, " *                ╚██████╔╝██║  ██║██║ ╚═╝ ██║     ██████╔╝███████╗            *\n");
    fprintf(file, " *                 ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝     ╚═════╝ ╚══════╝            *\n");
    fprintf(file, " *                                                                             *\n");
    fprintf(file, " * ╭─────────────────────────────────────────────────────────────────────────╮ *\n");
    fprintf(file, " * │  ** LEGENDARY ULTRA-MEGA AWESOME LIBRARY SDL3 C FOR RENDERS, MUSICS **  │ *\n");
    fprintf(file, " * ├─────────────────────────────────────────────────────────────────────────┤ *\n");
    fprintf(file, " * │  -> Nom      : %-56s │ *\n", filename);
    fprintf(file, " * │  -> Auteur   : %-56s │ *\n", author);
    fprintf(file, " * │  -> Date     : %-56s │ *\n", date);
    fprintf(file, " * ╰─────────────────────────────────────────────────────────────────────────╯ *\n");
    fprintf(file, " */\n\n");
}

// Ajoute le code de base avec la fonction personnalisée
void addBasicCode(FILE* file, const char* function_name)
{
    fprintf(file, "#include \"GAM_DL.h\"\n\n");
    
    // Fonction personnalisée
    int length = strlen(function_name);
    fprintf(file, "void GAM_DL_%.*s()\n{\n}\n", length - 2, function_name);
}

void printUsage(const char* program_name) {
    printf("╔═══════════════════════════════════════════════╗\n");
    printf("║           🎯 GAM_DL GENERATOR 🎯              ║\n");
    printf("╠═══════════════════════════════════════════════╣\n");
    printf("║ Usage:                                        ║\n");
    printf("║   %s <auteur> <fichier.c>                     ║\n", program_name);
    printf("║                                               ║\n");
    printf("║ Exemple:                                      ║\n");
    printf("║   %s \"John Doe\" \"init_game.c\"             ║\n", program_name);
    printf("║                                               ║\n");
    printf("║ Génère: GAM_DL_init_game.c avec en-tête       ║\n");
    printf("╚═══════════════════════════════════════════════╝\n");
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printUsage(argv[0]);
        return 1;
    }
    
    const char* author = argv[1];
    const char* file_name = argv[2];
    
    // Génère le nom du fichier avec préfixe GAM_DL_
    char filename[256];
    snprintf(filename, sizeof(filename), "GAM_DL_%s", file_name);
    
    // Crée le fichier
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("❌ Erreur: Impossible de créer le fichier '%s'\n", filename);
        return 1;
    }
    
    // Génère le contenu
    generateGamDLHeader(file, filename, author);
    addBasicCode(file, file_name);
    
    fclose(file);
    
    printf("✅ Fichier '%s' créé avec succès!\n", filename);
    printf("🎉 Auteur: %s | Fonction: %s() 🚀\n", author, file_name);
    
    return 0;
}

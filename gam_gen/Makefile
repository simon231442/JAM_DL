# Makefile pour le générateur de fichiers C GAM_DL
# Auteur: GAM_DL Team
# Date: Mai 2025

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = gam_gen
SOURCE = gam_gen.c
OLD_TARGET = file_generator

# Couleurs pour les messages
GREEN = \033[0;32m
CYAN = \033[0;36m
YELLOW = \033[1;33m
RED = \033[0;31m
NC = \033[0m # No Color

.PHONY: all clean test help

all: $(TARGET)
	@echo "$(GREEN)✅ Compilation terminée avec succès!$(NC)"
	@echo "$(CYAN)📋 Usage: './$(TARGET) <auteur> <fichier.c>'$(NC)"
	@echo "$(YELLOW)📋 Exemple: './$(TARGET) \"John Doe\" \"init_game.c\"'$(NC)"

$(TARGET): $(SOURCE)
	@echo "$(YELLOW)🔨 Compilation en cours...$(NC)"
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

clean:
	@echo "$(YELLOW)🧹 Nettoyage des fichiers compilés...$(NC)"
	rm -f $(TARGET) $(OLD_TARGET)
	@echo "$(GREEN)✅ Nettoyage terminé!$(NC)"

test: $(TARGET)
	@echo "$(CYAN)🧪 Test du générateur GAM_DL...$(NC)"
	./$(TARGET) "Test User" "test_function.c"

help:
	@echo "$(CYAN)📖 Aide - Générateur GAM_DL$(NC)"
	@echo "$(YELLOW)Commandes disponibles:$(NC)"
	@echo "  make        - Compile le générateur"
	@echo "  make test   - Compile et teste le générateur"
	@echo "  make clean  - Supprime les fichiers compilés"
	@echo "  make help   - Affiche cette aide"
	@echo ""
	@echo "$(GREEN)Utilisation:$(NC)"
	@echo "  1. make"
	@echo "  2. ./gam_gen \"Votre Nom\" \"nom_fichier.c\""
	@echo ""
	@echo "$(CYAN)Le générateur créera un fichier C avec l'en-tête GAM_DL!$(NC)"

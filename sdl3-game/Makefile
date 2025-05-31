CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -g
LDFLAGS = -lSDL3

SRC = src/main.c src/window.c src/graphics.c src/game.c
OBJ = $(SRC:.c=.o)
TARGET = sdl3-game

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
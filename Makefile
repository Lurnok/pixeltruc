ALL_SRCS = $(wildcard src/structs/*/*.c) $(wildcard src/functions/*/*.c)

SRCS_TEST = $(filter %_test.c, $(ALL_SRCS))
COMMON_SRCS = $(filter-out %_test.c, $(ALL_SRCS))

COMMON_OBJS = $(COMMON_SRCS:.c=.o)
OBJS_TEST = $(SRCS_TEST:.c=.o)
TEST_BINS = $(SRCS_TEST:.c=)

MAIN_SRC = src/main.c
MAIN_OBJ = $(MAIN_SRC:.c=.o)

CC = clang
CFLAGS = -std=c99 -Wall -Wextra -pedantic -g -fsanitize=address -Isrc
LDFLAGS = -fsanitize=address

CFLAGS += $(shell pkg-config --cflags sdl2 SDL2_image SDL2_ttf)
LDFLAGS += $(shell pkg-config --libs sdl2 SDL2_image SDL2_ttf)

TARGET = pixeltruc
TARGET_TEST = test

all: $(TARGET)

$(TARGET): $(MAIN_OBJ) $(COMMON_OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_BINS): %: %.o $(COMMON_OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

test: $(TEST_BINS)
	@for test in $(TEST_BINS); do \
		echo "Running test: $$(basename $$test)"; \
		./$$test; \
	done

clean:
	rm -f $(TARGET) $(MAIN_OBJ) $(COMMON_OBJS) $(OBJS_TEST) $(TEST_BINS)


req:
	@echo "Détection de l'OS et installation des dépendances..."
	@if [ -f /etc/debian_version ]; then \
		echo "Système basé sur Debian/Ubuntu détecté (apt)"; \
		sudo apt update && sudo apt install -y \
			libsdl2-dev \
			libsdl2-image-dev \
			libsdl2-ttf-dev \
			pkg-config; \
	elif [ -f /etc/arch-release ]; then \
		echo "Système basé sur Arch Linux détecté (pacman)"; \
		sudo pacman -Syu --needed --noconfirm \
			sdl2 \
			sdl2_image \
			sdl2_ttf \
			pkgconf; \
	else \
		echo "OS non supporté automatiquement. Veuillez installer SDL2, SDL2_image, SDL2_ttf et ncurses manuellement."; \
		exit 1; \
	fi
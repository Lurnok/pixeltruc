ALL_SRCS = $(wildcard src/structs/*/*.c) $(wildcard src/functions/*/*.c) $(wildcard src/functions/*/*/*.c)

SRCS_TEST = $(filter %_test.c, $(ALL_SRCS))
COMMON_SRCS = $(filter-out %_test.c, $(ALL_SRCS))

COMMON_OBJS = $(COMMON_SRCS:.c=.o)
OBJS_TEST = $(SRCS_TEST:.c=.o)
TEST_BINS = $(SRCS_TEST:.c=)

MAIN_SRC = src/main.c
MAIN_OBJ = $(MAIN_SRC:.c=.o)

SUBMODULES_DIR = external

NUKLEAR_DIR = $(SUBMODULES_DIR)/Nuklear
NUKLEAR_SDL2_DIR = $(NUKLEAR_DIR)/demo/sdl_renderer
NUKLEAR_HEADER = $(NUKLEAR_DIR)/nuklear.h
NUKLEAR_SDL2_HEADER = $(NUKLEAR_SDL2_DIR)/nuklear_sdl_renderer.h

CC = clang
CFLAGS = -std=c99 -Wall -Wextra -pedantic -g -fsanitize=address -Isrc
LDFLAGS = -fsanitize=address

CFLAGS += $(shell pkg-config --cflags sdl2 SDL2_image SDL2_ttf)
LDFLAGS += $(shell pkg-config --libs sdl2 SDL2_image SDL2_ttf)

# --- Nuklear libraries ---
CFLAGS += -I$(NUKLEAR_DIR)
CFLAGS += -I$(NUKLEAR_SDL2_DIR)


TARGET = pixeltruc
TARGET_TEST = test

all: $(TARGET)

$(TARGET): $(MAIN_OBJ) $(COMMON_OBJS) $(NUKLEAR_HEADER)
	$(CC) $(LDFLAGS) $(filter %.o, $^) -o $@

%.o: %.c $(NUKLEAR_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_BINS): %: %.o $(COMMON_OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

test: $(TEST_BINS)
	@for test in $(TEST_BINS); do \
		echo "Running test: $$(basename $$test)"; \
		./$$test; \
	done

run: $(TARGET)
	LSAN_OPTIONS=suppressions=asan.supp ./pixeltruc

clean:
	rm -f $(TARGET) $(MAIN_OBJ) $(COMMON_OBJS) $(OBJS_TEST) $(TEST_BINS)

$(NUKLEAR_HEADER):
	@echo "=> Initializing Nuklear submodule..."
	git submodule update --init external/Nuklear

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
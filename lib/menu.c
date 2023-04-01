#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

#include "menu.h"
#include "banner.h"
#include "../game/game.h"

void print_options(int *selected_option) {
    char *options[4] = {
        "Start Game",
        "How to play",
        "Scoreboard",
        "Quit"
    };

    for (int i = 0; i < 4; i++) {
        if (i == *selected_option) {
            printf("-> %s\n", options[i]);
        } else {
            printf("   %s\n", options[i]);
        }
    }
}

void select_previous(int *option) {
    if (*option == 0) {
        *option = 3;
    } else {
        *option -= 1;
    }
}

void select_next(int *option) {
    if (*option == 3) {
        *option = 0;
    } else {
        *option += 1;
    }
}

/**
 * Selects an option where:
 *
 * 0 -> play
 * 1 -> how to play
 * 2 -> scoreboard
 * 3 -> exit
 */
void select_option(int *option_ptr) {
    if (*option_ptr < 0 || *option_ptr > 3) {
        fprintf(stderr, "invalid option provided, this error shouldn't happen.\n");
        exit(1);
    }

    switch (*option_ptr) {
        case 0:
            play();
            break;
        case 1:
            fprintf(stderr, "how to play\n");
            break;
        case 2:
            fprintf(stderr, "scoreboard\n");
            break;
        case 3:
            break;
    }
}

void print_menu() {
    int option = 0;
    int *option_ptr = &option;

    display_banner();
    print_options(option_ptr);

    // set terminal to raw mode
    struct termios orig_termios;
    tcgetattr(STDIN_FILENO, &orig_termios);
    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);

    int c;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            select_option(option_ptr);
            break;
        }

        if (c == '\033') { // arrow keys escape sequence
            getchar(); // discards the [
            switch (getchar()) {
                case 'A': // up
                    select_previous(option_ptr);
                    display_banner();
                    print_options(option_ptr);
                    break;
                case 'B': // down
                    select_next(option_ptr);
                    display_banner();
                    print_options(option_ptr);
                    break;
            }
        }
    }

    // restore terminal to original settings
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

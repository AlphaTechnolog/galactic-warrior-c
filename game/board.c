#include <stdio.h>
#include <stdlib.h>

#include "board.h"
#include "../lib/termutils.h"

char **create_board() {
    char **board = (char**) malloc(sizeof(char*) * BOARD_HEIGHT);

    for (int i = 0; i < BOARD_HEIGHT; i++) {
        board[i] = (char*) malloc(sizeof(char) * BOARD_WIDTH);
    }

    return board;
}

// by default the whole board will be a void space
void fill_board(char **board) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            board[i][j] = VOID;
        }
        board[i][BOARD_WIDTH - 1] = '\0';
    }
}

char **get_board() {
    char **board = create_board();
    fill_board(board);

    return board;
}

void display_board(char **board) {
    clear_screen();

    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            printf("%c", board[y][x]);
        }
        printf("\n");
    }
}

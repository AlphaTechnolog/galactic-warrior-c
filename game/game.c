#include <stdio.h>

#include "game.h"
#include "board.h"

void play() {
    char **board = get_board();
    display_board(board);
}

#include <stdio.h>

#include "game.h"
#include "player.h"
#include "board.h"

void play() {
    char **board = get_board();
    display_board(board);

    Player *player = create_player(board);
    display_player(player);
    initialize_user_thread(player);
}
